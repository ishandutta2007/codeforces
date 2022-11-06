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
bool kc[5],kd[5];
bool a[5][5];
int MAP[128];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	{
		int k=0;
		MAP['R']=k++;
		MAP['G']=k++;
		MAP['B']=k++;
		MAP['Y']=k++;
		MAP['W']=k++;
	}
	int n; scanf("%d\n",&n);
	vector<pair<int,int> >v;
	for (int i=0;i<n;i++) {
		char c; int d;
		if (i!=n-1) scanf("%c%d ",&c,&d);
		else scanf("%c%d",&c,&d);
		int _c=MAP[c];
		int _d=d-1;
		if (!a[_c][_d]) {
			a[_c][_d]=1;
			v.PB(MP(_c,_d));
		}
	}
	int zlim=1<<10;
	int ans=1e9;
	for (int z=0;z<zlim;z++) {
		for (int i=0;i<5;i++) {
			if ((1<<i)&z) kc[i]=1;
			else kc[i]=0;
		}
		for (int i=5;i<10;i++) {
			if ((1<<i)&z) kd[i-5]=1;
			else kd[i-5]=0;
		}
		bool ok=1;
		for (auto &x:v) for (auto &y:v) {
			if (x==y) continue;
			bool dist=0;
			if (x.fst!=y.fst&&(kc[x.fst]||kc[y.fst])) dist=1;
			if (x.snd!=y.snd&&(kd[x.snd]||kd[y.snd])) dist=1;
			if (dist==0) {ok=0; break;}
		}
		if (ok) chkmin(ans,__builtin_popcount(z));
	}
	printf("%d\n",ans);
}