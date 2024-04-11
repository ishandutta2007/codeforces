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
const ll LINF=1LL<<62;
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
typedef pair<ll,int> pli;
const int mn=5001;
ll f[2][5000];
ll sim[mn];
int g[5001][5000];
pli PINF=MP(-LINF,-1);
int a[5000];
void fail(int t) {
  printf("NO\n"); exit(0);
}
int target;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),k=rint();target=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  if (n==1) {
    if (target==a[0]) {
      printf("YES\n");
    }
    else {
      printf("NO\n");
    }
    exit(0);
  }
  {
    for (int i=0;i<n;i++) {
      if (a[i]==target) {
        printf("YES\n");
        exit(0);
      }
    }
  }
  fill(f[0],f[0]+k,LINF);
  f[0][0]=0LL;
  const int SIG=1<<30;
  for (int t=0;t<n;t++) {
    int cur=t;
    int nxt=t+1;
    fill(f[nxt&1],f[nxt&1]+k,LINF);
    int at=a[t]; int atmod=at%k;
    for (int x=0;x<k;x++) {
      pli got=MP(f[cur&1][x],g[cur][x]); if (got.fst>=LINF) continue;
      pli res;
      res=min(MP(f[nxt&1][x],g[nxt][x]),MP(got.fst,x));
      f[nxt&1][x]=res.fst; g[nxt][x]=res.snd;
      int y=(x+atmod); if (y>=k) y-=k;
      res=min(MP(f[nxt&1][y],g[nxt][y]),MP(got.fst+at,x|SIG));
      f[nxt&1][y]=res.fst; g[nxt][y]=res.snd;
    }
  }
  int targetmod=target%k;
  const int lim=1000000000;
  vector<pair<int,pii> > vans;
  if (targetmod==0) {
    ll sum=a[0];
    for (int x=1;x<n;x++) {
      vans.PB(MP(lim,MP(x,0)));
      sum+=a[x];
    }
    if (sum<target) fail(2);
    ll need=target/k;
    //printf("need:%lld\n",need);
    while(need>0) {
      int got=min((ll)lim,need);
      need-=got;
      vans.PB(MP(got,MP(0,1)));
    }
  }
  else {
    vector<int> v;
    {
      int x=targetmod;
      for (int t=n;t>=1;t--) {
        int got=g[t][x];
        if (got&SIG) {
          v.PB(t-1);
          got^=SIG;
        }
        x=got;
      }
    }
    if (v.size()==0) fail(4);
    ll sum=a[v[0]];
    for (int i=1;i<v.size();i++) {
      int x=v[i];
      vans.PB(MP(lim,MP(x,v[0])));
      sum+=a[x];
      //printf("x:%d a[x]:%d sum:%d\n",x,a[x],sum);
    }
    ll excess=(sum-target)/k;
    int unk=-1;
    for (int x=0;x<n;x++) {
      if (x!=v[0]) unk=x;
    }
    while (excess>0) {
      int get=min(excess,(ll)lim);
      vans.PB(MP(get,MP(v[0],unk)));
      excess-=get;
    }
    bitset<mn> b;
    for (auto &x:v) b[x]=true;
    int fi=-1;
    for (int x=0;x<n;x++) {
      if (!b[x]) {
        if (fi==-1) {
          fi=x;
        }
        else {
          vans.PB(MP(lim,MP(x,fi)));
        }
      }
    }
    while(excess<0) {
      int get=min((ll)lim,-excess);
      vans.PB(MP(get, MP(fi,v[0])));
      excess+=get;
    }
    if (excess!=0) fail(3);
  }
  for (int i=0;i<n;i++) sim[i]=a[i];
  for (auto &w:vans) {
    int c=w.fst,src=w.snd.fst,dest=w.snd.snd;
    ll trans=min(c*(ll)k,sim[src]);
    sim[src]-=trans;
    sim[dest]+=trans;
  }
  bool found=0;
  for (int i=0;i<n;i++) {
    if (sim[i]==target) found=1;
  }
  if (!found) fail(3);
  printf("YES\n");
  for (auto &w:vans) {
    if (w.fst!=0) printf("%d %d %d\n",w.fst,w.snd.fst+1,w.snd.snd+1);
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