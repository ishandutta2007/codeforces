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

ll INF=1e18;

struct Node{
	ll s,maxi,mini;
	Node(ll a):s(a), maxi(a), mini(a) {}
	Node(ll a, ll b, ll c):s(a), maxi(b), mini(c) {}
};

Node NEUT(0,-INF,INF);

Node oper(Node a, Node b){
	return {a.s+b.s,max(a.maxi,a.s+b.maxi),min(a.mini,a.s+b.mini)};
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

STree st(100005);

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll> a(n);
	fore(i,0,n){
		ll x; cin>>x; a[i]+=x;
	}
	fore(i,0,n){
		ll x; cin>>x; a[i]-=x;
	}
	fore(i,0,n)st.upd(i,Node(a[i]));
	while(q--){
		ll l,r; cin>>l>>r; l--;
		auto q=st.query(l,r);
		if(q.maxi>0||q.s!=0)cout<<"-1\n";
		else cout<<-q.mini<<"\n";
	}
	
	return 0;
}