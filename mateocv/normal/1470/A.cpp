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

#define oper min
#define NEUT 9e18
struct STree{
	vector<ll> t; ll n;
	STree(ll n):n(n),t(2*n+5,NEUT){}
	void upd(ll p, ll value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(ll l, ll r){ // [l, r)
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

const int MAXN=300005;

STree st(MAXN);
ll a[MAXN],b[MAXN];
ll sump[MAXN];
ll sumpv[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n)cin>>a[i],a[i]--;
		sort(a,a+n);
		fore(i,0,m)cin>>b[i];
		fore(i,0,n)st.upd(i,a[i]-i);
		ll res=NEUT;
		sump[0]=0;
		fore(i,0,m)sump[i+1]=sump[i]+b[i];
		sumpv[0]=0;
		fore(i,0,n)sumpv[i+1]=sumpv[i]+b[a[i]];
		fore(i,0,n+1){
			if(st.query(i,n)+i>=0&&n-i<=m){
				res=min(res,sumpv[i]+sump[n-i]);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}