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

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t; scanf("%lld",&t);
	for (ll i=0;i<t;i++) {
		ll x,y,p,q; scanf("%lld%lld%lld%lld",&x,&y,&p,&q);
		if (x!=y && p==q) {
			printf("-1\n");
		}
		else if (x==y&&p==q) {
			printf("0\n");
		}
		else if (p==0) {
			if (x==0) {
				printf("0\n");
			}
			else {
				printf("-1\n");
			}
		}
		else {
			ll k=max((x+p-1)/p,(y+q-1)/q);
			ll a=k*p-x;
			ll b=k*q-y;
			//printf("k:%lld x:%lld y:%lld p:%lld q:%lld a:%lld b:%lld\n",k,x,y,p,q,a,b);
			if (a>b) {
				ll diff=a-b;
				ll step=q-p;
				ll inc=(diff+step-1)/step;
				k+=inc;
			}
			ll ans=k*q-y;
			//assert((k*p-x)>=0);
			//assert((k*q-y)>=(k*p-x));
			//--k;
			//assert(!((k*p-x)>=0&&((k*q-y)>=(k*p-x))));
			printf("%lld\n",ans);
		}
	}
}