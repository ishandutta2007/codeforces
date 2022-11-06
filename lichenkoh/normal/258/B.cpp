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
int vlimdig[12];
int dpf[12][2][12];
const int LS=0,EQ=1,GR=2;
int getstate(int canddig, int limdig, int state) {
  if (state==EQ) {
    if (canddig<limdig) return LS;
    else if (canddig==limdig) return EQ;
    else return GR;
  }
  else return state;
}
void f(int pos, int state) {
  if (pos==0) {
    dpf[pos][state][0]=1;
    return;
  }
  for (int lucky=0;lucky<=9;lucky++) {
    for (int d=0;d<=9;d++) {
      int needlucky=lucky;
      if (d==4||d==7) needlucky--;
      if (needlucky<0) continue;
      int newstate=getstate(d, vlimdig[pos], state);
      if (newstate==GR) continue;
      int add=dpf[pos-1][newstate][needlucky];
      dpf[pos][state][lucky]+=add;
      dpf[pos][state][lucky]%=MOD;
    }
  }
}

int extgcd(int a, int b, int& x, int& y) { for (int u = y = 1, v = x = 0; a;) { int q = b / a; swap(x -= q *(ll) u, u); swap(y -= q *(ll) v, v); swap(b -= q *(ll) a, a); } return b; }
int mod_inv(int a, int m) { int x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
const int MAXFACT=100+4;
int fact[MAXFACT+1],invfact[MAXFACT+1];
void init() {
  int got=1;
  for (int x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2,MOD);
  for (int x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
}
int binom(int n,int k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}

ll perm(ll n, ll k) {
  ll numer=1;
  for (int x=0;x<k;x++) {
    numer=mul(numer,n-x);
  }
  return numer;
}
ll g[2][50][50];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  int m=rint();
  int lim=m;
  for (int d=0;d<=10;d++) {
    vlimdig[d+1]=lim%10;
    lim/=10;
  }
  for (int pos=0;pos<=11;pos++) for (int s=0;s<2;s++) f(pos,s);
  dpf[11][EQ][0]--;
  int cur=0,nxt=1;
  g[cur][0][0]=1;
  for (int lucky=0;lucky<=9;lucky++) {
    memset(g[nxt],0,sizeof g[nxt]);
    int have=dpf[11][EQ][lucky];
    for (int take=0;take<=6;take++) {
      ll permm=perm(have,take);
      //printf("have:%d take:%d permm:%d\n",have,take,permm);
      for (int has=6;has>=0;has--) {
        if (has+take>6) continue;
        ll inter=binom(has+take,has);
        ll mull=mul(inter,permm);
        for (int sumlucky=9;sumlucky>=0;sumlucky--) {
          int prev=g[cur][has][sumlucky];
          int newlucky=sumlucky+lucky*take;
          if (newlucky<=9) {
            //if (newlucky==0) printf("has:%d take:%d prev:%d permm:%d inter:%d\n",has,take,prev,permm,inter);
            g[nxt][has+take][newlucky]+=prev*(ll)mull;
            g[nxt][has+take][newlucky]%=MOD;
          }
        }
      }
    }
    swap(cur,nxt);
  }
  ll final=0;
  ll lower=0;
  for (int lucky=0;lucky<=9;lucky++) {
    ll upper=dpf[11][EQ][lucky];
    final=(final+upper*lower)%MOD;
    lower+=g[cur][6][lucky];
    lower%=MOD;
    //printf("lucky:%d lower:%d upper:%d\n",lucky,lower,upper);
  }
  final%=MOD;
  printf("%lld\n",final);
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