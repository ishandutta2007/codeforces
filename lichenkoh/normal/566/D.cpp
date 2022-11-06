#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
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

const ll mn=2e5+1;
ll p[mn];
ll ffind(ll x) {
	if (p[x] != x) {
		p[x] = ffind(p[x]);
	}
	return p[x];
}
void funion(ll x, ll y) {
	if (rand()&1) swap(x,y); 
	ll xr = ffind(x);
	ll yr = ffind(y);
	p[xr] = yr;
}

int main() 
{
	ll n=readInt(),q=readInt();
	for (ll x=0;x<n;x++) p[x]=x;
	set<ll> s;
	for (ll x=0;x<n;x++) s.insert(x);
	for (ll i=0;i<q;i++) {
		ll type=readInt(),x=readInt(),y=readInt();
		--x; --y;
		if (type==1) {
			funion(x,y);
		}
		else if (type==2) {
			auto it=s.lower_bound(x);
			ll first=*it;
			for (; it!=s.end();) {
				ll z=*it;
				funion(first,z);
				if (z>=y) break;
				it=s.erase(it);
			}
		}
		else {
			ll tx=ffind(x),ty=ffind(y);
			if (tx==ty) {
				printf("YES\n");
			}
			else printf("NO\n");
		}

	}
}