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
bool bf(ll a, ll b) {
	for (ll ax=-a+1;ax<=a-1;ax++) for (ll ay=-a+1;ay<=a-1;ay++)
	for (ll bx=-b+1;bx<=b-1;bx++) for (ll by=-b+1;by<=b-1;by++) {
		if (ax*ax+ay*ay==a*a&&bx*bx+by*by==b*b&&ax*bx+ay*by==0) return true;
	}
	return false;
}
bool solve(ll a, ll b) {
	ll a2=a*a,b2=b*b;
	for (ll ax=1;ax<a;ax++) {
		ll ay=round(sqrt(a2-ax*ax));
		if (ax*ax+ay*ay==a2) {
			for (ll bx=1;bx<b;bx++) {
				ll by=-round(sqrt(b2-bx*bx));
				if (bx*bx+by*by==b2 && ax!=bx && ay!=by) {
					ll dot=ax*bx+ay*by;
					if (dot==0) {
						printf("YES\n0 0\n%lld %lld\n%lld %lld\n",ax,ay,bx,by);
						return true;
					}
				}
			}
		}
	}
	printf("NO\n");
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a,b; cin>>a>>b; solve(a,b);
	//for (ll a=1;a<=10;a++) for (ll b=1;b<=10;b++) {
	//	if(solve(a,b)!=bf(a,b)) {
	//		printf("%lld %lld. solve:%d bf:%d\n",a,b, solve(a,b), bf(a,b));
	//	}
	//}
}