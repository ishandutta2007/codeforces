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

const int MAXN=200005;

vector<ll> g[MAXN];

ll vis[MAXN],p[MAXN],d[MAXN];

vector<ll> ord;

void dfs(ll x){
	vis[x]=1;
	ord.pb(x);
	for(auto i:g[x]){
		if(!vis[i]){
			p[i]=x;
			d[i]=d[x]+1;
			dfs(i);
		}
	}
	ord.pb(-x-1);
}

ll ub[MAXN][2];

ll INF=2e9;

vector<pair<ll,ll>> ai;

struct STree { // example: range sum with range addition
	vector<pair<ll,ll>> st;
	vector<ll>lazy;int n;
	void init(int k, int s, int e){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=ai[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m);init(2*k+1,m,e);
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	STree(int n): st(4*n+5,{0,0}), lazy(4*n+5,0), n(n) {}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k].fst+=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	pair<ll,ll> query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return {-INF,-INF}; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return max(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void init(){init(1,0,n);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	pair<ll,ll> query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

STree st(2*MAXN);

ll solve(ll n, ll r, ll m){
	ll res=1e18;
	vector<ll> v={n/2,(n+1)/2,m};
	for(auto i:v){
		if(i<=m)res=min(res,(n-r-i)*(r-i));
	}
	//cout<<"solve "<<r<<" "<<m<<" -> "<<res<<"\n";
	return res;
}

void print(ll n){
	fore(i,0,n)cout<<st.query(i,i+1).fst<<" ";
	cout<<"\n";
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	fore(i,0,n-1){
		ll x,y; cin>>x>>y; x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0);
	fore(i,0,SZ(ord)){
		if(ord[i]>=0){
			ub[ord[i]][0]=i;
		}else{
			ub[-ord[i]-1][1]=i;
		}
	}
	ll res=solve(n,0,n);
	fore(i,0,st.n)ai.pb({0,i});
	st.init();
	fore(i,0,n){
		if(SZ(g[i])==1&&i!=0){
			st.upd(ub[i][0],ub[i][0]+1,d[i]+1);
		}else{
			st.upd(ub[i][0],ub[i][0]+1,-INF);
		}
		st.upd(ub[i][1],ub[i][1]+1,-INF);
	}
	vector<ll> oc(n);
	ll va=n;
	fore(i,0,k){
		//print(2*n);
		auto q=st.query(0,SZ(ord));
		if(q.fst>=0){
			va-=q.fst;
			ll pos=ord[q.snd];
			while(!oc[pos]){
				oc[pos]=1;
				st.upd(ub[pos][0],ub[pos][1],-1);
				if(pos==0)break;
				pos=p[pos];
			}
		}
		res=max(res,solve(n,i+1,va));
	}
	cout<<res<<"\n";
	
	return 0;
}