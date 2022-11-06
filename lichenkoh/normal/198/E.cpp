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





const int MAXSZ=(512-64)*(1<<20);
char prealloc[MAXSZ];
int preidx=0;
void * operator new(size_t size) {
  int oldidx=preidx;
  //preidx+=(((int)size) + 7) & ~0x07;
  preidx+=size;
  return (void *)(&prealloc[oldidx]);
}
void free (void* ptr) {
  return;
}

const int MAXN=250000+2;

typedef vector<int> STF;
STF fent[MAXN];
int fens[MAXN];
// T[i] += value
void fenwick_add(int i, int value) {
  for (; i < MAXN; i |= i + 1)
    fent[i].PB(value);
}
int hwr[MAXN];
bool cmp(const int x, const int y) {
  return hwr[x]<hwr[y];
}
bool vseen[MAXN];
// sum[0..i]
int fenwick_query(int i, int hr) {
  int oi=i;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    int sz=fent[i].size();
    for (;fens[i]<sz;fens[i]++) {
      int cand=fent[i][fens[i]];
      if (!vseen[cand]) {
        if (hwr[cand]<=hr) {
          //printf("oi:%d i:%d hwr:%d hr:%d cand:%d\n",oi,i,hwr[cand],hr,cand);
          return cand;
        }
        else break;
      }
    }
  }
  return 0;
}


const int MAXX=1e9+4;
int fsq(ll targ) {
  ll xc=sqrt(targ);
  if (xc>=MAXX) return MAXX;
  int xcc=xc;
  for (int x=max(0,xcc-1);;x++) {
    if (x*(ll)x >= targ) return x;
  }
}
const int mn=MAXN;
int hwp[mn];
vector<int> vh[mn];

void makeunique(vector<int> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
int bins(vector<int> &vx, int x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}

int vp[mn];

int vwp[mn]; int vwr[mn];
int vr[MAXN];
vector<int> bp,br;
bool vbad[mn];
vector<pair<pii, int> > vv;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int sx=rint(),sy=rint(); vp[0]=rint(),vr[0]=rint(); int n=rint();
  queue<int> q;
  for (int i=1;i<=n;i++) {
    int x=rint(),y=rint();
    int dx=(x-sx),dy=y-sy;
    ll dist2=dx*(ll)dx + dy*(ll)dy;
    vwr[i]=fsq(dist2);
    vwp[i]=rint();
    vp[i]=rint(),vr[i]=rint();
    if (vwr[i]>=MAXX) {
      vbad[i]=true;
    }
  }
  bp.reserve(n+2);
  bp.PB(MAXX);
  for (int i=0;i<=n;i++) {
    bp.PB(vp[i]);// bp.PB(vwp[i]);
  }
  makeunique(bp);
  for (int i=0;i<=n;i++) {
    vp[i]=bins(bp,vp[i]);
    vwp[i]=bins(bp,vwp[i]);
  }
  br.reserve(n+2);
  for (int i=0;i<=n;i++) {
    br.PB(vr[i]);// br.PB(vwr[i]);
  }
  br.PB(MAXX);
  makeunique(br);
  for (int i=0;i<=n;i++) {
    vr[i]=bins(br,vr[i]);
    vwr[i]=bins(br,vwr[i]);
  }
  for (int i=1;i<=n;i++) {
    //printf("i:%d vwp:%d vwr:%d vp:%d vr:%d\n",i,bp[vwp[i]],br[vwr[i]],bp[vp[i]],br[vr[i]]);
    if (vbad[i]) continue;
    vv.PB(MP(MP(vwp[i],vwr[i]),i));
  }
  sort(vv.begin(),vv.end());
  int vs=vv.size();
  int hid=0;
  pii prev;
  int ans=0;
  for (int i=0;i<vs;i++) {
    auto &w=vv[i];
    pii sig=w.fst;
    int p = w.fst.fst, r = w.fst.snd;
    if (i==0||sig!=prev) {
      hid++;
      hwr[hid] = r;
      hwp[hid] = p;
      if (!(p<=vp[0]&&r<=vr[0])) {
        fenwick_add(p, hid);
      }
      prev=sig;
    }
    if (!(p<=vp[0]&&r<=vr[0])) {
      vh[hid].PB(w.snd);
    }
    else {
      q.push(w.snd);
      ans++;
    }
  }

  for (int x=0;x<MAXN;x++) {
    sort(fent[x].begin(),fent[x].end(),cmp);
  }

  while(!q.empty()) {
    int qid=q.front(); q.pop();
    int hp=vp[qid],hr=vr[qid];
    while(1) {
      int hid = fenwick_query(hp, hr);
      if (hid==0) break;
      //printf("hid:%d\n",hid);
      vseen[hid]=true;
      ans+=vh[hid].size();
      for (auto id:vh[hid]) {
        //printf("id:%d\n",id);
        q.push(id);
      }
    }
  }
  printf("%d\n",ans);

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