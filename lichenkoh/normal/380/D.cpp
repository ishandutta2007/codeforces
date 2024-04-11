#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
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

int readInt()
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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}


template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n) { ll ret = 1; ll p = a % MOD; while (n) { if (n & 1) ret = ret * p % MOD; p = p * p % MOD; n >>= 1; } return ret; }
const ll MAXFACT=1e5+4;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
void init() {
  ll got=1;
  for (ll x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2);
  for (ll x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
}
ll binom(ll n,ll k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}

ll starbar(ll stars, ll parts) {
  if (parts==0) {
    return (stars==0)?1:0;
  }
  if (parts<=0||stars<0) return 0;
  return binom(stars+parts-1,parts-1);
}



const int mn=1e5+4;
int n;
int gx2t[mn];
int gt2x[mn];
vector<pair<int,int> > gvec;
int x2t[mn];
int t2x[mn];
vector<pair<int,int> > vec;

int l,r;
bool ok;
bool canright(int t) {
  return !(r+1>n||x2t[r+1]>t);
}
bool canleft(int t) {
  return !(l-1<1||x2t[l-1]>t);
}
void goright(int t) {
  if (!canright(t)) ok=false;
  r++;
  //printf("goright l:%d r:%d\n",l,r);
}
void goleft(int t) {
  if (!canleft(t)) ok=false;
  l--;
  //printf("goleft l:%d r:%d\n",l,r);
}
ll solve(int initright, int endright) {
  //printf("initright:%d endright:%d\n",initright,endright);
  ok=true;
  memcpy(x2t,gx2t,sizeof x2t);
  memcpy(t2x,gt2x,sizeof t2x);
  vec=gvec;
  if (endright) {
    if (x2t[n]!=n&&x2t[n]!=0) return 0;
    if (x2t[n]==0) {
      x2t[n]=n;
      t2x[n]=n;
      vec.PB(MP(n,n));
    }
  }
  else {
    if (x2t[1]!=n&&x2t[1]!=0) return 0;
    if (x2t[1]==0) {
      x2t[1]=n;
      t2x[n]=1;
      vec.PB(MP(n,1));
    }
  }
  int vsz=vec.size();
  ll ans=0;
  {
    int i=0;
    int t=vec[i].fst,x=vec[i].snd;
    l=x,r=x;
    for (int i=1;i<t;i++) {if (initright) goright(t); else goleft(t);}
    if (t==1) ans=1;
    else ans=mod_pow(2,t-2);
    //printf("INIT t:%d x:%d ans:%lld\n",t,x,ans);
  }
  for (int i=0;i<vsz-1;i++) {
    int t=vec[i].fst,x=vec[i].snd;
    int nt=vec[i+1].fst,nx=vec[i+1].snd;
    if (nx<l) {
      int cl=0;
      for (int i=t+1;i<=nt-1;i++) {
        if (canleft(t)) {goleft(t); cl++;}
        else goright(t);
      }
      goleft(nt);
      if (l!=nx) return 0;
      ans=mul(ans,binom(nt-t-1,cl));
    }
    else if (nx>r) {
      int cr=0;
      for (int i=t+1;i<=nt-1;i++) {
        if (canright(t)) {goright(t); cr++;}
        else goleft(t);
      }
      goright(nt);
      if (r!=nx) return 0;
      ans=mul(ans,binom(nt-t-1,cr));
    }
    else return 0;
    //printf("t:%d x:%d nt:%d nx:%d ans:%lld\n",t,x,nt,nx,ans);
  }
  if (!ok) return 0;
  //printf("initright:%d endright:%d ans:%lld\n",initright,endright,ans);
  return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  init();
	scanf("%d",&n);
  for (int x=1;x<=n;x++) {
    scanf("%d",&gx2t[x]);
  }
  if (n==1) {
    printf("1\n"); return 0;
  }
  for (int x=1;x<=n;x++) {
    int t=gx2t[x];
    if (t!=0) {
      gt2x[t]=x;
      gvec.PB(MP(t,x));
    }
  }
  sort(gvec.begin(),gvec.end());
  ll ans=0;
  if ((int)gvec.size()==0) {
    ans=mod_pow(2,n-1);
  }
  else {
    for (int k=0;k<2;k++) {
      ans+=solve(0,k);
      if (gvec[0].fst!=1) ans+=solve(1,k);
    }
  }
  ans%=MOD;
  printf("%d\n",(int)ans);
}