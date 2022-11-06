#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=3e5+4;
int a[mn];
int c[mn];
int r[mn];
int f[mn]; // f[p] = last x st [x,p] is null
map<int,int> vh[mn];
void seth(int p, int l) {
	f[p]=l;
	r[p]=r[l-1];
	auto &h=vh[r[p]];
	int key=a[l-1];
	auto it=h.find(key);
	if (it==h.end()) {
		//printf("Insert key:%d val:%d\n",key,l);
		h[key]=l;
	} else {
		it->snd=max(it->snd,l);
	}
}
int geth(int p, int key) {
	auto &h=vh[r[p]];
	auto it=h.find(key);
	if (it==h.end()) return -INF;
	return it->snd;
}
void test() {
	int n=rint();
	for (int i=1;i<=n;i++) {a[i]=rint();}
	for (int i=0;i<=n;i++) {c[i]=0; r[i]=i;}
	for (int p=2;p<=n;p++) {
		//printf("\nStart process p:%d\n",p);
		if (a[p]==a[p-1]) {
			//printf("seth p:%d p-1:%d\n",p,p-1);
			seth(p,p-1);
		} else {
			f[p]=-INF;
			int x=geth(p-1,a[p]);
			//printf("geth p-1:%d a[p] key:%d gets x:%d\n",p-1,a[p],x);
			if (x>0) { // [x-1,p] is null
				//printf("seth p:%d x-1:%d\n",p,x-1);
				seth(p,x-1);
			}
		}
		if (f[p]>=0) {
			c[p]=c[f[p]-1]+1;
			//printf("p:%d f:%d c:%d cfp:%d\n",p,f[p],c[p],c[f[p]-1]);
		}
		//printf("p:%d f:%d c:%d\n",p,f[p],c[p]);
	}
	ll ans=0;
	for (int p=1;p<=n;p++) {
		ans+=c[p];
	}
	/*for (int p=0;p<=n;p++) {
		printf("p:%d r[p]:%d\n",p,r[p]);
	}*/
	printf("%lld\n",ans);
	for (int p=0;p<=n;p++) vh[p].clear();
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int q=rint();
  for (int i=0;i<q;i++) test();
}




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