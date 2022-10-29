#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
struct Edge{
  int u, v, id;
};

const int M=3e5, N=3e5;
int n, m, s;
char cs[2][M];
vector<Edge> g[N];
int ans[2];
bool vis[N];


void bfs(int b){
  memset(vis,0,sizeof(vis)); 
  queue<int> q; q.push(s);
  vis[s]=1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    for(Edge e : g[u]){
      if(e.id == -1 && !vis[e.v]){
        vis[e.v]=1;
        q.push(e.v); 
      }else if(e.id >= 0){
      	if(cs[b][e.id])continue;
        if(e.u == u){
          if(b==0 && !vis[e.v]){
            vis[e.v]=1; q.push(e.v); 
          }
          cs[b][e.id]=b==0?'+':'-';
        }else{
          if(b==0 && !vis[e.u]){
            vis[e.u]=1; q.push(e.u);
          }
          cs[b][e.id]=b==0?'-':'+';
        }
      }
    }
  }
  ans[b]=count(vis,vis+n,1);
}

int main(){
  cin >> n >> m >> s; s--;
  int id_cnt=0;
  fore(x,0,m){
    int t, u, v; cin >> t >> u >> v; u--; v--;
    if(t==1){
      g[u].pb(Edge{u,v,-1});
    }else{
      g[u].pb(Edge{u,v,id_cnt});
      g[v].pb(Edge{u,v,id_cnt});
      id_cnt++;
    }
  }
  fore(x,0,2){
    bfs(x);
    cout << ans[x] << "\n";
    fore(y,0,id_cnt){if(cs[x][y])cout<<cs[x][y];else cout<<'+';}cout<<"\n";
  }
}