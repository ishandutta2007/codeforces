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

const int MAXN=300005;

struct STree { // example: range sum with range addition
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,-1), n(n) {}
	void push(int k, int s, int e){
		if(lazy[k]==-1)return; // if neutral, nothing to do
		st[k]=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=lazy[k];
			lazy[2*k+1]=lazy[k];
		}
		lazy[k]=-1; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return -1; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return max(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

STree st(2*MAXN);

vector<ll> ga[MAXN],gb[MAXN];

vector<ll> ord;

ll u[MAXN][2];

void dfs(ll v){
	ord.pb(v);
	for(auto i:gb[v])dfs(i);
	ord.pb(-v-1);
}

ll res=0,va=0;

ll ob[MAXN];

void print(ll n){
	fore(i,0,n)cout<<st.query(i,i+1)<<" ";
	cout<<"\n";
}

void solve(ll v){
	//cout<<"sol "<<v<<"\n";
	//print(SZ(ord));
	auto q=st.query(u[v][0],u[v][0]+1);
	if(q!=0){
		q--;
		ob[v]=q;
		st.upd(u[q][0],u[q][1]+1,0);
		//print(SZ(ord));
		st.upd(u[v][0],u[v][1]+1,v+1);
		//print(SZ(ord));
		res=max(res,va);
	}else{
		st.upd(u[v][0],u[v][1]+1,v+1);
		//print(SZ(ord));
		va++;
		res=max(res,va);
	}
	for(auto i:ga[v])solve(i);
	st.upd(u[v][0],u[v][1]+1,0);
	//print(SZ(ord));
	va--;
	res=max(res,va);
	if(ob[v]!=-1){
		st.upd(u[ob[v]][0],u[ob[v]][1]+1,ob[v]+1);
		//print(SZ(ord));
		va++;
		res=max(res,va);
		ob[v]=-1;
	}
	//cout<<"-sol "<<v<<"\n";
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)ga[i].clear(),gb[i].clear();
		fore(i,1,n){
			ll p; cin>>p; p--;
			ga[p].pb(i);
		}
		fore(i,1,n){
			ll p; cin>>p; p--;
			gb[p].pb(i);
		}
		ord.clear();
		dfs(0);
		//for(auto i:ord)cout<<i<<" ";
		//cout<<"\n";
		fore(i,0,SZ(ord)){
			if(ord[i]>=0){
				u[ord[i]][0]=i;
			}else{
				u[-ord[i]-1][1]=i;
			}
		}
		//fore(i,0,n)cout<<u[i][0]<<" "<<u[i][1]<<"\n";
		st.upd(0,2*n,0);
		fore(i,0,n)ob[i]=-1;
		res=0,va=0;
		solve(0);
		cout<<res<<"\n";
	}
	
	return 0;
}