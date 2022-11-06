#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
const int mn=2e5+1;
ll p[mn];ll sp[mn];

ll pa,ra,pb,rb;
ll query(ll l, ll r) {
	return sp[r+1]-sp[l];
}
ll f(int t) {
	ll lcm=(ra*(ll)rb)/__gcd(ra,rb);
	ll nab=t/lcm;
	ll na=(t/ra)-nab;
	ll nb=(t/rb)-nab;
	assert(nab+na+nb<=t);
	ll sum=(pa+pb)*query(0,nab-1)+pa*query(nab,nab+na-1)+pb*query(nab+na,nab+na+nb-1);
	return sum;
}

void go() {
	int n=rint();
	for (int i=0;i<n;i++) p[i]=rint()/100;
	sort(p,p+n,greater<ll>());
	sp[0]=0;
	for (int i=0;i<n;i++) {
		sp[i+1]=sp[i]+p[i];
	}
	pa=rint(); ra=rint();
	pb=rint(); rb=rint();
	if (pa<pb) {
		swap(pa,pb); swap(ra,rb);
	}
	
	ll k=rlong();
	int imin=0,imax=n+1;
	while(imin<imax) {
		int imid=(imin+imax)/2;
		//printf("imid: %d\n",imid);
		if (f(imid)<k) imin=imid+1;
		else imax=imid;
	}
	if (imin>n) imin=-1;
	printf("%d\n",imin);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int q=rint();
  for (int i=0;i<q;i++) go();
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