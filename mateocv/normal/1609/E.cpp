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

/*----------------SEGMENT_TREE_ITERATIVO----------------*/
#define oper(a,b) a+b
#define NEUT 0
struct STree{
	vector<int> t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
	void upd(int p, int value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	int query(int l, int r){ // [l, r)
		int res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

ll INF=1e18;

struct node{
	ll c[3][3];
};

node NEUTp={{{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}}};

void print(node n, string s){
	cout<<s<<"\n";
	fore(i,0,3){
		fore(j,0,3){
			cout<<n.c[i][j]<<" ";
		}
		cout<<"\n";
	}
}

node unit(char c){
	node res;
	fore(i,0,3){
		fore(j,i,3){
			res.c[i][j]=0;
			ll vis[3]={0,0,0};
			fore(k,i,j+1)vis[k]++;
			if(c=='a'&&vis[0])res.c[i][j]=1;
			if(c=='b'&&vis[1])res.c[i][j]=1;
			if(c=='c'&&vis[2])res.c[i][j]=1;
		}
	}
	return res;
}

node operp(node a, node b){
	if(a.c[0][0]==-1)return b;
	if(b.c[0][0]==-1)return a;
	node res;
	fore(i,0,3){
		fore(j,i,3){
			res.c[i][j]=INF;
			fore(k,i,j+1)res.c[i][j]=min(res.c[i][j],a.c[i][k]+b.c[k][j]);
			fore(k,i,j)res.c[i][j]=min(res.c[i][j],a.c[i][k]+b.c[k+1][j]);
		}
	}
	/*
	print(a,"a");
	print(b,"b");
	print(res,"res");
	*/
	return res;
}

struct STreep { // segment tree for min over integers
	vector<node> st;int n;
	STreep(int n): st(4*n+5,NEUTp), n(n) {}
	void upd(int k, int s, int e, int p, node v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=operp(st[2*k],st[2*k+1]);
	}
	node query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUTp;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return operp(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int p, node v){upd(1,0,n,p,v);}
	node query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

STreep st(100005);

int main(){FIN;
	//print(unit('a'),"a");
	//print(unit('b'),"b");
	//print(unit('c'),"c");
	//return 0;
	ll n,q; cin>>n>>q;
	string s; cin>>s;
	STree ca(100005),cb(100005),cc(100005);
	fore(i,0,SZ(s)){
		if(s[i]=='a')ca.upd(i,1),st.upd(i,unit('a'));
		if(s[i]=='b')cb.upd(i,1),st.upd(i,unit('b'));
		if(s[i]=='c')cc.upd(i,1),st.upd(i,unit('c'));
	}
	while(q--){
		ll pos; cin>>pos; pos--;
		char c; cin>>c;
		if(c=='a')ca.upd(pos,1),st.upd(pos,unit('a'));
		if(c=='b')cb.upd(pos,1),st.upd(pos,unit('b'));
		if(c=='c')cc.upd(pos,1),st.upd(pos,unit('c'));
		auto qu=st.query(0,n);
		ll res=INF;
		fore(i,0,3){
			fore(j,i,3){
				res=min(res,qu.c[i][j]);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}