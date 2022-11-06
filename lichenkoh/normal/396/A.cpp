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

const ll MAXN=1e6+4;
const ll MAXP=MAXN;
bool sieve_array[MAXP+1];
ll sp[MAXP+1];
vector<ll> gpv;

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
/*map<int,int> factorize(ll x) {
	map<int,int> h;
	for (auto &p:gpv) {
		if (x==1||p*(ll)p>x) break;
		int cnt=0;
		while(x%p==0) {
			x/=p;
			cnt++;
		}
		if (cnt) h[p]=cnt;
	}
	if (x>1) h[x]++;
	return h;
}*/
map<ll,ll> factorize(ll x) {
	map<ll,ll> h;
	while(x>=MAXP) {
		bool found=false;
		for (auto &p:gpv) {
			if (p*p>x) break;
			ll cnt=0;
			while ((x%p)==0) {
				x/=p;
				cnt++;
			}
			if (cnt>0) {
				h[p]+=cnt;
				found=true;
			}
		}
		if (x<MAXP) break;
		if (!found) break;
	}
	if (x<MAXP) {
		while(x>1) {
		ll p=sp[x];
		x/=p;
		h[p]++;
		}
	}
	if (x>1) h[x]++;
	return h;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MAXFACT=1e5+4;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
void init() {
  ll got=1;
  for (ll x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2,MOD);
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

int f(ll x, ll n) {
	if (x==1&&n==0) return 1;
	else if (n==0) return 0;
	ll ans=0;
	for (ll y=1;y<=x;y++) {
		if (x%y==0) ans+=f(y,n-1);
	}
	return ans%MOD;
}

int brute(vector<int> v) {
	ll res=1;
	for (auto &w:v) res*=w;
	return f(res,v.size());
}

int solve(vector<int> v) {
	map<int,int> h;
	int n=v.size();
	for (int i=0;i<n;i++) {
		int x=v[i];
		//factorize(x, h);
		auto got=factorize(x);
		for (auto &w:got) {
			h[w.fst]+=w.snd;
		}
	}
	int ans=1;
	for (auto &w:h) {
		int got=starbar(w.snd,n);
		//printf("w.fst:%d %d\n",w.fst,w.snd);
		ans=(ans*got)%MOD;
	}
	return ans;
}
void test() {
	for (int k=0;k<10000;k++) {
		ll seed=clock()+rand()+time(0);
		srand(seed);
		int n=rand()%8;
		vector<int> v;
		for (int x=1;x<=n;x++) {
			int y=rand()%100+1;
			v.PB(y);
		}
		int b=brute(v),s=solve(v);
		if (b!=s) {
			printf("b:%d s:%d seed:%lld\n",b,s,seed);
			exit(0);
		}
		printf("."); fflush(stdout);
	}
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();
	init();
	//test();
	//return 0;
	int n; scanf("%d",&n);
	map<int,int> h;
	for (int i=0;i<n;i++) {
		int x; scanf("%d",&x);
		//factorize(x, h);
		auto got=factorize(x);
		for (auto &w:got) {
			h[w.fst]+=w.snd;
		}
	}
	ll ans=1;
	for (auto &w:h) {
		ll got=starbar(w.snd,n);
		//printf("w.fst:%d %d\n",w.fst,w.snd);
		ans=(ans*got)%MOD;
	}
	printf("%lld\n",ans);
}