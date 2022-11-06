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

const int MAXN=606;

ll n,m;

vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]
vector<pair<int,int> > ge[MAXN];
ll dist[MAXN];
ll vis[MAXN];
void dijkstra(int x){
	//cout<<x<<":"<<endl;
	memset(dist,-1,sizeof(dist));
	mset(vis,0);
	dist[x]=0;
	fore(_,0,n){
		//fore(i,0,n)cout<<vis[i]<<" ";
		//cout<<"\n";
		//fore(i,0,n)cout<<dist[i]<<" ";
		//cout<<endl;
		//x=q.top().snd;ll c=-q.top().fst;q.pop();
		pair<ll,ll> mini={1e18,-1};
		fore(i,0,n){
			if(!vis[i]&&dist[i]>=0)mini=min(mini,{dist[i],i});
		}
		assert(mini.snd>=0);
		x=mini.snd;
		ll c=mini.fst;
		vis[x]=1;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; ll c=g[x][i].snd;
			y=(y+dist[x])%n;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c;
			y=(y+1)%n; c++;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c;
		}
		if(c!=0){
			fore(i,0,ge[x].size()){
				int y=ge[x][i].fst; ll c=ge[x][i].snd;
				if(dist[y]<0||dist[x]+c<dist[y])
					dist[y]=dist[x]+c;
			}
		}
		
	}
}

int main(){FIN;
	cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w;
		g[u].pb({v,w});
	}
	fore(i,0,n){
		fore(j,1,n)ge[i].pb({(i+j)%n,j});
	}
	fore(i,0,n){
		dijkstra(i);
		fore(j,0,n)cout<<dist[j]<<" ";
		cout<<"\n";
	}
	
	return 0;
}