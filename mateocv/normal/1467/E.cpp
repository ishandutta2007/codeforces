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
ll a[MAXN],vis[MAXN];

vector<ll> ord;
ll ub[MAXN][2];

void dfs(ll v){
	if(vis[v])return;
	vis[v]=1;
	ord.pb(v);
	for(auto i:g[v])dfs(i);
	ord.pb(-v-1);
}

map<ll,ll> comp;
set<ll> stv;

vector<ll> gv[MAXN];

struct STree { // example: range sum with range addition
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=(e-s)*lazy[k]; // update st according to lazy
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
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

STree st(2*MAXN);

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	fore(i,0,SZ(ord)){
		if(ord[i]>=0)ub[ord[i]][0]=i;
		else ub[-ord[i]-1][1]=i;
	}
	//for(auto i:ord)cout<<i<<" "; cout<<"\n";
	fore(i,0,n)stv.insert(a[i]);
	ll va=0;
	for(auto i:stv)comp[i]=va++;
	fore(i,0,n)a[i]=comp[a[i]];
	fore(i,0,n)gv[a[i]].pb(i);
	ll tot=0;
	fore(i,0,n){
		//cout<<i<<":\n";
		if(SZ(gv[i])<=1)continue;
		for(auto j:gv[i])st.upd(ub[j][0],ub[j][0]+1,-st.query(ub[j][0],ub[j][0]+1));
		fore(j,0,SZ(gv[i])){
			//cout<<"Viendo "<<gv[i][j]<<"\n";
			ll ot=(j==0);
			for(auto ii:g[gv[i][j]]){
				if(ub[ii][0]>ub[gv[i][j]][0]){
					ll l=ub[ii][0],r=ub[ii][1];
					if(l<=ub[gv[i][ot]][0]&&ub[gv[i][ot]][0]<=r){
						//cout<<"Cae en el hijo "<<ii<<"\n";
						st.upd(l,r,1);
					}
				}else{
					ll l=ub[gv[i][j]][0],r=ub[gv[i][j]][1];
					if(ub[gv[i][ot]][0]<l||ub[gv[i][ot]][0]>r){
						//cout<<"Cae en el hijo "<<ii<<"\n";
						st.upd(0,l,1);
						st.upd(r+1,2*n,1);
					}
				}
			}
		}
		//fore(j,0,2*n)cout<<st.query(j,j+1)<<" "; cout<<"\n";
		for(auto j:gv[i]){
			if(st.query(ub[j][0],ub[j][0]+1)!=SZ(gv[i])-1){
				cout<<"0\n";
				return 0;
			}
		}
		tot+=SZ(gv[i]);
	}
	//cout<<"No corte\n";
	ll res=0;
	fore(i,0,n){
		if(SZ(gv[a[i]])==1&&st.query(ub[i][0],ub[i][0]+1)==tot)res++;
	}
	cout<<res<<"\n";
	
	return 0;
}