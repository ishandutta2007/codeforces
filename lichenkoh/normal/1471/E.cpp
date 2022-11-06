#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
vi a;
int p;
void rot() {
  int n=a.size();
  vi b(n);
  for (int x=0;x<n;x++) {
    if (x==p) {
      b[(x+1)%n]+=a[x];
    } else {
      b[(x+1)%n]+=(a[x]+1)/2;
      b[(x-1+n)%n]+=(a[x])/2;
    }
  }
  a=b;
  //for (auto w:a) printf("%d ",w);
  //printf("\n");
}
int gn;
int gseed;
/*
int ask(int x) {
  int ans=a[x];
  rot();
  return ans;
}
void output(int x) {
  assert(0<=x&&x<gn);
  if(x!=p) {
    printf("seed: %d\n",gseed);
    assert(0);
  }
}
*/
int ask(int x) {
  ++x;
  assert(1<=x&&x<=gn);
  printf("? %d\n",x); fflush(stdout);
  int ans; scanf("%d",&ans);
  return ans;
}

void output(int x) {
  ++x;
  assert(1<=x&&x<=gn);
  printf("! %d\n",x); fflush(stdout);
  exit(0);
}

void go(int n, int k) {
  gn=n;
  int slim=ceil(sqrt(ld(n)))+1;
  for (int i=0;i<slim;i++) ask(0);
  vpii vq;
  int ssmall=max(1,(n/slim)-2);
  for (int x=0;x<n;x+=ssmall) {
    vq.PB(MP(x,-1));
  }
  vq.PB(MP(n-1,-1));
  for (auto &w:vq) {
    int got=ask(w.fst);
    w.snd=got;
    //printf("q:%d ans:%d\n",w.fst,w.snd);
  }
  int l=-1,r=-1;
  for (auto &w:vq) {
    if (w.snd<k) l=w.fst;
    if (w.snd>k) r=w.fst;
  }
  assert(l!=-1);
  assert(r!=-1);
  assert(l!=r);
  if (l>r) r+=n;
  while(l<r) {
    int imid=((l+r)/2);
    int got=ask(imid%n);
    //printf("l:%d r:%d imid:%d got:%d k:%d\n",l,r,imid,got,k);
    if (got<k) l=imid;
    else if (got>k) r=imid;
    else {
      assert(got==k);
      output(imid%n);
      exit(0);
    }
  }
}

void gen() {
  int n=4+rand()%150;
  int k=2*(1+rand()%90);
  p=rand()%n;
  //printf("n:%d k:%d p:%d\n",n,k,p);
  a.resize(n);
  for (auto &w:a) w=k;
  go(n,k);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //int tt=time(0);
  //int seed=tt^clock();
  //gseed=seed;
  ////printf("seed:%d\n",seed);
  //srand(seed);
  //gen(); return 0;
  int n,k; scanf("%d %d",&n,&k);
  go(n,k);
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