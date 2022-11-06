#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <random>
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
int rint();char rch();long long rlong();
mt19937 rng;

const int mn=1e5+4;
void pr(vector<pair<int,pii> > &vans) {
  printf("YES\n%d\n",(int)vans.size());
  for (auto &w:vans) {
    printf("%d %d %d\n",w.fst+1,w.snd.fst+1,w.snd.snd+1);
  }
  exit(0);
}
void fail() {
  printf("NO\n"); exit(0);
}

void push(vector<pair<int,pii> > &vans, int x, int y, int z) {
  vans.PB(MP(x,MP(y,z)));
}

const int mk=6+6+2;
auto start=std::chrono::high_resolution_clock::now().time_since_epoch();
int vdist[1<<mk];
int orig[1<<mk];
pair<bool, vector<pair<int,pii> > > bf(bitset<mk> a,int n) {
  int init=0;
  for (int i=0;i<n;i++) if(a[i]) init|=1<<i;
  int zlim=1<<n; for (int z=0;z<zlim;z++) vdist[z]=INF;
  queue<int> q; q.push(init); vdist[init]=0;
  vector<int> sig;
  vector<pair<int,pii> > vans;
  for (int x=0;x<n-2;x++) {
    for (int d=1;d<=(n-1-x)/2;d++) {
      sig.PB((1<<x)|(1<<(x+d))|(1<<(x+d+d)));
    }
  }
  while(!q.empty()) {
    int x=q.front(); q.pop();
    if (x==0) {
      while(x!=init) {
        int y=orig[x];
        int z=x^y;
        vi got;
        for (int i=0;i<n;i++) if (z&(1<<i)) got.PB(i);
        vans.PB(MP(got[0],MP(got[1],got[2])));
        x=y;
      }
      return MP(true,vans);
    }
    int ndist=vdist[x]+1;
    for (auto &s:sig) {
      int y=x^s;
      if (vdist[y]==INF) {
        orig[y]=x;
        vdist[y]=ndist;
        q.push(y);
      }
    }
  }
  return MP(false,vans);
}
/*
pair<bool,vector<pair<int,pii> > > bf(bitset<mk> &oa, int deadline, int n) {
  vector<pair<int,pii> > best;
  bitset<mk> a;
  if (oa.count()==0) return MP(true,best);
  if (n<=2) {
    return MP(false,best);
  }
  bool bestans=false;
  int lim=(n/3)+12;
  while(1) {
    auto now=std::chrono::high_resolution_clock::now().time_since_epoch();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now-start).count() > deadline) break;
    rng.seed(now.count());
    a=oa;
    bool ok=0;
    vector<pair<int,pii> > vans; vans.reserve(lim);
    for (int k=0;k<lim;k++) {
      int x=rng()%(n-2);
      int d=rng()%((n-1-x)/2) + 1;
      for (int y=x;y<=x+d+d;y+=d) {
        a[y]=!a[y];
      }
      push(vans,x,x+d,x+2*d);
      if (a.count()==0) {ok=true; break;}
    }
    if (ok) {
      if (!bestans||vans.size()<best.size()) {
        best=vans;
        bestans=true;
      }
    }
  }
  return MP(bestans,best);
}
*/
void psh(bitset<mn> &a, vector<pair<int,pii> > &vans, int x, int y, int z) {
  vans.PB(MP(x,MP(y,z)));
  a[x]=!a[x];
  a[y]=!a[y];
  a[z]=!a[z];
}

bool f(bitset<mn> &a,vector<pair<int,pii> > &vans, int s, int d) {
  assert(s>=0);
  //assert(a[s]);
  string b; b.resize(2);
  b[0]=a[s+d]+'0',b[1]=a[s+2*d]+'0';
  if (b=="00") {
    psh(a,vans,s,s+3*d,s+3*d*2);
  }
  else if (b=="01") {
    psh(a,vans,s,s+2*d,s+2*d*2);
  }
  else if (b=="11") {
    psh(a,vans,s,s+d,s+d*2);
  }
  else return false;
  //assert(!a[s]);
  //assert(!a[s+1]);
  //assert(!a[s+2]);
  return true;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //go(); return 0;
  int n; cin>>n;
  if (n<=mk) {
    bitset<mk> oa;
    for (int i=0;i<n;i++) {int x; cin>>x; oa[i]=x;}
    auto got=bf(oa,n);
    if (got.fst) pr(got.snd);
    else fail();
  }
  bitset<mn> a;
  for (int i=0;i<n;i++) {int x; cin>>x; a[i]=x;}
  vector<pair<int,pii> > vans;
  if (a.count()==0) pr(vans);
  int l=0,r=n-1;
  while(1) {
    while(l<n&&!a[l]) ++l;
    while(r>=0&&!a[r]) --r;
    if (l>r) break;
    //assert(a[l]);
    //assert(a[r]);
    assert(l>=0);
    assert(r>=0);
    if (r-l+1 <= mk-6) break;
    if (!f(a,vans,l,1)) {
      if (!f(a,vans,r,-1)) {
        if ((r-l)%2==0) {
          psh(a,vans,l,(l+r)/2,r);
          psh(a,vans,l+1,(l+r)/2,r-1);
        }
        else {
          psh(a,vans,l,(l+r-1)/2,r-1);
          psh(a,vans,l+1,(l+1+r)/2,r);
        }
      }
    }
  }
  bitset<mk> c;
  //for (int x=0;x<l;x++) assert(!a[x]);
  //for (int x=r+1;x<n;x++) assert(!a[x]);
  int D=min(3,l);
  for (int x=l;x<=r;x++) {
    c[x-l+D]=a[x];
  }
  int lft=mk-(r-l+1)-D;
  int R=min(lft,n-1-r+1);
  //printf("D:%d R:%d l:%d r:%d\n",D,R,l,r);
  pair<bool,vector<pair<int,pii> > > got=bf(c,r-l+1+D+R);
  if (!got.fst) {
    fail();
  }
  else {
    for (auto &w:got.snd) {
      psh(a,vans,w.fst-D+l,w.snd.fst-D+l,w.snd.snd-D+l);
    }
    //assert(a.count()==0);
    pr(vans);
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