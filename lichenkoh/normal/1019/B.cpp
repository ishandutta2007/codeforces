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
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
//const int TESTN=100000;
/*
vector<int> seed;
int gseed;
void init(int n) {
  gseed=clock();
  srand(gseed);
  vi b;
  for (int i=0;i<n/2;i++) {b.PB(1);}
  for (int i=0;i<n/2;i++) {b.PB(-1);}
  random_shuffle(b.begin(),b.end());
  seed.PB(1);
  for (int i=1;i<n;i++) {
    int last=seed.back();
    int now=last+b[i];
    seed.PB(now);
  }
  for (int i=0;i<n;i++) {
    //printf("%d ",seed[i]);
    assert(abs(seed[i]-seed[(i+1)%n])==1);
  }
  //printf("gseed:%d\n",gseed);
  vector<int> tmp; tmp.PB(-1234);
  for (auto &w:seed) tmp.PB(w);
  seed=tmp; assert(tmp.size()==n+1);
}
*/
//int globask=0;
int done(int x) {
  /*
  if (x==-1) {
    for (int i=1;i<TESTN/2;i++) {
      if(seed[i]==seed[i+TESTN/2]) {
        printf("x:%d i:%d VIOLATION. %d %d\n",x,i,seed[i],seed[i+TESTN/2]);
        assert(0);
      }
    }
  }
  else {
    assert(x<=TESTN/2 && x>=1);
    assert(seed[x]==seed[x+TESTN/2]);
  }
  assert(globask<=60);
  printf("OK asks:%d\n",globask);
  exit(0);
  */
  
  printf("! %d\n",x); fflush(stdout);
  exit(0);
  
}
map<int,int> h;
int gn;

int ask(int pos) {
  int ret;
  auto kt=h.find(pos);
  if (kt!=h.end()) {
    ret=kt->snd;
  }
  else {
    /*ret=seed[pos];
    globask++;*/
    
    printf("? %d\n",pos); fflush(stdout);
    scanf("%d",&ret);
    
  }
  h[pos]=ret;
  {
    auto it=h.find(pos-gn);
    if (it!=h.end() && (it->snd)==ret) done(pos-gn); 
  }
  {
    auto it=h.find(pos+gn);
    if (it!=h.end() && (it->snd)==ret) done(pos); 
  }
  return ret;
}
pii askp(pii p) {
  int l=ask(p.fst); int r=ask(p.snd);
  //printf("Ask: %d->%d. Got: %d %d\n",p.fst,p.snd,l,r);
  return MP(l,r);
}
typedef pair<pii,pii> ppii;
ppii askp2(pii p) {
  return MP(p,askp(p));
}
bool intersect(pii a, pii b) {
  if (a.fst==b.fst) return true;
  if (a.snd==b.snd) return true;
  return (a.fst<b.fst) != (a.snd<b.snd);
  int la=min(a.fst,a.snd);
  int ra=max(a.fst,a.snd);
  int lb=min(b.fst,b.snd);
  int rb=max(b.fst,b.snd);
  //printf("%d %d intersect %d %d\n",la,ra,lb,rb);
  if (rb<la) return false;
  if (ra<lb) return false;
  //printf("YES\n");
  return ((ll)(a.snd-a.fst))*(ll)(b.snd-b.fst)<0;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; scanf("%d",&n);
  /*int n=TESTN; init(n);*/
  n/=2;
  gn=n;
  if (n%2) {
    done(-1);
  }
  ppii cur[2];
  cur[0].fst=MP(1,n);
  cur[1].fst=MP(n+1,n+n);
  srand(clock());
  while(1) {
    int len0=cur[0].fst.snd-cur[0].fst.fst;
    int len1=cur[1].fst.snd-cur[1].fst.fst;
    /*printf("Iteration. %d->%d (%d %d) %d->%d (%d %d)\n",
      cur[0].fst.fst,cur[0].fst.snd,
      cur[0].snd.fst,cur[0].snd.snd,
      cur[1].fst.fst,cur[1].fst.snd,
      cur[1].snd.fst,cur[1].snd.snd
      );*/
    /*if (cur[0].fst.fst==cur[0].fst.snd && cur[1].fst.fst==cur[1].fst.snd) {
      if (cur[0].snd.fst == cur[0].snd.snd) {
        done(min(cur[0].fst.fst,cur[1].fst.fst));
      }
      else {
        done(-1);
      }
    }*/
    ppii nxt[2][2];
    int al=cur[0].fst.fst,ar=cur[0].fst.snd+1;
    int amid=(al+ar)/2;
    int rs=rand()&1;
    bool found=false;
    for (int t=0;t<2;t++) {
      if (rs^t) {
        int ap=0;
        cur[0]=askp2(MP(ap+al,ap+amid-1));
        ap=n;
        cur[1]=askp2(MP(ap+al,ap+amid-1));
      }
      else {
        int ap=0;
        cur[0]=askp2(MP(ap+amid,ap+ar-1));
        ap=n;
        cur[1]=askp2(MP(ap+amid,ap+ar-1));
      }
      if (intersect(cur[0].snd,cur[1].snd)) {
        found=true;
        break;
      }
    }
    /*for (int k=0;k<2;k++) {
      int ap=k*n;
      nxt[k][0]=askp2(MP(ap+al,ap+amid-1));
      nxt[k][1]=askp2(MP(ap+amid,ap+ar-1));
    }
    bool found=false;
    for (int a=0;a<2;a++) {
      int b=a;
      //for (int b=0;b<2;b++) {
        //pii tmp=nxt[0][a].fst;
        //tmp.fst+=n; tmp.snd+=n;
        if (
          //intersect(tmp, nxt[1][b].fst)&&
          intersect(nxt[0][a].snd, nxt[1][b].snd)
          ) {
          cur[0]=nxt[0][a];
          cur[1]=nxt[1][b];
          found=true;
        }
      //}
    }*/
    if (!found) done(-1);
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