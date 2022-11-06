#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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

int readInt()
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
const int mn=5e5+4;
const int mv=1e6+2;
vector<int> val2i[mv];
int a[mn];
int vl[mn],vr[mn];
int n;
int tmin[2*mn];
int tmax[2*mn];
void modifymin(int l, int r, int value) {
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) chkmin(tmin[l++], value);
    if (r&1) chkmin(tmin[--r], value);
  }
}

int querymin(int p) {
  int res = INF;
  for (p += n; p > 0; p >>= 1) chkmin(res, tmin[p]);
  return res;
}
void modifymax(int l, int r, int value) {
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) chkmax(tmax[l++], value);
    if (r&1) chkmax(tmax[--r], value);
  }
}

int querymax(int p) {
  int res = -INF;
  for (p += n; p > 0; p >>= 1) chkmax(res, tmax[p]);
  return res;
}


ll final=0;
void addArc(int l, int r) {
  chkmax(vr[l],r);
  chkmin(vl[r],l);
  modifymin(l+1,r-1,r);
  modifymax(l+1,r-1,l);
  final+=min(a[l],a[r]);
  //dbg("l:%d r:%d a[l]:%d a[r]:%d vr[%d]=%d vl[%d]=%d\n",l,r,a[l],a[r],l,vr[l],r,vl[r]);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=readInt();
  for (int i=0;i<n;i++) {
    int x=readInt();
    a[i]=x;
    val2i[x].PB(i);
  }
  for (int i=0;i<n;i++) {vl[i]=INF; vr[i]=-INF;}
  for (int i=0;i<2*n;i++) {tmin[i]=n-1; tmax[i]=0;}
  set<int> s;
  s.insert(-1);
  s.insert(n);
  for (int v=mv-1;v>=0;v--) {
    for (auto &i:val2i[v]) {
      dbg("v:%d i:%d\n",v,i);
      auto rit=s.upper_bound(i);
      auto lit=rit; --lit;
      s.insert(i);
      int ri=*rit;
      if (0<=ri&&ri<n) {
        chkmin(vl[ri],i);
        chkmax(vr[i],ri);
      }
      int li=*lit;
      if (0<=li&&li<n) {
        chkmin(vl[i],li);
        chkmax(vr[li],i);
      }
      //printf("i:%d li:%d ri:%d\n",i,li,ri);
      int lo=querymax(i);
      int hi=querymin(i);
      for (int x=i;;) {
        if (abs(x-i)>1) {
          addArc(i,x);
        }
        int nx=vr[x];
        if (!(lo<=nx&&nx<=hi)) break;
        x=nx;
      }
      for (int x=i;;) {
        if (abs(x-i)>1) {
          addArc(x,i);
        }
        int nx=vl[x];
        if (!(lo<=nx&&nx<=hi)) break;
        x=nx;
      }
    }
  }
  printf("%lld\n",final);
}