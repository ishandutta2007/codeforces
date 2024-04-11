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
const int INF=1<<29;
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

const int MAXN=1e6+4;
const int MAXP=MAXN;
bool sieve_array[MAXP+1];
int ap[MAXP+1];
vector<int> gpv;

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
    ap[i]=1<<30;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = (int)(ceil(sqrt(MAXP)))+2;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
        ap[j]=i;
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
      ap[i]=i;
    }
  }
}
const int mn=1000000;
const int mk=10;

const int md=5000+1,mp=41;
vector<vi> f[md][mp];

int tmp[mk];
int factorize_tmp[500];
pii factorize(int ox) {
  int x=ox;
  int tsz=0;
  while(x>1) {
    int p=ap[x];
    x/=p;
    factorize_tmp[tsz++]=p;
  }
  if (x>1) factorize_tmp[tsz++]=x;
  sort(factorize_tmp,factorize_tmp+tsz);
  memset(tmp,0,sizeof tmp);
  int didx=0;
  int cnt=0;
  for (int t=0;t<tsz;t++) {
    int p=factorize_tmp[t];
    if (t==0||p!=factorize_tmp[t-1]) {
      tmp[didx++]=cnt;
      cnt=0;
    }
    cnt++;
  }
  if (cnt) tmp[didx++]=cnt;
  sort(tmp,tmp+mk);
  pii ans=MP(0,0);
  for (int i=0;i<mk/2;i++) {
    ans.fst*=20;
    ans.fst+=tmp[i];
    //if (ox==10)printf("%d, ",tmp[i]);
  }
  for (int i=mk/2;i<mk;i++) {
    ans.snd*=20;
    ans.snd+=tmp[i];
    //if (ox==10)printf("%d, ",tmp[i]);
  }
  //if (ox==10)printf("\n");
  return ans;
}
vector<pii> vs;
int bins(vector<pii> &v, pii key) {
  int imin=0,imax=v.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (v[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
int h[785+2][md];
pii x2p[mn+1];
void init() {
  sieve();
  set<pii> s;
  for (int x=1;x<=mn;x++) {
    pii got=factorize(x);
    x2p[x]=got;
    s.insert(got);
  }
  for (auto &w:s) {
    vs.PB(w);
  }
  //int blah=0;
  for (int si=0;si<vs.size();si++) {
    auto w=vs[si];
    vi v;
    while(w.fst) {
      v.PB(w.fst%20);
      w.fst/=20;
    }
    while(w.snd) {
      v.PB(w.snd%20);
      w.snd/=20;
    }
    sort(v.begin(),v.end(),greater<int>());
    //{
    //  int zz=1;
    //  for (auto &x:v) zz*=(x+1);
    //  chkmax(blah,zz);
    //}
    //if(si==42||si==108) {for (auto &x:v) printf("%d ",x); printf("\n");}
    for (int d=1;d<md;d++) {
      int final=INF;
      for (int p=0;p<mp;p++) {
        for (auto &a:f[d][p]) {
          int ans=0;
          int sz=min(a.size(),v.size());
          for (int i=0;i<sz;i++) {
            ans+=abs(a[i]-v[i]);
          }
          for (int i=sz;i<a.size();i++) ans+=a[i];
          for (int i=sz;i<v.size();i++) ans+=v[i];
          chkmin(final,ans);
        }
      }
      h[si][d]=final;
    }
  }
  //printf("blah:%d\n",blah);
}

void makechain() {
  vi emp;
  f[1][0].PB(emp);
  for (int d=2;d<md;d++) {
    for (int p=1;p<mp;p++) {
      if (d%(p+1)) continue;
      int x=d/(p+1);
      for (int q=0;q<=p;q++) {
        for (auto v:f[x][q]) {
          v.insert(v.begin(),p);
          //reverse(v.begin(),v.end());
          //if (d==24) {for (auto &w:v) printf("%d ",w); printf(" end chain\n");}
          f[d][p].PB(v);
        }
      }
    }
  }
}

void solve() {
  int x=bins(vs,x2p[rint()]); int y=bins(vs,x2p[rint()]);
  //printf("x:%d y:%d\n",x,y);
  int final=INT_MAX;
  for (int d=1;d<md;d++) {
    int ans=h[x][d]+h[y][d];
    chkmin(final,ans);
  }
  printf("%d\n",final);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  makechain();
  init();
  int T=rint();
  for (int i=0;i<T;i++) solve();
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