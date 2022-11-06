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

STree st(303);

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<pair<ll,ll>> a(m);
		fore(i,0,m)cin>>a[i].fst,a[i].snd=-i;
		fore(i,0,m)st.upd(i,0);
		sort(ALL(a));
		vector<ll> u(m);
		fore(i,0,m){
			u[-a[i].snd]=i;
		}
		ll res=0;
		fore(i,0,m){
			res+=st.query(0,u[i]);
			st.upd(u[i],1);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}