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

const int mn=5002;
const int mx=1000*1000*1000;
int h[mn];
int sd[mn];
int vans[mn];
int vt[mn],vl[mn],vr[mn],vdm[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
	for (int x=1;x<=n;x++) h[x]=mx;
	for (int i=0;i<m;i++) {
		int t=rint(),l=rint(),r=rint(),dm=rint();
		vt[i]=t,vl[i]=l,vr[i]=r,vdm[i]=dm;
		if (t==1) {
			for (int x=l;x<=r;x++) sd[x]+=dm;
		}
		else {
			for (int x=l;x<=r;x++) chkmin(h[x], dm-sd[x]);
		}
	}
	memcpy(vans,h,sizeof(h));
	memset(sd,0,sizeof sd);
	for (int i=0;i<m;i++) {
		int t=vt[i],l=vl[i],r=vr[i],dm=vdm[i];
		if (t==1) {
			for (int x=l;x<=r;x++) sd[x]+=dm;
		}
		else {
			int hi=-mx;
			for (int x=l;x<=r;x++) chkmax(hi, sd[x]+vans[x]);
			if (hi!=dm) {
				printf("NO\n"); return 0;
			}
		}
	}
	printf("YES\n");
	for (int x=1;x<=n;x++) printf("%d ",vans[x]);
	printf("\n");
}