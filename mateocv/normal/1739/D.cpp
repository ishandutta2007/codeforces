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

#define oper max
#define NEUT {-1,-1}
struct STree{
	vector<pair<ll,ll>> t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
	void upd(int p, pair<ll,ll> value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	pair<ll,ll> query(int l, int r){ // [l, r)
		pair<ll,ll> res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

const int MAXN=200005;

ll n;

vector<ll> g[MAXN];

ll p[MAXN],d[MAXN],vis[MAXN];

vector<ll> v;

void dfs(ll x){
	v.pb(x);
	vis[x]=1;
	for(auto i:g[x]){
		if(vis[i])continue;
		d[i]=d[x]+1;
		dfs(i);
	}
}

ll solve(ll m){
	//cout<<m<<endl;
	fore(i,0,n)vis[i]=0;
	dfs(0);
	STree st(n);
	fore(i,0,n){
		st.upd(i,{d[i],i});
	}
	v.clear();
	fore(i,0,n)vis[i]=0;
	ll res=0;
	while(1){
		auto q=st.query(0,n);
		//cout<<q.fst<<" "<<q.snd<<"\n";
		if(q.fst<=m)break;
		ll va=q.snd;
		fore(_,0,m-1)va=p[va];
		res++;
		if(!vis[va])dfs(va);
		for(auto i:v){
			st.upd(i,NEUT);
		}
		v.clear();
	}
	//cout<<m<<" "<<res<<endl;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k; cin>>n>>k;
		fore(i,0,n)g[i].clear();
		p[0]=-1;
		fore(i,1,n){
			cin>>p[i]; p[i]--;
			g[p[i]].pb(i);
		}
		ll l=1,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			if(solve(m)<=k)r=m-1;
			else l=m+1;
		}
		cout<<l<<"\n";
	}
	
	return 0;
}