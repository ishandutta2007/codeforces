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
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
typedef unsigned long long ull;
struct Node{
	int val;
	ull sig1,sig2;
	bool t;
  Node(int val,ull sig1,ull sig2, bool t): val(val),sig1(sig1),sig2(sig2),t(t) {}
  Node() {}
  bool operator < (Node b)const{
    return val<b.val;
  }
};

vector<Node> gv;
int p;
void go(int s, bool t) {
	mt19937 rng(clock());
	for (int k=0;k<50000;k++) {
		if (0==(k&0xff)) rng.seed(clock()^rng());
		ull sig1=((ull)rng())<<32|(ull)rng();
		ull sig2=((ull)rng())<<32|(ull)rng();
		int x=s;
		for (int i=0;i<32;i++) {
			int got=(sig1>>(2*i))&0x3;
			if (got==2) {--x; if (x<0) x+=p;}
			else if (got==3) {x=mod_pow(x,p-2,p);}
			else {++x; if (x>=p) x-=p;}
		}
		for (int i=0;i<32;i++) {
			int got=(sig2>>(2*i))&0x3;
			if (got==2) {--x; if (x<0) x+=p;}
			else if (got==3) {x=mod_pow(x,p-2,p);}
			else {++x; if (x>=p) x-=p;}
		}
		gv.PB(Node(x,sig1,sig2,t));
	}
}
Node last[2];
int mm[4];
vector<int> vans;
vector<int> vrev;
int gs,gt;
void out(vector<int> v) {
	for (auto &w:v) {
		printf("%d\n",w);
		if (w==1) {++gs; if (gs>=p) gs-=p;}
		else if (w==2) {--gs; if (gs<0) gs+=p;}
		else gs=mod_pow(gs,p-2,p);
	}
}
void rev(vector<int> v) {
	reverse(v.begin(),v.end());
	for (auto &w:v) {
		if (w==1) w=2;
		else if (w==2) w=1;
		printf("%d\n",w);
		if (w==1) {++gs; if (gs>=p) gs-=p;}
		else if (w==2) {--gs; if (gs<0) gs+=p;}
		else gs=mod_pow(gs,p-2,p);
	}
}
int main() 
{
	mm[0]=mm[1]=1;
	mm[2]=2;
	mm[3]=3;
  ios_base::sync_with_stdio(false); cin.tie(0);
	int s=rint(),target=rint(); p=rint();
	gs=s;gt=target;
	while(1) {
		gv.reserve(50000*2);
		go(s,false);
		go(target,true);
		sort(gv.begin(),gv.end());
		for (int t=0;t<2;t++) last[t]=Node(INT_MIN,-1,-1,t);
		for (int b=0;b<2;b++) {
			for (auto &w:gv) {
				if (b) w.val+=p;
				chkmax(last[w.t],w);
				auto &l=last[w.t^1];
				if (l.val!=INT_MIN) {
					int diff=w.val-l.val;
					if (diff<=200-64*2) {
						for (int i=0;i<32;i++) {
							int got=(l.sig1>>(2*i))&0x3;
							vans.PB(mm[got]);
						}
						for (int i=0;i<32;i++) {
							int got=(l.sig2>>(2*i))&0x3;
							vans.PB(mm[got]);
						}
						for (int i=0;i<diff;i++) vans.PB(1);
						for (int i=0;i<32;i++) {
							int got=(w.sig1>>(2*i))&0x3;
							vrev.PB(mm[got]);
						}
						for (int i=0;i<32;i++) {
							int got=(w.sig2>>(2*i))&0x3;
							vrev.PB(mm[got]);
						}
						printf("%d\n",(int)(vans.size()+vrev.size()));
						if (w.t) {
							out(vans);
							rev(vrev);
						}
						else {
							out(vrev);
							rev(vans);
						}
						assert(gs==gt);
						exit(0);
					}
				}
			}
		}
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