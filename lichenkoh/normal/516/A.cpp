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
const int ma=15*8+1;
const int mb=15*3+1;
const int mc=15*1+1;
const int md=15*1+1;
vector<int> dp[ma][mb][mc][md];
int fac[10][4];
vector<int> f(int a, int b, int c, int d) {
	if (a+b+c+d==0) return {};
	if (dp[a][b][c][d].size()!=0) return dp[a][b][c][d];
	int oa=a,ob=b,oc=c,od=d;
	vector<int> vans={-1};
	for (int k=2;k<=9;k++) {
		a-=fac[k][0];
		b-=fac[k][1];
		c-=fac[k][2];
		d-=fac[k][3];
		if (a>=0&&b>=0&&c>=0&&d>=0) {
			auto got=f(a,b,c,d);
			if (!(got.size()==1&&got[0]==-1)) {
				got.PB(k);
				sort(got.begin(),got.end(),greater<int>());
				if (got.size()>vans.size()) vans=got;
				else if (got.size()==vans.size()&&got>vans) vans=got;
			}
		}
	}
	//printf("%d %d %d %d:",oa,ob,oc,od);
	//for (auto &w:vans) printf("%d",w);
	//printf("\n");
	return dp[oa][ob][oc][od]=vans;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; string s; cin>>n>>s;
	for (int x=2;x<=9;x++) {
		int a=0,b=0,c=0,d=0;
		{
			int z=x;
			while(z%2==0) {a++; z/=2;}
			while(z%3==0) {b++; z/=3;}
			while(z%5==0) {c++; z/=5;}
			while(z%7==0) {d++; z/=7;}
		}
		fac[x][0]=a;
		fac[x][1]=b;
		fac[x][2]=c;
		fac[x][3]=d;
		//printf("x:%d. %d %d %d %d\n",x,a,b,c,d);
	}
	{
		int a=0,b=0,c=0,d=0;
		for (auto &dig:s) {
			int x=dig-'0';
			for (int y=2;y<=x;y++) {
				a+=fac[y][0];
				b+=fac[y][1];
				c+=fac[y][2];
				d+=fac[y][3];
			}
		}
		vector<int> ans=f(a,b,c,d);
		for (auto &w:ans) printf("%d",w);
		printf("\n");
	}
}