#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
const int mn=204;
char g[mn];
const ll LIM=(1e18) + 50;
ll f[2][mn];
ll compute(int n) {
  int cur=0,nxt=1;
  memset(f[cur],0,sizeof f[0]);
  f[cur][0]=1;
  int xlim=n;
  for (int i=0;i<n;i++) {
    memset(f[nxt],0,sizeof f[0]);
    char c=g[i];
    if (c=='?'||c=='(') for (int x=0;x<=xlim;x++) {
      ll now=f[cur][x]; if (now==0) continue;
      f[nxt][x+1]+=now;
      chkmin(f[nxt][x+1],LIM);
    }
    if (c=='?'||c==')') for (int x=1;x<=xlim;x++) {
      ll now=f[cur][x]; if (now==0) continue;
      f[nxt][x-1]+=now;
      chkmin(f[nxt][x-1],LIM);
    }
    swap(cur,nxt);
  }
  return f[cur][0];
}


int vp[mn][mn];
pii p[mn];

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m; ll k; cin>>n>>m>>k; --k;
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) cin>>vp[x][y];
  int slim=n+m-1;
  for (int s=0;s<slim;s++) {
    p[s].snd=s;
    p[s].fst=INT_MAX;
    for (int x=0;x<n;x++) {
      int y=s-x;
      if (0<=y&&y<m) {
        chkmin(p[s].fst,vp[x][y]);
      }
    }
  }
  sort(p,p+slim);
  memset(g,'?',sizeof g);
  //printf("slim:%d\n",slim);
  for (int i=0;i<slim;i++) {
    int pos=p[i].snd;
    g[pos]='(';
    ll got=compute(slim);
    //if (i<=5) printf("%d %d: %lld\n",i,pos,got);
    //printf("pos:%d k:%lld got:%lld\n",pos,k,got);
    if (k>=got) {
      g[pos]=')';
      k-=got;
    }
  }
  
  for (int x=0;x<n;x++) {for (int y=0;y<m;y++) {
    printf("%c",g[x+y]);
  }printf("\n");}
  
}