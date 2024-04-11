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
const int mn=1002;
map<int,int,greater<int> > vc[mn];
map<int,int,greater<int> > ah;
int vspec[mn];
int vup[mn];
int vall[mn];
ld vsits[2][mn];
ld vgood[2][mn];
typedef __float128 lld;
lld logfact[mn];
ld binom[mn][mn];
ld _binom(int n, int k) {
  return exp((ld)(logfact[n]-logfact[k]-logfact[n-k]));
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int x=1;x<mn;x++) {
    logfact[x]=logfact[x-1]+log(x);
  }
  for (int x=0;x<mn;x++) {
    for (int y=0;y<=x;y++) {
      binom[x][y]=_binom(x,y);
    }
  }
  int n=rint(),m=rint();
  for (int x=0;x<m;x++) {
    int k=rint();
    for (int i=0;i<k;i++) {
      int y=rint();
      ah[y]++;
      vc[x][y]++;
    }
    vall[x]=k;
  }
  int have=0;
  int spec=-1,speclim=-1;
  for (auto &w:ah) {
    //printf("%d:%d\n",w.fst,w.snd);
    if (have+w.snd==n) {
      spec=w.fst-1;
      speclim=0;
      break;
    }

    if (have+w.snd>n) {
      spec=w.fst;
      speclim=n-have;
      break;
    }
    have+=w.snd;
  }
  for (int x=0;x<m;x++) {
    for (auto &w:vc[x]) {
      if (w.fst>spec) {
        vup[x]+=w.snd;
      }
    }
    vspec[x]=min(speclim,vc[x][spec]);
  }
  vector<pair<int,pii> > tmp; tmp.reserve(m);
  for (int x=0;x<m;x++) {
    tmp.PB(MP(vspec[x],MP(vall[x],vup[x])));
  }
  sort(tmp.begin(),tmp.end());
  int allspecs=0;
  for (int x=0;x<m;x++) {
    auto got=tmp[x];
    vspec[x]=got.fst;
    vall[x]=got.snd.fst;
    vup[x]=got.snd.snd;
    //printf("%d %d %d\n",vspec[x],vall[x],vup[x]);
    allspecs+=vspec[x];
  }
  int cur=0,nxt=1;
  int specsum=0;
  vsits[cur][0]=1;
  vgood[cur][0]=1;
  for (int x=0;x<m;x++) {
    memset(vsits[nxt],0,sizeof vsits[nxt]);
    memset(vgood[nxt],0,sizeof vgood[nxt]);
    int sx=vspec[x];
    for (int s=0;s<=specsum;s++) {
      //printf("x:%d s:%d sits:%Lf good:%Lf good/sits:%Lf\n",x,s,vsits[cur][s],vgood[cur][s],vgood[cur][s]/vsits[cur][s]);
      for (int ds=0;ds<=sx;ds++) {
        int ns=s+ds;
        int ch=vup[x]+ds;
        vsits[nxt][ns]+=vsits[cur][s];
        vgood[nxt][ns]+=(binom[vspec[x]][ds]/binom[vall[x]][ch])*(vgood[cur][s]);
        //printf("x:%d s:%d ds:%d ns:%d sitadd:%Lf goodadd:%Lf\n",x,s,ds,ns,vsits[cur][s],(binom[vspec[x]][ds]/binom[vall[x]][ch])*(vgood[cur][s]/vsits[cur][s])*vsits[cur][s]);
        //int goodx=vup[x]+sx;
        //if (ns==0) printf("x:%d s:%d ds:%d ns:%d padd:%Lf vup:%d sx:%d ch:%d\n",x,s,ds,ns,binom(sx,ds)*vp[cur][s],vup[x],sx,ch);
      }
    }
    specsum+=vspec[x];
    chkmin(specsum,speclim);
    swap(cur,nxt);
  }
  /*for (int s=0;s<=specsum;s++) {
    printf("x:%d s:%d sits:%Lf good:%Lf good/sits:%Lf\n", n-1, s, vsits[cur][s], vgood[cur][s],
           vgood[cur][s] / vsits[cur][s]);
  }*/
  ld numer=vgood[cur][speclim];
  ld denom=vsits[cur][speclim];
  //printf("speclim:%d numer:%Lf denom:%Lf\n",speclim,numer,denom);
  //printf("%Lf %Lf\n",numer,denom);
  ld final=numer/denom;
  printf("%.12f\n",(double)final);
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