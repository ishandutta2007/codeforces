#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=2004;
int a[mn];
int c[3][mn];
int query(int t, int l, int r) {
	if (l>r) return 0;
	if (l-1<0) return c[t][r];
	return c[t][r]-c[t][l-1];
}
int tmp[2][mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=1;i<=n;i++) {
  	a[i]=rint();
  }
  for (int i=1;i<=n;i++) {
  	c[a[i]][i]++;
  }
  for (int t=1;t<=2;t++) for (int i=1;i<=n;i++) {
  	c[t][i]+=c[t][i-1];
  }
  {
  	for (int r=0;r<=n;r++) {
  		int ans=0;
  		for (int x=0;x<=r;x++) {
  			chkmax(ans,query(1,1,x)+query(2,x+1,r));
  			//if (r==0) printf("x:%d. %d %d\n",x,query(1,1,x),query(2,x+1,r));
  		}
  		tmp[0][r]=ans;
  	}
  }
  {
  	for (int l=n+1;l>=1;l--) {
  		int ans=0;
  		for (int x=l-1;x<=n;x++) {
  			chkmax(ans,query(1,l,x)+query(2,x+1,n));
  		}
  		tmp[1][l]=ans;
  	}
  }
  int final=0;
  for (int r=0;r<=n;r++) {
  	int cand=tmp[0][r]+tmp[1][r+1];
  	//printf("r:%d cand:%d %d\n",r,tmp[0][r],tmp[1][r+1]);
  	chkmax(final,cand);
  }
  printf("%d\n",final);
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