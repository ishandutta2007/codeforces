#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <locale>
#include <list>
using namespace std;
#define FORN(i,m,n) for(int i=m; i<(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
#define p_b(x) push_back(x)
#define m_p(a,b) make_pair(a,b)
typedef long long ll;
typedef long double ld;
 
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
vector<vector<int> > edges;
bool vis[N];
ll B[N], ans = 0;
int n;
 
ll gcd(ll a, ll b){
  if(!a) return b;
  if(!b) return a;
  return gcd(b,a%b);
}
 
void Solve(int u, map<ll,int> s){
  vis[u] = true;
  map<ll,int> tmp;
  for(auto i : s){
    ll cur = gcd(i.first,B[u]);
    ans = (ans + cur * i.second) % mod;
    tmp[cur] += i.second;
  }
  tmp[B[u]]++;
  ans = (ans + B[u]) % mod;
  FORN(i,0,edges[u].size()){
    if(!vis[edges[u][i]]) Solve(edges[u][i],tmp);
  }
}
 
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n;
  FORN(i,0,n) cin>>B[i];
  edges = vector<vector<int> > (n);
  FORN(i,1,n){
    int a,b; cin>>a>>b;
    a--, b--;
    edges[a].p_b(b);
    edges[b].p_b(a);
  }
  memset(vis,0,sizeof(vis));
  Solve(0,map<ll,int> ());
  cout<<ans<<endl;
}