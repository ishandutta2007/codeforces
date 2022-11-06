#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

struct Node{
	ll el,er,cl,cr,res,eq;
	Node(ll x):el(x),er(x),cl(1),cr(1),res(1),eq(1){}
};

Node NEUT(-1);

ll cant(ll x){
	return x*(x-1)/2+x;
}

void print(Node a,string s){
	//return;
	cout<<s<<":\n";
	cout<<a.el<<" "<<a.er<<" "<<a.cl<<" "<<a.cr<<" "<<a.res<<" "<<a.eq<<"\n";
}

Node oper(Node a, Node b){
	if(a.el==-1)return b;
	if(b.el==-1)return a;
	Node res(0);
	res.el=a.el;
	res.er=b.er;
	if(a.er>b.el){
		res.cl=a.cl;
		res.cr=b.cr;
		res.res=a.res+b.res;
		res.eq=0;
	}else{
		res.cl=a.cl+(a.eq?b.cl:0);
		res.cr=b.cr+(b.eq?a.cr:0);
		res.res=a.res+b.res-cant(a.cr)-cant(b.cl)+cant(a.cr+b.cl);
		res.eq=(a.eq&&b.eq);
	}
	//print(a,"a");
	//print(b,"b");
	//print(res,"res");
	return res;
}

struct STree { // segment tree for min over integers
	vector<Node> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void upd(int k, int s, int e, int p, Node v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	Node query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int p, Node v){upd(1,0,n,p,v);}
	Node query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

STree st(200005);

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)st.upd(i,Node(a[i]));
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll x,y; cin>>x>>y; x--;
			st.upd(x,Node(y));
		}else{
			ll l,r; cin>>l>>r; l--;
			cout<<st.query(l,r).res<<"\n";
		}
	}
	
	return 0;
}