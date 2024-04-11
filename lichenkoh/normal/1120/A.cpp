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

const int mn=(5e5)+4;
int b[mn],c[mn],a[mn]; bool f[mn];

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int m,k,_n,s; cin>>m>>k>>_n>>s;
  for (int i=0;i<m;i++) cin>>a[i];
  int extra=m-k*_n;
  for (int i=0;i<s;i++) {
  	int x; cin>>x; ++b[x];
  }
  int req=0;
  for (int x=0;x<mn;x++) if (b[x]>0) req++;
  int has=0;
	int L=0;
  for (int R=0;R<m;R++) {
  	{
  		int x=a[R];
  		if (b[x]>0) {
  			++c[x];
  			if (c[x]==b[x]) ++has;
  		}
  	}
  	while(L<R) {
  		int x=a[L];
  		if (b[x]>0) {
  			if (c[x]<=b[x]) break;
  			--c[x];
  		}
  		++L;
  	}
  	//printf("has:%d req:%d L:%d R:%d\n",has,req,L,R);
  	assert(has<=req);
  	int innerrm=R-L+1 - k;
  	int outerrm=L%k;
  	if (has==req && innerrm+outerrm<=extra) {
  		if (innerrm<0) {outerrm+=innerrm; innerrm=0;}
  		chkmax(outerrm,0);
  		//printf("innerrm:%d outerrm:%d e:%d\n",innerrm,outerrm,extra);
  		memset(c,0,sizeof c);
  		for (int q=L;q<=R;q++) {
  			int x=a[q];
  			if (b[x]>0) {
  				++c[x];
  				if (c[x]<=b[x]) {
  					f[q]=true; //printf("Need:%d\n",q);
  				}
  			}
  		}
  		vi vans;
  		for (int q=0;q<outerrm;q++) {
  			vans.PB(q);
  			//printf("outer:%d\n",q);
  		}
  		for (int q=L;q<=R;q++) {
  			if (innerrm==0) break;
  			if (!f[q]) {
  				vans.PB(q); innerrm--;
  			}
  		}
  		int sz=vans.size();
  		//assert(sz<=extra);
  		//assert(sz==innerrm+outerrm);
  		printf("%d\n",((int)vans.size()));
  		for (auto &w:vans) printf("%d ",w+1);
  		printf("\n"); exit(0);
  	}

  }
  printf("-1\n");
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