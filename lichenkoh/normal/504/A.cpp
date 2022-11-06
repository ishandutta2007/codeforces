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
const int mn=(1<<16)+2;
int deg[mn],s[mn];
bitset<mn> done;
vector<int> g[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
	for (int i=0;i<n;i++) {
		deg[i]=readInt(),s[i]=readInt();
	}
	queue<int> vone;
	for (int i=0;i<n;i++) {
		if (deg[i]==1) vone.push(i);
		if (deg[i]==0) done[i]=1;
	}
	while(!vone.empty()) {
		int x=vone.front(); vone.pop();
		if (done[x]) continue;
		int y=s[x];
		g[x].PB(y);
		g[y].PB(x);
		s[x]^=y;
		s[y]^=x;
		deg[x]--;
		deg[y]--;
		if (deg[x]==0) done[x]=1;
		if (deg[y]==0) done[y]=1;
		if (deg[y]==1 && !done[y]) vone.push(y);
	}
	int m=0; for (int x=0;x<n;x++) for (auto &y:g[x]) if (x>y) m++;
	printf("%d\n",m);
	for (int x=0;x<n;x++) for (auto &y:g[x]) if (x>y) printf("%d %d\n",x,y);
}