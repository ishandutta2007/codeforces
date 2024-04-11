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

int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}
typedef vector<pair<int,int> > vpii;
vpii factorize(int n) {
	vpii fact;
  for (int i=2; i*i<=n; ++i) {
    if (n % i == 0) {
    	int e=0;
      while (n % i == 0) {
        n /= i;
        ++e;
      }
      fact.push_back(make_pair(i,e));
    }
  }
  if (n>1) fact.push_back(make_pair(n,1));
  return fact;
}
int findorder(int x, int p, vpii &phifact) {
	int now=p-1;
	for (auto &fe: phifact) {
		int factor=fe.fst, elim=fe.snd;
		for (int e=0;e<elim;e++) {
			if (powmod(x, now/factor, p)==1) {
				now/=factor;
			}
		}
	}
	return now;
}

int divisors_dest[50000]; // This needs to be larger than you think
int divisors_mu[50000]; // mobius function of each divisor
int getdivisors(vpii &fact) {
  // Puts all divisors into int divisors_dest[], and returns the count
  int sz=1;
  divisors_dest[0]=1;
  divisors_mu[0]=1;
  for (auto &w:fact) {
    int p=w.fst; int elim=w.snd;
    int pp=1;
    int prevsz=sz;
    for (int e=1;e<=elim;e++) {
      pp*=p;
      for (int i=0;i<prevsz;i++) {
        divisors_dest[sz]=divisors_dest[i]*pp;
        if (e==1) divisors_mu[sz]=-divisors_mu[i];
        else divisors_mu[sz]=0;
        ++sz;
      }
    }
  }
  return sz;
}

const int mn=1e4+2;
int a[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint(),p=rint();
	for (int i=0;i<n;i++) a[i]=rint();
	int bgcd=rint();
	for (int i=1;i<m;i++) {
		bgcd=__gcd(rint(),bgcd);
	}
	vpii phifact=factorize(p-1);
	set<int> sorder;
	for (int i=0;i<n;i++) {
		int x=powmod(a[i],bgcd,p);
		int order=findorder(x,p,phifact);
		//printf("x:%d order:%d\n",x,order);
		sorder.insert(order);
	}
	vector<int> vorder; for (auto &w:sorder) vorder.PB((p-1)/w);
	//for (auto &w:phifact) printf("(%d,%d) ",w.fst,w.snd);
	int divsz=getdivisors(phifact);
	vector<int> vlog;
	map<int,int> d2mu;
	for (int di=0;di<divsz;di++) {
		int d=divisors_dest[di];
		d2mu[d]=divisors_mu[di];
		for (auto &w:vorder) {
			if (d%w==0) {vlog.PB(d); break;}
		}
	}
	ll final=0;
	for (auto &n:vlog) {
		ll ans=0;
		for (auto &e:vlog) {
			if (e%n==0) {
				//printf("n:%d e:%d contrib:%d\n",n,e,mu[e/n]*((p-1)/e));
				ans+=d2mu[e/n]*((p-1)/e);
			}
		}
		//printf("n:%d ans:%lld\n",n,ans);
		final+=ans;
	}
	printf("%lld\n",final);
}