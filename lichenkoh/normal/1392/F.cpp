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
const int mn=(1e6)+8;

ll a[mn];
ll b[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  ll sumall=0;
  for (int i=n-1;i>=0;i--) {
  	ll x=rlong();
  	sumall+=x; a[i]=x;
  }
  ll mean=sumall/n;
  {
  	ll excess=0;
  	for (int i=0;i<n;i++) {
  		ll hi=mean+n-1-i;
  		if (a[i]>hi) {
  			excess+=a[i]-hi;
  			a[i]=hi;
  		} else {
  			ll take=min(hi-a[i],excess);
  			a[i]+=take;
  			excess-=take;
  		}
  	}
  }
  {
  	ll deficit=0;
  	for (int i=n-1;i>=0;i--) {
  		ll lo=mean-i;
  		if (a[i]<lo) {
  			deficit+=lo-a[i];
  			a[i]=lo;
  		} else {
  			ll take=min(a[i]-lo,deficit);
  			a[i]-=take;
  			deficit-=take;
  		}
  	}
  }
  /*for (int p=0;p<n;p++) {
  	printf("%lld ",a[p]);
  }
  printf(" post\n");
  */
  stack<int> S;
  for (int i=0;i<2*n;i++) S.push(0);
  for (ll p=1;p<n;p++) {
  	ll ap1=a[p-1],ap=a[p];
  	if (ap1==ap) {
  		S.push(p);
  	}
  	else if (ap1==ap+1) {
  		// Nothing
  	} else {
  		assert(ap1>=ap+2);
  		while(1) {
  			ll need=a[p-1]-1-a[p];
  			assert(need>=-1);
  			if (need<=0) break;
  			ll top=S.top();
  			ll havetop=p-top;
  			if (need>=havetop) {
  				need-=havetop;
  				S.pop();
  				assert(p-top==havetop);
  				b[top]--;
  				b[p-1]++;
  				a[p-1]--;
  				a[p]+=havetop;
  			} else {
  				b[top]--;
  				b[top+need]++;
  				a[p]+=need;
  				S.pop();
  				S.push(top+need);
  				break;
  			}
  		}
  		ap1=a[p-1]; ap=a[p];
  		assert(ap1>=ap);
  		assert(ap1<=ap+1);
  		if (ap1==ap) S.push(p);
  	}
  }
  ll bpre=0;
  for (int p=0;p<n;p++) {
  	bpre+=b[p];
  	a[p]+=bpre;
  }
  for (int p=n-1;p>=0;p--) {
  	ll ans=a[p];
  	printf("%lld ",ans);
  }
  printf("\n");
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