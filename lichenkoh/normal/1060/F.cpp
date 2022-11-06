#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
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
const ld EPS=1e-12;
int rint();char rch();long long rlong();
const int mn=52;
const int me=3*mn;
ld logfac[mn];
ld h[me][mn][mn];
ld hsum[me][mn][mn];
ld choose[mn][mn];
bitset<me> done;
vi g[mn];
pii ve[me];
int ev[mn][mn];
int vcount[mn][mn];

int counte(int p, int x) {
  if (vcount[p][x]!=-1) return vcount[p][x];
  int ans=0;
  for (auto &y:g[x]) if (y!=p) ans+=1+counte(x,y);
  return vcount[p][x]=ans;
}

void dfs(int par, int x) {
  int id=ev[par][x];
  if (done[id]) return;
  for (auto &y:g[x]) {if (y!=par) dfs(x,y);}
  ld f[2][mn][mn];
  memset(f[0],0,sizeof f[0]);
  f[0][0][0]=1;
  int A=0;
  int cur=0;
  for (auto &y:g[x]) {
    if (y==par) continue;
    int yid=ev[x][y];
    int nxt=cur^1;
    memset(f[nxt],0,sizeof f[nxt]);
    int C=counte(x,y);
    for (int B=0;B<=A+C+1;B++) {
      int S=A+C+1-B;
      //printf("A:%d C:%d B:%d S:%d\n",A,C,B,S);
      for (int E=0;E<=B;E++) {
        ld ans=0;
        for (int b=0;b<=min(B,C);b++) {
          int s=C-b;
          for (int e=0;e<=min(E,b);e++) {
            // Choose less than
            ans+=choose[S][s+1]*choose[B][b]*(s+1)*h[yid][b][e]*f[cur][B-b][E-e];
            //printf("S:%d s:%d B:%d b:%d E:%d e:%d h:%f f:%f\n",S,s,B,b,E,e,h[yid][b][e],f[cur][B-b][E-e]);
            // Choose greater than
            if (B-b-1>=0&&E-e-1>=0) {
              ans+=choose[S][s]*choose[B][b+1]*hsum[yid][b][e]*f[cur][B-b-1][E-e-1];
              //if (E==2) printf("b:%d e:%d hsum[%d][%d][%d]: %f  f[%d][%d][%d]: %f\n",b,e,yid,b,e,hsum[yid][b][e],cur,B-b-1,E-e-1,f[cur][B-b-1][E-e-1]);
            }
          }
        }
        //if(ans) printf("B:%d E:%d %f\n",B,E,ans);
        f[nxt][B][E]=ans;
      }
    }
    A+=C+1; cur^=1;
  }
  memcpy(h[id],f[cur],sizeof f[cur]);
  memcpy(hsum[id][0],h[id][0], sizeof h[id][0]);
  for (int b=1;b<=A;b++) {
    for (int e=0;e<=b;e++) hsum[id][b][e]=hsum[id][b-1][e]+h[id][b][e];
  }
  /*for (int b=0;b<=A;b++) {
    for (int e=0;e<=b;e++) {
      if (h[id][b][e]) printf("p:%d x:%d id:%d b:%d e:%d %f hsum:%f\n",par,x,id,b,e,h[id][b][e],hsum[id][b][e]);
    }
  }*/
  done[id]=true;
}
ld p2[2*mn];
int tid=0;
void ae(int x, int y) {
  ve[tid]=MP(x,y); ev[x][y]=tid; tid++;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(vcount,-1,sizeof vcount);
  logfac[0]=0;
  for (int i=1;i<mn;i++) {logfac[i]=logfac[i-1]+log(i);}
  for (int x=0;x<mn;x++) for (int y=0;y<=x;y++) choose[x][y]=exp(logfac[x]-logfac[y]-logfac[x-y]);
  for (int i=0;i<2*mn;i++) p2[i]=pow((ld)0.5L,i);
  int n; cin>>n;
  for (int x=1;x<=n;x++) {ae(0,x);}
  for (int i=1;i<n;i++) {int x,y; cin>>x>>y;
    g[x].PB(y); ae(x,y);
    g[y].PB(x); ae(y,x);
  }
  for (int x=1;x<=n;x++) {
  	dfs(0,x);
  	ld num=0,den=0;
    int id=ev[0][x];
    for (int s=0;s<=n-1;s++) {
      num+=h[id][n-1][s]*p2[s];
      den+=h[id][n-1][s];
    }
    ld final=num/den;
  	printf("%.10f\n",final);
  }
}