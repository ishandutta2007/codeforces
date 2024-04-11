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
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

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

typedef pair<ll,ll> pll;
typedef vector<ll> vll;
int has[1001];
vll v;
const int mt=2002;
ll dist[mt+mt+2];
int main()
{
	int n=readInt();
	int k=readInt();
	for (int i=0;i<k;i++) {
		int x=readInt();
		has[x]=true;
	}
	bool lower=0,higher=0;
	for (int x=0;x<=1000;x++) {
		if (has[x]) {
			if (x>n)higher=true;
			if (x<n) lower=true;
			int y=x-n;
			v.PB(y);
			if (x==n) {
				printf("1\n"); return 0;
			}
		}
	}
	if (!(lower&&higher)) {
		printf("-1\n");
		return 0;
	}
	for (ll t=-mt;t<=mt;t++) {
		dist[mt+t]=INF;
	}
	queue<ll> q;
	for (auto &y:v) {
		q.push(y);
		dist[mt+y]=1;
	}
	while(!q.empty()) {
		ll x=q.front(); q.pop();
		if (x==0) {
			printf("%d\n",dist[mt+x]);
			return 0;
		}
		ll newdist=dist[mt+x]+1;
		for (auto &add:v) {
			ll y=x+add;
			if (-mt<=y&&y<=mt&&dist[mt+y]==INF) {
				dist[mt+y]=newdist;
				q.push(y);
			}
		}
	}
	printf("-1\n");
}