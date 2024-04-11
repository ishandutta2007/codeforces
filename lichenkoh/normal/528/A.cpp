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
typedef pair<int,int> pii;
set<int, greater<int> > s[2];
set<pii, greater<pii> > p[2];
const int maxn=2e5+4;
int v[2][maxn];
const int X=0,Y=1;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int w,h,n; scanf("%d %d %d\n",&w,&h,&n);
	s[X].insert(0);
	p[X].insert(MP(w,0));
	v[X][0]=w;

	s[Y].insert(0);
	p[Y].insert(MP(h,0));
	v[Y][0]=h;

	for (int q=0;q<n;q++) {
		char c; int coord;
		scanf("%c %d\n",&c,&coord);
		int t=(c=='H')?Y:X;
		int ry=coord;
		auto it=s[t].lower_bound(ry);
		int ly=*it;
		int lh=v[t][ly];
		p[t].erase(MP(lh,ly));
		int newlh=ry-ly;
		int newrh=lh-newlh;
		v[t][ly]=newlh;
		v[t][ry]=newrh;
		p[t].insert(MP(newlh,ly));
		p[t].insert(MP(newrh,ry));
		s[t].insert(ry);
		long long ans=((long long)(p[0].begin()->fst) * p[1].begin()->fst);
		printf("%lld\n",ans);
	}
}