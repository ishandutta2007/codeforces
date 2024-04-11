#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
#define fst first
#define snd second
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
const int MOD=1000000007;
int extgcd(int a, int b, int& x, int& y) { for (int u = y = 1, v = x = 0; a;) { int q = b / a; swap(x -= q *(ll) u, u); swap(y -= q *(ll) v, v); swap(b -= q *(ll) a, a); } return b; }
int mod_inv(int a, int m) { int x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
const int mk=101;
const int mn=200000+4;
int vsegl[mk],vsegr[mk];

template<typename T> class SlidingWindowMinimum {
public:
  int id=0;
  std::deque< std::pair<T, int> > window;
  int K;
  void rst(int k) {K=k; id=0; window.clear();}
  void add(T val) {
     while (!window.empty() && window.back().first >= val) {window.pop_back();}
     window.push_back(std::make_pair(val, id));
     while(window.front().second <= id - K) {window.pop_front();}
     ++id;
  }
  T query() {
    return window.front().first;
  }
};

SlidingWindowMinimum<char> SW;

char f[2][2][mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint()*2,k=rint();
  for (int i=0;i<k;i++) {
    vsegl[i]=rint()*2;vsegr[i]=rint()*2;
  }
  //vsegl[k]=n; vsegr[k]=n;
  memset(f[0],0x7c,sizeof(f[0]));
  f[0][0][0]=0;
  int lastr=0;
  for (int i=0;i<k;i++) {
  	int cur=i&1; int nxt=cur^1;
    int sl=vsegl[i],sr=vsegr[i];
    int gap=sl-lastr;
    lastr=sr;
    int trans=sr-sl;
    //printf("gap:%d trans:%d n:%d\n",gap,trans,n);
    {
    	memcpy(f[nxt][0], f[cur][0], sizeof(f[0][0]));
    	int inc=gap+trans;
    	if (inc<=n) {
    		memset(f[nxt][1], 0x7c, inc);
    		memcpy(f[nxt][1]+inc, f[cur][1], sizeof(f[0][0])-inc);
    	}
    	else {
    		memset(f[nxt][1], 0x7c, sizeof f[0][0]);
    	}
    }
    { // 0->1 means you can get 0...trans
    	SW.rst(trans+1);
    	for (int x=0;x<=n;x++) {
    		SW.add(f[cur][0][x]);
    		char ans=SW.query();
    		if (ans<0x7c) {
    			chkmin(f[nxt][0][x],(char)(ans+2));
    			chkmin(f[nxt][1][x],(char)(ans+1));
    		}
    	}
    }
    { // 1->0 means you can get gap...gap+trans
    	SW.rst(trans+1);
    	for (int x=0;x<=n-gap;x++) {
    		SW.add(f[cur][1][x]);
    		char ans=SW.query();
    		if (ans<0x7c) {
    			chkmin(f[nxt][0][x+gap],(char)(ans+1));
    			chkmin(f[nxt][1][x+gap],(char)(ans+2));
    		}
    	}
    }
    /*for (int t=0;t<2;t++) {
    	for (int x=0;x<=n;x++) {
    		printf("%d ",f[nxt][t][x]);
    	}
    	printf("\n");
    }
    printf("\n");*/
  }
  char ans=f[k&1][0][n];
  if (lastr-n>=0) chkmin(ans,f[k&1][1][lastr-n]);
  if (ans<0x7c) {
  	printf("Full\n%d\n",(int)ans);
  }
  else {
  	printf("Hungry\n");
  }
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