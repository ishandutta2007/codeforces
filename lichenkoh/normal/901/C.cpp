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
#else
//#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=300000+2;

//*/
////////////////////////////////////////////////////////////////////////////////
// Biconnected components & 2-edge connected components
////////////////////////////////////////////////////////////////////////////////
// Note that component excludes bridges
//*!
namespace n10 {
//*/
const int MAXN=mn;
typedef vector<pair<int,int> > vpii;
int cutvertex[MAXN],low[MAXN],number[MAXN],parent[MAXN],I;
vi a[MAXN]; // adjacency list
vpii bridge; vector<vpii> component; //biconn-cmps
stack<pii> s; stack<int> roots, verts;
bool inS[MAXN]; vvi tecomp;  //2-edge conn cmps
void biconnected(int u){
  low[u] = number[u] = ++I; int child = 0;
  roots.push(u); verts.push(u); inS[u] = true;
  for (auto i = 0u; i < a[u].size(); i++) {
    int v = a[u][i];
    if (!number[v]) {
      s.push(make_pair(u,v)); parent[v] = u, child++;
      biconnected(v); low[u] = min(low[u], low[v]);
      if(parent[u]!=-1 && low[v]>=number[u]) cutvertex[u] = 1;
      if(low[v]>number[u]) bridge.push_back(make_pair(u,v)), s.pop();
      else if(low[v]==number[u]) {
        component.resize(component.size()+1);
        while(s.top()!=make_pair(u,v) && s.top() != make_pair(v,u))
          component.back().push_back(s.top()), s.pop();
        component.back().push_back(make_pair(u,v)); s.pop(); } }
    else if(number[v]<number[u] && v!=parent[u]){
      low[u] = min(low[u], number[v]), s.push(make_pair(u,v));
      while (number[roots.top()] > number[v]) roots.pop(); } }
  if (u == roots.top()) { tecomp.push_back(vi());
    while (true) {
      int w = verts.top(); verts.pop(); inS[w] = false;
      tecomp.back().push_back(w); if (u == w) break; }
    roots.pop(); }
  if(parent[u]==-1 && child>=2) cutvertex[u]=1; }
void doit(int n) {
  I = 0; component.clear(),bridge.clear(),tecomp.clear();
  memset(number,0,sizeof(number));
  memset(cutvertex,0,sizeof(cutvertex));
  memset(parent,0,sizeof(parent));
  memset(inS,0,sizeof(inS));
  for(int i=0; i < n; i++) if(!number[i]) parent[i]=-1, biconnected(i); }
//*!
}
ll mul(int x, int y) {
  return x*(ll)y;
}
ll c2(int len) {
  return ((len+1)*(ll)len)>>1;
}
int vr[mn];
vector<pii> vs;
ll getsum(ll *prefixval, int l, int r) {
  return prefixval[r+1]-prefixval[l];
}
ll prefixval[mn], prefixprod[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int m=rint();
  for (int i=0;i<m;i++) {
    int x=rint()-1; int y=rint()-1;
    n10::a[x].PB(y);
    n10::a[y].PB(x);
  }
  n10::doit(n);
  memset(vr,-1,sizeof vr);
  for (auto &comp: n10::component) {
    int lo=INF,hi=-INF;
    for (auto &p:comp) {
      int x=p.fst,y=p.snd;
      //dbg("x:%d y:%d\n",x+1,y+1);
      chkmin(lo,min(x,y));
      chkmax(hi,max(x,y));
    }
    if (lo!=hi&&lo!=INF&&hi!=-INF) {
      dbg("lo:%d hi:%d\n",lo,hi);
      vr[lo]=hi;
    }
  }
  int minr=INF;
  for (int l=n-1;l>=0;l--) {
    int r=vr[l];
    if (r==-1) continue;
    if (r>=minr) {
      vr[l]=-1;
    }
    chkmin(minr,r);
  }
  int prevl=-1;
  for (int l=0;l<n;l++) {
    if (vr[l]!=-1) {
      int r=vr[l];
      int val=(l-prevl);
      ll prod=val*(ll)(n-r);
      int idx=vs.size();
      prefixval[idx+1]=val+prefixval[idx];
      prefixprod[idx+1]=prod+prefixprod[idx];
      vs.PB(MP(l,r));
      dbg("SEG idx:%d l:%d r:%d val:%lld prod:%lld\n",idx,l,r,val,prod);
      prevl=l;
    }
  }
  int qlim=rint();
  int ssz=vs.size();
  for (int qi=0;qi<qlim;qi++) {
    int QL=rint()-1,QR=rint()-1;
    int SL,SR;
    {
      int imin=0,imax=ssz;
      while(imin<imax) {
        int imid=(imin+imax)>>1;
        if (vs[imid].fst<QL) imin=imid+1;
        else imax=imid;
      }
      SL=imin;
    }
    {
      int imin=0,imax=ssz;
      while(imin<imax) {
        int imid=(imin+imax)>>1;
        if (vs[imid].snd<=QR) imin=imid+1;
        else imax=imid;
      }
      SR=imin-1;
    }
    ll ans=0;
    if (SL<=SR) {
      int lft=vs[SL].fst-QL+1;
      int rt=QR-vs[SL].snd+1;
      ll ans1=mul(lft,rt);
      ll ans2=getsum(prefixprod, SL+1,SR);
      ll ans3=-getsum(prefixval, SL+1,SR)*(n-1-QR);
      ans+=ans1+ans2+ans3;
      dbg("ans1:%lld ans2:%lld ans3:%lld\n",ans1,ans2,ans3);
    }
    ll final=c2(QR-QL+1)-ans;
    printf("%lld\n",final);
  }
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}