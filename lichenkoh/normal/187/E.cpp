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
const ll LINF=1LL<<60;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
//#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=1e5+2;
class FirstK {
public:
  priority_queue<int> pq;
  priority_queue<int,vi,greater<int> > other;
  int k;
  ll sum=0;
  void rm() {int x=pq.top(); pq.pop(); other.push(x); sum-=x;}
  void add() {int x=other.top(); other.pop(); pq.push(x); sum+=x;}
  void ins(int x) {
    pq.push(x);
    sum+=x;
    if (pq.size()>k) {rm();}
  }
  void resizek(int nk) {
    k=nk;
    while(pq.size()>k) rm();
    while(pq.size()<k) add();
  }
};
int a[mn];
void fail(int t) {
  printf("-1\n"); exit(0);
}
vector<int> FAIL={-1};
ll getdist(vi &vans) {
  if (vans==FAIL) return LINF;
  ll dist=0;
  for (int i=1;i<vans.size();i++) {
    dist+=abs(a[vans[i]]-a[vans[i-1]]);
  }
  return dist;
}
void out(vi &vans) {
  ll dist=getdist(vans);
  if (dist>=LINF) {printf("-1\n"); exit(0);}
  printf("%lld\n",dist);
  for (int i=1;i<vans.size();i++) {
    printf("%d ",vans[i]);
  }
  printf("\n");
}
int solvesimple(vi &vdist, int l) {
  int n=vdist.size();
  FirstK fk;
  fk.resizek(0);
  for (int x=0;x<n-l;x++) {
    fk.ins(vdist[x]);
  }
  ll tail=0; for (int x=n-l;x<n;x++) tail+=vdist[x];
  int tlsz=l;
  pair<ll,int> best=MP(LINF,-1);
  {
    ll cost=fk.sum*2+tail;
    chkmin(best,MP(cost,tlsz));
  }
  for (int x=n-l;x<n;x++) {
    tail-=vdist[x];
    fk.ins(vdist[x]);
    fk.resizek(fk.k+1);
    ll cost=fk.sum*2+tail;
    tlsz--;
    chkmin(best,MP(cost,tlsz));
  }
  assert(tlsz==0);
  return best.snd;
}
bitset<mn> vb;
vi solvestart(vi &coord, int l) {
  if (!(l<=coord.size()-2)) return FAIL;
  vi vans;
  vector<int> odist;
  for (int x=1;x<coord.size()-1;x++) {
    odist.PB(abs(a[coord[x+1]]-a[coord[x]]));
  }
  int tlsz=solvesimple(odist,l);
  vector<pii> vdist;
  for (int x=1;x<coord.size()-1-tlsz;x++) {
    vdist.PB(MP(abs(a[coord[x+1]]-a[coord[x]]),x));
  }
  sort(vdist.begin(),vdist.end());
  vb.reset();
  for (int i=0;i<l-tlsz;i++) {
    int x=vdist[i].snd;
    vb[x]=true;
    dbg("x:%d. c: %d->%d\n",x,coord[x],coord[x+1]);
  }
  for (int x=coord.size()-1-tlsz;x<coord.size()-1;x++) vb[x]=true;
  vector<pii> chain;
  int lft=0;
  for (int x=0;x<coord.size();x++) {
    if (!vb[x]) {
      chain.PB(MP(lft,x));
      dbg("lft:%d x:%d\n",lft,x);
      lft=x+1;
    }
  }
  for (auto &w:chain) {
    int lft=w.fst,rt=w.snd;
    for (int x=rt;x>=lft;x--) {
      vans.PB(coord[x]);
      dbg("x:%d c:%d\n",x,coord[x]);
    }
  }
  return vans;
}

int n,l,s;

int rev(int x) {
  if (x==-1) return -1;
  return n+1-x;
}
void dorev() {
  s=rev(s);
  reverse(a+1,a+n+1);
  l=n-1-l;
}

vi solvemid() {
  int r=n-1-l;
  if (l==0) return FAIL;
  vi vans1;
  {
    vans1.PB(s);
    if (l<s) {
      for (int x=l;x>=1;x--) vans1.PB(x);
      for (int x=l+1;x<=n;x++) if (x!=s) vans1.PB(x);
    }
    else {
      assert(l>=s-1);
      for (int x=s-1;x>=2;x--) vans1.PB(x);
      vi coord; coord.PB(1);
      for (int x=s+1;x<=n;x++) coord.PB(x);
      vi res=solvestart(coord, l-(s-1));
      for (auto &w:res) vans1.PB(w);
    }
  }
  return vans1;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),l=rint(),s=rint();
  for (int i=1;i<=n;i++) a[i]=rint();
  if (s==1||s==n) {
    vi coord; for (int x=1;x<=n;x++) coord.PB(x);
    if (s==1) {
      vi ans=solvestart(coord,l);
      out(ans);
    }
    else {
      dorev();
      vi ans=solvestart(coord,l);
      dorev();
      for (auto &w:ans) w=rev(w);
      out(ans);
    }
  }
  else {
    if (l==0||n-1-l==0) fail(2);
    vi ans1=solvemid();
    ll d1=getdist(ans1);
    dorev();
    vi ans2=solvemid();
    dorev();
    for (auto &w:ans2) w=rev(w);
    ll d2=getdist(ans2);
    if (d2<=d1) {
      out(ans2);
    }
    else {
      out(ans1);
    }
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