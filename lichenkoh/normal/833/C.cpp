#include <bits/stdc++.h>
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
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
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
struct S {
  int c[10];
  void clr() {memset(c,0,sizeof c);}
};
struct ST {
  int c[10];
  int lo, hi,extra;
  void clr() {memset(c,0,sizeof c);}
};
const int K=5;
const int MSK=(1<<K)-1;
ll vgen[4686824];
int gsz=0;
void fgen(ll x, int d, int sz) {
  vgen[gsz++]=(x);
  if (sz>=18) return;
  for (int nd=d;nd<=9;nd++) {
    ll z=x+(1LL<<(nd*K));
    fgen(z,nd,sz+1);
  }
}
ll pten[19];
int digl[19],digr[19];
vector<ST> vcand;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  for (int nd=1;nd<=9;nd++) {
    ll z=(1LL<<(nd*K));
    fgen(z,nd,1);
  }
  //printf("sz:%d\n",vgen.size());
  ll L=rlong()-1,R=rlong()+1;
  pten[0]=1;
  for (int i=1;i<19;i++) pten[i]=pten[i-1]*10;
  for (int x=18;x>=0;x--) {
    ll pt=pten[x];
    digl[x]=(L/pt)%10;
    digr[x]=(R/pt)%10;
  }
  ST pre; pre.clr();
  ST pl,pr;
  for (int x=18;x>=0;x--) {
    if (digl[x]!=digr[x]) {
      ST o=pre;
      o.lo=digl[x]+1;
      o.hi=digr[x]-1;
      o.extra=x;
      if (o.lo<=o.hi) vcand.PB(o);
      pl=pre;pr=pre;
      pl.hi=9;
      pr.lo=0;
      for (int y=x;y>=1;y--) {
        pl.c[digl[y]]++;
        pl.lo=digl[y-1]+1;
        pr.c[digr[y]]++;
        pr.hi=digr[y-1]-1;
        pl.extra=pr.extra=y-1;
        if (pl.lo<=pl.hi) vcand.PB(pl);
        if (pr.lo<=pr.hi) vcand.PB(pr);
      }
      break;
    }
    pre.c[digl[x]]++;
  }
  /*for (auto &cand:vcand) {
    for (int d=1;d<=9;d++) {
      if (cand.c[d])printf("(%d, %d) ",d,cand.c[d]);
    }
    printf("lo:%d hi:%d end cand\n",cand.lo,cand.hi);
  }*/
  int final=0;
  for (int ii=0;ii<4686824;ii++) {
    ll lreq=vgen[ii];
    S req;
    for (int d=1;d<=9;d++) {
      req.c[d]=(lreq>>(d*K))&MSK;
      //if (req.c[d]) printf("(%d, %d) ",d,req.c[d]);
    }
    //printf("\n");
    for (auto &cand:vcand) {
      int need=0;
      bool hasres=1;
      bool bad=false;
      for (int d=1;d<=9;d++) {
        int nd=req.c[d]-cand.c[d];
        if (nd<0) {
          bad=true; break;
        }
        if (nd>0) {
          if (hasres&&cand.lo<=d&&d<=cand.hi) {
            nd--; hasres=0;
          }
          need+=nd;
        }
      }
      if (cand.lo==0) hasres=0;
      if (bad||hasres) continue;
      if (need<=cand.extra) {
        //for (int d=1;d<=9;d++) {
        //  if (req.c[d])printf("(%d, %d) ",d,req.c[d]);
        //}
        //printf("\n");
    //for (int d=1;d<=9;d++) {
    //  if (cand.c[d])printf("(%d, %d) ",d,cand.c[d]);
    //}
    //printf("lo:%d hi:%d extra:%d end cand\n",cand.lo,cand.hi,cand.extra);
        final++;
        break;
      }
    }
  }
  printf("%d\n",final);
}