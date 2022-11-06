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
const int mn=2e5+4;

typedef int S;
const int MAXSEG=mn;
const int segn=MAXSEG;
S t[2 * MAXSEG];
S identity = 0;
S combine(const S& lefts, const S& rights) {
  return lefts+rights;
}
//void build(S *t) {  // build the tree
//  int n=segn;
//  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
//}

void modify(int p, const S& value) { // set value at position p
  int n=segn;
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

S query(int l, int r) { // sum on interval [l, r]
  r++;
  int n=segn;
  S resl=identity, resr=identity;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}



int x2y[mn];
vector<int> vquery1ans;
vector<pair<int,pii> > vquery1[mn];
int gqid=0;
void fillgo(int n) {
  vquery1ans.resize(gqid);
  for (int x=0;x<mn;x++) {
    if (1<=x&&x<=n) {
      modify(x2y[x],1);
    }
    for (auto &w:vquery1[x]) {
      int id=w.fst,yl=w.snd.fst,yh=w.snd.snd;
      int ans=query(yl,yh);
      vquery1ans[id]=ans;
    }
  }
}

int query1(int x, int yl, int yh, bool sec) {
  if (!sec) {
    vquery1[x].PB(MP(gqid++, MP(yl,yh)));
    return 0;
  }
  else {
    return vquery1ans[gqid++];
  }
}
int query2(int xl, int xh, int yl, int yh, bool sec) {
  int A=query1(xl-1,yl,yh,sec);
  int B=query1(xh,yl,yh,sec);
  return B-A;
}
ll all;
int vl[mn],vd[mn],vr[mn],vu[mn];
void go(int qi, bool sec) {
  int px[4],py[4];
  int recdot[3][3];
  int xl=vl[qi],yl=vd[qi],xh=vr[qi],yh=vu[qi];
  px[0]=1;
  px[1]=xl;
  px[2]=xh+1;
  px[3]=mn-2;
  py[0]=1;
  py[1]=yl;
  py[2]=yh+1;
  py[3]=mn-2;
  for (int xi=0;xi<3;xi++) {
    for (int yi=0;yi<3;yi++) {
      if (xi==1&&yi==1) continue;
      recdot[xi][yi]=query2(
        px[xi],px[xi+1]-1,
        py[yi],py[yi+1]-1,sec);
      //if (sec) printf("xi:%d yi:%d. x:%d %d. y:%d %d. q:%d\n",
      //  xi,yi,
      //  px[xi],px[xi+1]-1,
      //  py[yi],py[yi+1]-1,
      //  recdot[xi][yi]);
    }
  }
  if (sec) {
    ll ans=all;
    for (int xi=0;xi<3;xi++) {
      for (int yi=0;yi<3;yi++) {
        if (xi==1&&yi==1) continue;
        int th=recdot[xi][yi];
        for (int oxi=xi;oxi<3;oxi++) {
          for (int oyi=yi;oyi<3;oyi++) {
            if (oxi==1&&oyi==1) continue;
            if ((xi==oxi)!=(yi==oyi)) {
              if (xi==1&&(yi!=oyi)) continue;
              if (yi==1&&(xi!=oxi)) continue;
              ans-=1ll*th*recdot[oxi][oyi];
            }
          }
        }
        ans-=(1ll*th*(th-1))/2;
      }
    }
    printf("%lld\n",ans);
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),qn=rint();
  all=(1ll*n*(n-1))/2;
  for (int x=1;x<=n;x++) x2y[x]=rint();
  for (int i=0;i<qn;i++) {
    vl[i]=rint();
    vd[i]=rint();
    vr[i]=rint();
    vu[i]=rint();
    go(i,false);
  }
  fillgo(n);
  gqid=0;
  for (int i=0;i<qn;i++) go(i,true);
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