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

const int MAXN=505;

ll INF=1e18;

// g[i][j]: weight of edge (i, j) or INF if there's no edge
// g[i][i]=0
ll g[MAXN][MAXN];
ll gc[MAXN][MAXN];
int n;
void floyd(){ // O(n^3) . Replaces g with min distances
	fore(k,0,n)fore(i,0,n)if(g[i][k]<INF)fore(j,0,n)if(g[k][j]<INF)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		ll m; cin>>m;
		fore(i,0,n){
			fore(j,0,n){
				g[i][j]=(i!=j)*INF;
				gc[i][j]=(i!=j)*INF;
			}
		}
		vector<pair<ll,pair<ll,ll>>> ed;
		fore(i,0,m){
			ll x,y,w; cin>>x>>y>>w; x--; y--;
			ed.pb({w,{x,y}});
			g[x][y]=1;
			g[y][x]=1;
			gc[x][y]=min(gc[x][y],w);
			gc[y][x]=min(gc[y][x],w);
		}
		floyd();
		ll res=INF;
		for(auto i:ed){
			res=min(res,(g[0][i.snd.fst]+g[i.snd.snd][n-1]+1)*i.fst);
			res=min(res,(g[0][i.snd.snd]+g[i.snd.fst][n-1]+1)*i.fst);
		}
		fore(i,0,n){
			fore(j,0,n){
				if(i!=j&&gc[i][j]<INF){
					fore(k,0,n){
						res=min(res,(g[i][k]+1+g[k][0]+g[k][n-1]+1)*gc[i][j]);
					}
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}