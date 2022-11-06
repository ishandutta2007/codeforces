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
  int y; scanf("%d",&y); return y;
    /*readAhead(16);

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

    return neg ? -x : x;*/
}
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

typedef pair<ll,ll> PLL;
namespace Factor {
  const int N=1010000;
  ll C,fac[10010],n,mut,a[1001000];
  int T,cnt,i,l,prime[N],p[N],psize,_cnt;
  ll _e[100],_pr[100];
  vector<ll> d;
  inline ll mul(ll a,ll b,ll p) {
    if (p<=1000000000) return a*b%p;
    else if (p<=1000000000000ll) return (((a*(b>>20)%p)<<20)+(a*(b&((1<<20)-1))))%p;
    else {
      ll d=(ll)floor(a*(long double)b/p+0.5);
      ll ret=(a*b-d*p)%p;
      if (ret<0) ret+=p;
      return ret;
    }
  }
  void prime_table(){
    int i,j,tot,t1;
    for (i=1;i<=psize;i++) p[i]=i;
    for (i=2,tot=0;i<=psize;i++){
      if (p[i]==i) prime[++tot]=i;
      for (j=1;j<=tot && (t1=prime[j]*i)<=psize;j++){
        p[t1]=prime[j];
        if (i%prime[j]==0) break;
      }
    }
  }
  void init(int ps) {
    psize=ps;
    prime_table();
  }
  ll powl(ll a,ll n,ll p) {
    ll ans=1;
    for (;n;n>>=1) {
      if (n&1) ans=mul(ans,a,p);
      a=mul(a,a,p);
    }
    return ans;
  }
  bool witness(ll a,ll n) {
    int t=0;
    ll u=n-1;
    for (;~u&1;u>>=1) t++;
    ll x=powl(a,u,n),_x=0;
    for (;t;t--) {
      _x=mul(x,x,n);
      if (_x==1 && x!=1 && x!=n-1) return 1;
      x=_x;
    }
    return _x!=1;
  }
  bool miller(ll n) {
    if (n<2) return 0;
    if (n<=psize) return p[n]==n;
    if (~n&1) return 0;
    for (int j=0;j<=20;j++) if (witness(rand()%(n-1)+1,n)) return 0;
    return 1;
  }
  ll gcd(ll a,ll b) {
    ll ret=1;
    while (a!=0) {
      if ((~a&1) && (~b&1)) ret<<=1,a>>=1,b>>=1;
      else if (~a&1) a>>=1; else if (~b&1) b>>=1;
      else {
        if (a<b) swap(a,b);
        a-=b;
      }
    }
    return ret*b;
  }
  ll rho(ll n) {
    for (;;) {
      ll X=rand()%n,Y,Z,T=1,*lY=a,*lX=lY;
      int tmp=20;
      C=rand()%10+3;
      X=mul(X,X,n)+C;*(lY++)=X;lX++;
      Y=mul(X,X,n)+C;*(lY++)=Y;
      for(;X!=Y;) {
        ll t=X-Y+n;
        Z=mul(T,t,n);
        if(Z==0) return gcd(T,n);
        tmp--;
        if (tmp==0) {
          tmp=20;
          Z=gcd(Z,n);
          if (Z!=1 && Z!=n) return Z;
        }
        T=Z;
        Y=*(lY++)=mul(Y,Y,n)+C;
        Y=*(lY++)=mul(Y,Y,n)+C;
        X=*(lX++);
      }
    }
  }
  void _factor(ll n) {
    for (int i=0;i<cnt;i++) {
      if (n%fac[i]==0) n/=fac[i],fac[cnt++]=fac[i];}
    if (n<=psize) {
      for (;n!=1;n/=p[n]) fac[cnt++]=p[n];
      return;
    }
    if (miller(n)) fac[cnt++]=n;
    else {
      ll x=rho(n);
      _factor(x);_factor(n/x);
    }
  }
  void dfs(ll x,int dep) {
    if (dep==_cnt) d.pb(x);
    else {
      dfs(x,dep+1);
      for (int i=1;i<=_e[dep];i++) dfs(x*=_pr[dep],dep+1);
    }
  }
  void norm() {
    sort(fac,fac+cnt);
    _cnt=0;
    rep(i,0,cnt) if (i==0||fac[i]!=fac[i-1]) _pr[_cnt]=fac[i],_e[_cnt++]=1;
      else _e[_cnt-1]++;
  }
  vector<ll> getd() {
    d.clear();
    dfs(1,0);
    return d;
  }
  vector<ll> factor(ll n) {
    cnt=0;
    _factor(n);
    norm();
    return getd();
  }
  vector<PLL> factorG(ll n) {
    cnt=0;
    _factor(n);
    norm();
    vector<PLL> d;
    rep(i,0,_cnt) d.pb(mp(_pr[i],_e[i]));
    return d;
  }
  bool is_primitive(ll a,ll p) {
    assert(miller(p));
    vector<PLL> D=factorG(p-1);
    rep(i,0,SZ(D)) if (powl(a,(p-1)/D[i].fi,p)==1) return 0;
    return 1;
  }
  ll phi(ll n) {
    vector<PLL> d=factorG(n);
    for (auto p:d) n=n/p.fi*(p.fi-1);
    return n;
  }
}

const ll MAXN=sqrt(1e9)+4;
const ll MAXP=MAXN;
bool sieve_array[MAXP+1];
ll sp[MAXP+1];
vector<int> gpv;

void sieve() {
  for (ll i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
    sp[i]=INF;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  ll lim = sqrt(MAXP)+1;
  for (ll i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (ll j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
        chkmin(sp[j],i);
      }
    }
  }
  for (ll i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
      chkmin(sp[i],i);
    }
  }
}

bool isprime(int n) {
  return Factor::miller(n);
  /* sqrt(n) version
  for (auto &p:gpv) {
    if (p*p>n) return 1;
    if (n%p==0) return 0;
  }
  return 1;*/
}

//typedef rational_t rat;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  Factor::init(10);
  //sieve();
	int tt=readInt();
  for (int jj=0;jj<tt;jj++) {
    int n=readInt();
    ll lep=-1,grp=-1;
    srand(rand()+clock());
    for (int p=n;p>=2;p--) {
      if (isprime(p)) {lep=p; break;}
    }
    for (int p=n+1;;p++) {
      if (isprime(p)) {grp=p; break;}
    }
    ll nu=lep*grp+2*(n-lep+1-grp);
    ll de=2*lep*grp;
    ll g=__gcd(nu,de);
    //printf("ur: %lld %lld\n",nu,de);
    nu/=g; de/=g;
    //rat ans=rat(1,2)-rat(1,lep)+rat(n-lep+1,lep*grp);
    //printf("lep:%lld %lld\n",lep,grp);
    printf("%lld/%lld\n",nu,de);
  }
}