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

int n; ll k;
int a[104];
int f[104];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=rint();k=rlong();
	for (int i=0;i<n;i++) a[i]=rint();
	sort(a,a+n);
	ll suma=0;
	for (int i=0;i<n;i++) suma+=a[i];
	ll gota=(k+suma)/n;
	ll final=-1;
	if (gota>=a[n-1]) final=gota;
	int slim=ceil(sqrt(a[n-1])*4)+1;
	while(slim*slim<=a[n-1]) slim++;
	int s=slim;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	ll gsum=0;
	int contrib=0;
	for (int i=0;i<n;i++) {
		f[i]=(a[i]+s-1)/s;
		contrib+=f[i];
		int rem=f[i]*s-a[i];
		gsum+=rem;
		if (f[i]>1) {
			int leeway=s+((s-rem+f[i]-2)/(f[i]-1));
			//printf("s:%d a[i]:%d leeway:%d rem:%d f:%d\n",s,a[i],leeway,rem,f[i]); fflush(stdout);
			pq.push(MP(leeway,i));
		}
	}

	while(!pq.empty()) {
		if (s>a[n-1]) break;
		while(!pq.empty()) {
			auto got=pq.top();
			if (got.fst>s) break;
			pq.pop();
			int i=got.snd;
			int oldrem=f[i]*s-a[i];
			int oldf=f[i];
			f[i]=(a[i]+s-1)/s;
			contrib+=f[i]-oldf;
			int rem=f[i]*s-a[i];
			gsum+=rem-oldrem;
			if (f[i]>1) {
				int leeway=s+((s-rem+f[i]-2)/(f[i]-1));
				//printf("s:%d a[i]:%d leeway:%d rem:%d f:%d\n",s,a[i],leeway,rem,f[i]); fflush(stdout);
				pq.push(MP(leeway,i));
			}
		}
		if (pq.empty()) break;
		int ns=pq.top().fst;
		int minleeway=ns-s;
		chkmax(minleeway,0);
		int gomax=(k-gsum)/contrib;
		if (gomax>=0) {
			int cango=min(gomax,minleeway);
			if (gsum+(cango*(ll)contrib)<=k) chkmax(final,(ll)(s+cango));
		}
		if (s==ns) break;
		//printf("s:%d ns:%d\n",s,ns);
		int ds=ns-s;
		gsum+=ds*(ll)contrib;
		s=ns;
		//printf("s:%lld minleeway:%lld cango:%lld gomax:%lld\n",s,minleeway,cango,gomax); fflush(stdout);
	}
	for (int d=slim-1;d>=1;d--) {
		if (final>=d) {
			printf("%lld\n",final);
			return 0;
		}
		ll sum=0;
		for (int i=0;i<n;i++) {
			int rem=a[i]%d;
			if (rem>0) sum+=d-rem;
		}
		if (sum<=k) {
			printf("%d\n",d);
			return 0;
		}
	}
}