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

const int MAXN=2020;

ll a[MAXN][MAXN];

vector<ll> g[MAXN*MAXN+10];

vector<pair<ll,ll>> dir={{0,1},{1,0},{0,-1},{-1,0}};

bool val(ll x, ll y, ll n, ll m){
	return 0<=x&&x<n&&0<=y&&y<m;
}

ll vis[MAXN*MAXN+10];

ll d[MAXN*MAXN+10];

void bfs(ll v) {
	queue<int>q;
	vis[v]=1;
	q.push(v);
	while(q.size()) {
		int t=q.front(); q.pop();
		for(int i:g[t]) {
			if(!vis[i]) {
				vis[i]=1;
				d[i]=d[t]+1;
				q.push(i);
			}
		}
	}
}

ll INF=(1ll<<60);

int main(){FIN;
	ll n,m,w; cin>>n>>m>>w;
	fore(i,0,n){
		fore(j,0,m){
			cin>>a[i][j];
		}
	}
	fore(i,0,n){
		fore(j,0,m){
			if(a[i][j]==-1)continue;
			for(auto ii:dir){
				ll x=i+ii.fst,y=j+ii.snd;
				if(val(x,y,n,m)&&a[x][y]!=-1){
					g[MAXN*i+j].pb(MAXN*x+y);
				}
			}
		}
	}
	bfs(0);
	ll res=INF;
	if(vis[MAXN*(n-1)+m-1]){
		res=min(res,w*d[MAXN*(n-1)+m-1]);
	}
	ll c=INF;
	fore(i,0,n){
		fore(j,0,m){
			if(a[i][j]>0&&vis[MAXN*i+j]){
				c=min(c,w*d[MAXN*i+j]+a[i][j]);
			}
		}
	}
	mset(vis,0);
	mset(d,0);
	bfs(MAXN*(n-1)+m-1);
	fore(i,0,n){
		fore(j,0,m){
			if(a[i][j]>0&&vis[MAXN*i+j]){
				res=min(res,w*d[MAXN*i+j]+a[i][j]+c);
			}
		}
	}
	if(res==INF)cout<<"-1\n";
	else cout<<res<<"\n";
	
	return 0;
}