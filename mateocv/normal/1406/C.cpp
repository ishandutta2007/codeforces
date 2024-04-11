#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=100005;

vector<ll> g[100005];

ll vis[MAXN],s[MAXN],gc[MAXN];

ll n; 

void dfs(ll v){
	vis[v]=1;
	s[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			dfs(i);
			s[v]+=s[i];
			gc[v]=max(gc[v],s[i]);
		}
	}
	gc[v]=max(gc[v],n-s[v]);
}

/*---------------- Union Find (DSU) ------------------*/
int pa[MAXN],sz[MAXN];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0);
		//fore(i,0,n)cout<<s[i]<<" "; cout<<endl;
		//fore(i,0,n)cout<<gc[i]<<" "; cout<<endl;
		ll mini=n;
		fore(i,0,n){
			mini=min(mini,gc[i]);
		}
		vector<ll> v;
		fore(i,0,n){
			if(gc[i]==mini)v.pb(i);
		}
		assert(SZ(v)<=2);
		sort(ALL(v));
		if(SZ(v)==1){
			fore(k,0,2)cout<<1<<" "<<g[0][0]+1<<"\n";
		}else{
			assert(mini==n/2&&n%2==0);
			dsu_init(n);
			fore(i,0,n){
				for(auto j:g[i]){
					if(min(i,j)!=v[0]||max(i,j)!=v[1]){
						join(i,j);
						//cout<<"Unimos "<<i+1<<" "<<j+1<<endl;
					}
				}
			}
			ll br=0;
			fore(i,0,n){
				if(SZ(g[i])==1&&i!=v[0]&&find_pa(i)!=find_pa(v[1])){
					cout<<i+1<<" "<<g[i][0]+1<<"\n";
					cout<<i+1<<" "<<v[1]+1<<"\n";
					br++; break;
				}
			}
			assert(br);
		}
		fore(i,0,n)g[i].clear();
		fore(i,0,n)vis[i]=0,s[i]=0,gc[i]=0;
	}
	
	return 0;
}