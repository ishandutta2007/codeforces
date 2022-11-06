#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

class BestKI{
public:
  int b0,b1;
  void init(int const & worst) {
    b0=worst; b1=worst;
  }
  void add(int const & x) {
    if (x>b0) {
      b1=b0;
      b0=x;
    } else if (x>b1) {
      b1=x;
    }
  }
};

class BestKP {
public:
  pii b[2];
  void init(pii const & worst) {
    for (int i=0;i<2;i++) b[i]=worst;
  }
  void add(pii const & x) {
    if (x.fst>b[0].fst) {
      b[1]=b[0];
      b[0]=x;
    } else if (x.fst>b[1].fst) {
      b[1]=x;
    }
  }
};

const int mn=(5e5)+4;
int n;
int a[mn];
int amax=0;
int adivy[mn];
int divtable[mn];
ll suma=0;
const int s=sqrt(mn)+2;
int bki[s][2];
bool smallOk(int RX, int y, ll sumadivy) {
  BestKI two; two.init(-INF);
  for (int m=0;m<y;m++) {
    for (int t=0;t<2;t++) {
      int j=bki[m][t];
      if (j!=-INF) {
        int aj=a[j];
        if (aj>=RX) {
          if (aj>=2*RX) {
            int adjust=-(adivy[j])+(divtable[a[j]-2*RX]);
            ll have=sumadivy+adjust;
            if (have>=RX) {
              //printf("aj:%d adjust:%d have:%lld\n",aj,adjust,have);
              return true;
            }
          }
          {
            int adjust=-(adivy[j])+(divtable[a[j]-RX]);
            two.add(adjust);
            if (two.b1 != -INF) {
              int sumadjust=two.b0+two.b1;
              if (sumadjust+sumadivy >= RX) {
                //printf("b0:%d b1:%d adjust:%d\n",two.b0,two.b1,adjust);
                return true;
              }
            }
          }
        }
      }
    }
  }
  return false;
}

int smallWithY(int y) {
  {
    int init=0;;
    for (int k=0;init<mn;k++) {
      int xhi=min(mn,init+y);
      for (int x=init;x<xhi;x++) {
        divtable[x]=k;
      }
      init=xhi;
    }
  }
  for (int i=0;i<y;i++) for (int t=0;t<2;t++) bki[i][t]=-INF;
  ll sumadivy=0;
  for (int i=n-1;i>=0;i--) {
    int ai=a[i];
    int q=divtable[ai];
    int m=ai-q*y;
    adivy[i]=q;
    sumadivy+=q;
    for (int t=0;t<2;t++) {
      if (bki[y-1-m][t]==-INF) {
        bki[y-1-m][t]=i;
        break;
      }
    }
  }

  /*if (y==3) {
    bool dd=smallOk(3,y,sumadivy);
    printf("d:%d sumadivy:%lld\n",dd,sumadivy);
  } else {
    return -1;
  }*/

  int imin=2,imax=min((ll)mn,(suma/y))+1;
  while(imin<imax) {
    int imid=(imin+imax)/2;
    if (smallOk(imid,y,sumadivy)) {
      imin=imid+1;
    } else {
      imax=imid;
    }
  }
  return imin-1;
}
ll small() {
  ll ans=0;
  for (int y=2;y<=s;y++) {
    int RX=smallWithY(y);
    if (RX>=2) {
      ll cand=RX*((ll)y);
      //printf("y:%d RX:%d cand:%lld\n",y,RX,cand);
      chkmax(ans,cand);
    }
  }
  return ans;
}
//int getl(int ai, int k) {
//  return (ai+1+k)/(k+1);
//}

int f[s+1];
int cs=0;
int c[2*s+1];
int cdivy[2*s+1];
BestKP bk[2*s+1];
pii vbest2[2*s+1];

int bins(int key) {
  int imin=0,imax=cs;
  while(imin<imax) {
    int imid=(imin+imax)/2;
    if (c[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin;
}

bool bigOk(int RX, int all, int y) {
  // Search for good RX candidates
  // Can speed up by pregenerating segtree
  
  int ci2=bins(2*RX);
  
  if (ci2<cs) { // 2 RX logs from same log
    auto & best2=vbest2[ci2];
    if (best2.fst!= -INF) {
      int j=best2.snd;
      int adjust=-(cdivy[j])+((c[j]-2*RX)/y);
      int have=all+adjust;
      //printf("Two from same. have:%d\n",have);
      if (have>=RX) {
        return true;
      }
    }
  }
  int ci=bins(RX);
  if (ci<cs) {
    BestKP &b = bk[ci];
    if (b.b[1].fst != -INF) { // 1 RX log from 2 distinct logs
      int have=all;
      for (int t=0;t<2;t++) {
        int j=b.b[t].snd;
        int adjust=-(cdivy[j])+((c[j]-RX)/y);
        have+=adjust;
      }
      //printf("Two from distinct. have:%d\n",have);
      if (have>=RX) {
        return true;
      }
    }
  }
  return false;
}

ll big() {
  ll final=0;
  for (int y=max(2,s+1);y<=amax;y++) { // O(n)
    // Update splitting bars
    int q=0;
    for (int k=1;k<=s;k++) {
      chkmax(q,f[k]);
      while(q<n&&a[q]/y<k) q++;
      f[k]=q;
    }
    int all=0;
    for (int k=1;k<s;k++) {
      all+=(f[k+1]-f[k])*k;
    }

    int prevj=-1;
    cs=0;
    for (int k=0;k<s;k++) { // O(s)
      int jlo=max(f[k],f[k+1]-2);
      int jhi=f[k+1]-1;
      //printf("jlo:%d jhi:%d\n",jlo,jhi);
      for (int j=jlo;j<=jhi;j++) { // O(1)
        if (j>prevj) {
          int aj=a[j];
          //printf("cs:%d aj:%d\n",cs,aj);
          c[cs]=aj;
          cdivy[cs]=k;
          cs++;
        }
      }
      prevj=jhi;
    }
    sort(c,c+cs);
    bk[cs].init(MP(-INF,-INF));
    vbest2[cs]=MP(-INF,-INF);
    for (int i=cs-1;i>=0;i--) {
      bk[i]=bk[i+1];
      pii now=MP(c[i]-y*cdivy[i],i);
      bk[i].add(now);
      vbest2[i]=max(vbest2[i+1],now);
    }
    
    // Can optimize to all - (2*all/y) <= RX <= all
    int imin=2;
    int imax=min(amax,all)+1;

    /*if (y==5) {
    for (int i=0;i<cs;i++) {
      printf("i:%d c[i]:%d best2:%d %d. bk: (%d %d) and (%d %d)\n",i,c[i],vbest2[i].fst,vbest2[i].snd,
        bk[i].best[0].fst,bk[i].best[0].snd,
        bk[i].best[1].fst,bk[i].best[1].snd);
    }
      int RX=2;
      bool b=bigOk(RX,all,y);
      printf("b:%d\n",b);
      exit(0);
    } else {
      continue;
    }*/

    while(imin<imax) { // O(logn)
      int RX=(imin+imax)/2;
      bool ok=bigOk(RX,all,y);
      if (ok) {
        imin=RX+1;
      } else {
        imax=RX;
      }
    }
    {
      int RX=imin-1;
      if (RX>=2) {
        ll cand=RX*(ll)y;
        //printf("y:%d RX:%d cand:%lld\n",y,RX,cand);
        chkmax(final,cand);
      }
    }
  }
  return final;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int i=0;i<n;i++) {int ai=rint(); a[i]=ai; suma+=ai; chkmax(amax,ai);}
  sort(a,a+n);
  ll final=big();
  if (final < s*(ll)amax) {
    final=max(final,small());
  }
  //ll final=small();
  printf("%lld",final);
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