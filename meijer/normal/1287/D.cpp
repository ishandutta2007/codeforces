#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
 
const int MX=2500, MOD=1e9+7;
int n, p[MX], c[MX];
vi adj[MX];
int sz[MX];
int a[MX];
int cur = 0;
int root = 0;

int dfsSz(int u) {
  sz[u] = 1;
  for(int v:adj[u])
    sz[u] += dfsSz(v);
  return sz[u];
}
void addSub(int u, int min) {
  if(a[u] >= min) a[u]++;
  for(int v:adj[u])
    addSub(v, min);
}
void dfs(int u) {
  for(int v:adj[u]) {
    dfs(v);
    cur += sz[v];
  }
  cur -= sz[u] - 1;
  a[u] = cur + c[u] + 1;
  for(int v:adj[u])
    addSub(v, a[u]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  REP(i,1,n+1) cin>>p[i]>>c[i], adj[p[i]].pb(i);
  REP(i,1,n+1) if(p[i] == 0) root = i;
  dfsSz(root);
  bool pos = 1;
  REP(i,1,n+1) if(c[i] >= sz[i]) pos = 0;
  if(pos) {
    dfs(root);
    cout<<"YES"<<endl;
    REP(i,1,n+1) cout<<(i==1?"":" ")<<a[i];
    cout<<endl;
  } else {
    cout<<"NO"<<endl;
  }
}