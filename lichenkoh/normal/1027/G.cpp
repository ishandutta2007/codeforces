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
typedef unsigned long long ull;
const int mk=48;
ull mulmod(ull a,ull b,ull c){
	//if (a>=c) a%=c; if (b>=c) b%=c;
	ull prod; bool ovf=__builtin_umulll_overflow(a,b,&prod);
	if (!ovf) return prod%c;
	if (b>a) swap(a,b);
  ull x = 0; ull y=a;
  while(b != 0){
    if(b&1 == 1){
      x = (x+y);
      if (x>=c) x-=c;
    }
    y<<=1; if (y>=c) y-=c;
    b>>=1;
  }
  return x%c;
}

ll ptable[mk];

ll mod_pow(ll n, ll mod) {
	ll ret = 1; //ll p = a % mod;
	int i=0;
	while (n) {
		if (n & 1) ret = mulmod(ptable[i], ret, mod);
		//p = mulmod(p, p, mod);
		n >>= 1;
		i++;
	}
	return ret;
}
vector<ll> vt;
ll eulerPhi (ll n) {
    ll result = n;
    // think that it like this, initially all numbers have gcd with n to be equal to 1.
    // Hence value of result is n
    // according to formulla  n * (1 - 1/p1) * (1 - 1/p2) .... * (1 - 1/pm). We will be calculating value 
    // of the product upto i. that is n * (1 - 1/p1) * ... (1 - 1/p_i)
    // So let us take example of p1. value of result after one iteration will be n - n / p1, which is precisly
    // n * (1 - 1/p1). 
    // Similarily by induction hypthesis we can say finally the result will be as required.

    for (int k=1;k<vt.size();k++) {
    	ll i=vt[k];
      if (n % i == 0) {
          result -= result / i;
          // By using while loop here, we are ensuing that all the numbers i will be prime.
          // because for every i, all it's multiples are gets removed.
          while (n % i == 0) {
              n /= i;
          }
      }
      if (n==1) break;
    }

    if (n > 1) {
        result -= result / n;
    }

    return result;
}
void initvt(ll origm) {
  ll phi=origm;
  ll dlim=min(phi,3+((ll)sqrt((ld)phi)));
  
  //total-=clock();
  for (ll d=1;d<=dlim;d++) {
  	ll quo=phi/d;
  	ll rem=phi%d;
  	if (rem==0) {
  		vt.PB(d); vt.PB(quo);
  	}
  }
  //total+=clock();
  sort(vt.begin(),vt.end());
  auto it=unique(vt.begin(),vt.end());
  vt.resize(it-vt.begin());
}
//clock_t total=0;
vector<ll> vd;

void initvd(ll origm) {
  ll phi=eulerPhi(origm);
  ll dlim=min(phi,3+((ll)sqrt((ld)phi)));
  
  //total-=clock();
  for (ll d=1;d<=dlim;d++) {
  	ll quo=phi/d;
  	ll rem=phi%d;
  	if (rem==0) {
  		vd.PB(d); vd.PB(quo);
  	}
  }
  //total+=clock();
  sort(vd.begin(),vd.end());
  auto it=unique(vd.begin(),vd.end());
  vd.resize(it-vd.begin());
}
vector<pair<ull,ull> > vz;
ll solve(ll origm) {
	//for (int i=0;i<mk;i++) ptable[i]=optable[i]%origm;
	ll phi=eulerPhi(origm);
  ll order=-1;
  for (auto &z:vz) {
  	ull d=z.snd; ll mm=z.fst;
  	if (phi%d==0) {
  		if (mm%origm==1) {
  			order=d; break;
  		}
  	}
  }
  ll final=phi/order;
  //printf("origm:%lld phi:%lld order:%lld\n",origm,phi,order);
  assert(phi%order==0);
  assert(order!=-1);
  return final;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll origm,a; cin>>origm>>a;
  initvt(origm);
  initvd(origm);
  
  {
  	ll p=a%origm;
  	ptable[0]=p;
  	for (int i=1;i<mk;i++) {
  		p=mulmod(p,p,origm);
  		ptable[i]=p;
  	}
  }
  for (auto &d:vd) {
  	vz.PB(MP(mod_pow(d,origm),d));
  }
  ll final=0;
  for (auto &d:vt) {
  	if (d!=1) final+=solve(d);
  }
  printf("%lld\n",final+1);
  //printf("%.9f\n",total/(double)CLOCKS_PER_SEC);
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