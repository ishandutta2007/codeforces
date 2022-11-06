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
const int mn=1e5+4;

int va[mn],vl[mn],vr[mn];
ll vd[mn];
int vtmp[mn];
ll vt[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt(),k=readInt();
	for (int i=1;i<=n;i++) va[i]=readInt();
	for (int i=1;i<=m;i++) {
		vl[i]=readInt();vr[i]=readInt();vd[i]=readInt();
	}
	for (int i=1;i<=k;i++) {
		int x=readInt(),y=readInt();
		vtmp[x]++; vtmp[y+1]--;
	}
	for (int i=1;i<=m;i++) {
		vtmp[i]+=vtmp[i-1];
		vd[i]*=vtmp[i];
	}
	for (int i=1;i<=m;i++) {
		vt[vl[i]]+=vd[i];
		vt[vr[i]+1]-=vd[i];
	}
	for (int i=1;i<=n;i++) {
		vt[i]+=vt[i-1];
		ll ans=vt[i]+va[i];
		printf("%lld ",ans);
	}
	printf("\n");
}