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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();


const int mn=1e5+2;
const int mx=mn;
class UnionFind {
public:

int ufParent[mx];
int rank[mx];
void init(int n) {
  memset(rank,0,sizeof(int)*n);
  for (int x=0;x<n;x++) {
    ufParent[x]=x;
  }
}
int ffind(int x) {
  if (ufParent[x] != x) {
    ufParent[x] = ffind(ufParent[x]);
  }
  return ufParent[x];
}
void funion(int _x, int _y) {
  int xr = ffind(_x);
  int yr = ffind(_y);
  if (xr==yr) return;
  if (rank[xr] > rank[yr]) swap(xr,yr);
  if (rank[xr]==rank[yr]) rank[yr]++;
  ufParent[xr] = yr;
}
};


int vg[mn],vp[mn],vt[mn];
vector<int> g[2*mn];
UnionFind uf;
vector<int> h[mn];

bool cmp(const int &x, const int &y) {
  if (vg[x]==vg[y]) {
    if (vg[x]==1) {
      return vp[x]<vp[y];
    }
    else {
      return vp[x]>vp[y];
    }
  }
  return vg[x]>vg[y];
}
bool cmp2(const int &x, const int &y) {
  if (vg[x]==vg[y]) {
    if (vg[x]==1) {
      return vp[x]<vp[y];
    }
    else {
      return vp[x]>vp[y];
    }
  }
  return vg[x]<vg[y];
}
int vansx[mn],vansy[mn];
int wi,ht;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();wi=rint(),ht=rint();
  for (int i=0;i<n;i++) {
    int gg=rint(),p=rint(),t=rint();
    vg[i]=gg,vp[i]=p,vt[i]=i;
    
      int ident=t-p;
      g[ident+mn].PB(i);
      //printf("ident:%d\n",ident);
    
  }
  uf.init(n);
  for (int ident=0;ident<2*mn;ident++) {
    int sz=g[ident].size();
    for (int i=1;i<sz;i++) {
      int x=g[ident][i-1],y=g[ident][i];
      //printf("ident:%d x:%d y:%d\n",ident-mn,x,y);
      uf.funion(x,y);
    }
  }
  for (int x=0;x<n;x++) {
    int p=uf.ffind(x);
    h[p].PB(x);
  }
  for (int p=0;p<n;p++) {
    vector<int> vsrc=h[p];
    sort(vsrc.begin(),vsrc.end(),cmp);
    vector<int> vdest=h[p];
    sort(vdest.begin(),vdest.end(),cmp2);
    int hpsz=h[p].size();
    for (int i=0;i<hpsz;i++) {
      int srcid=vsrc[i];
      int destid=vdest[i];
      //printf("srcid:%d destid:%d p:%d\n",srcid,destid,p);
      int gg=vg[destid],pos=vp[destid];
      int destx=wi,desty=ht;
      if (gg==1) destx=pos;
      else desty=pos;
      vansx[srcid]=destx;
      vansy[srcid]=desty;
    }
    
  }
  for (int i=0;i<n;i++) {
    printf("%d %d\n",vansx[i],vansy[i]);
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