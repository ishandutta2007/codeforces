#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include <assert.h>
extern "C" {
#include <quadmath.h>
}
using namespace std;
typedef long long ll;
using ld=__float128;
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}


struct mint {
  unsigned x;
  inline int _norm(int x) {
    if (x<0) x+=MOD;
    return x;
  }
  mint() : x(0) {}
  mint(signed sig) {sig=_norm(sig); x=sig;}
  mint(signed long long sig) {sig=_norm(sig%MOD); x=sig;}
  int get() const { return (int)x; }
 
  mint &operator+=(mint that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  mint &operator-=(mint that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  mint &operator*=(mint that) { x = ((unsigned long long)x * that.x) % MOD; return *this; }
  mint &operator/=(mint that) { return *this *= that.inverse(); }

  mint &operator+=(int that) {that=_norm(that); if((x += that) >= MOD) x -= MOD; return *this; }
  mint &operator-=(int that) {that=_norm(that); if((x += MOD - that) >= MOD) x -= MOD; return *this; }
  mint &operator*=(int that) {that=_norm(that); x = ((unsigned long long)x * that) % MOD; return *this; }
  mint &operator/=(int that) {that=_norm(that); return *this *= mint(that).inverse(); }

  mint operator+(mint that) const { return mint(*this) += that; }
  mint operator-(mint that) const { return mint(*this) -= that; }
  mint operator*(mint that) const { return mint(*this) *= that; }
  mint operator/(mint that) const { return mint(*this) /= that; }

  mint operator+(int that) const { return mint(*this) += that; }
  mint operator-(int that) const { return mint(*this) -= that; }
  mint operator*(int that) const { return mint(*this) *= that; }
  mint operator/(int that) const { return mint(*this) /= that; }


  mint inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while(b) {
      signed t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += MOD;
    mint res; res.x = (unsigned)u;
    return res;
  }
 
  bool operator==(mint that) const { return x == that.x; }
  bool operator!=(mint that) const { return x != that.x; }
  mint operator-() const { mint t; t.x = x == 0 ? 0 : MOD - x; return t; }
  mint operator^(unsigned long long k) const {
    // 0^0 is 1. k must be taken modulo phi(MOD) (MOD-1 if prime) and NOT MOD itself
    mint a=(*this);
    mint r = 1;
    while(k) {
      if(k & 1) r *= a;
      a *= a;
      k >>= 1;
    }
    return r;
  }
};



const int mn=(1e6)+2;
int p[mn];
int getlo2(int x) {
	int mod=x%3;
	if (mod==0) return 0;
	else return 3-mod;
}
pii getOptimal23(int x) {
	int e2=getlo2(x);
	int e3=(x-e2*2)/3;
	return MP(e2,e3);
}

enum {
	NONE,
	c11,
	begin4,
	c01,
	c22,
	c1111,
	end4,
	MODEMAX
};

// !!!! Bruteforce which cycle to remove 4 from
int solvecyc(vi & cyc) {
	int origcost=0;
	vi origh(5);
	for (int len: cyc) {
		int take3=len/3,rem3=len%3;
		if (rem3==1 && take3>=1) {
			take3--; rem3=4;
		}
		origcost+=take3-(rem3==0);
		origh[rem3]++;
	}
	//printf("origcost:%d h[0]:%d h[1]:%d h[2]:%d h[4]:%d\n",origcost,origh[0],origh[1],origh[2],origh[4]);
	int ans=INT_MAX;
	for (int mode=0;mode<MODEMAX;mode++) {
		vi h=origh;
		int cost=origcost;
		if (mode==c01) {
			if (h[0]&&h[1]) {h[0]--; h[1]--; h[4]++; cost++;} else continue;
		} else if (mode==c22) {
			if (h[2]>=2) {h[2]-=2; h[4]++; cost++;} else continue;
		} else if (mode==c11) {
			if (h[1]>=2) {h[1]-=2; h[2]++; cost++;} else continue;
		} else if (mode==c1111) {
			if (h[1]>=4) {h[1]-=4; h[4]++; cost+=2;} else continue;
		}
		//if(mode==c1111) printf("Stage A cost so far:%d h[1]:%d h[2]:%d\n",cost,h[1],h[2]);

		bool has4=false;
		if (begin4<=mode&&mode<=end4) {
			if (h[4]>0) {h[4]--; has4=true;} else continue;
		}
		cost+=h[4];
		h[1]+=h[4];
		h[4]=0;
		// Combine 1 with 2
		int take12=min(h[1],h[2]);
		h[1]-=take12; h[2]-=take12;
		if (h[1]) assert(h[2]==0);
		if (h[2]) assert(h[1]==0);

		cost+=take12;
		// Combine 2,2,2 => 6 => 3,3
		cost+=3*(h[2]/3); h[2]%=3;
		// Combine 1,1,1
		cost+=2*(h[1]/3); h[1]%=3;
		//if(mode==c1111) printf("cost so far:%d h[1]:%d h[2]:%d\n",cost,h[1],h[2]);
		if (h[1]) assert(h[2]==0);
		if (h[2]) assert(h[1]==0);
		if (has4) {
			if (h[1]+h[2]==0) chkmin(ans,cost);
		}
		else if (h[1]==1) {
			// We cannot just use a lone 1. It must be a 4.
		}
		else if (h[1]==2) {
			// If leftover 1,1, then forced to combine
			// Could we have achieved h[2]==1 instead?
			// ie. In take12 step, we can choose to decrement take12
			// save12 will handle this
			cost++;
			chkmin(ans,cost);
		} else if (h[2]==2) {
			chkmin(ans,cost);
		} else if (h[2]==1 || h[1]+h[2]==0) {
			// No action needed
			chkmin(ans,cost);
		} else {
			// Not valid solution
			assert(0);
		}
	}
	assert(ans<INT_MAX/2);
	return ans;
}

void go() {
	int n=rint();
	for (int x=1;x<=n;x++) p[x]=rint();
	pii e=getOptimal23(n);
	vi cyc; cyc.reserve(n);
	for (int init=1;init<=n;init++) {
		if (p[init]==-1) continue;
		int len=1;
		int x=p[init];
		p[init]=-1;
		while(x!=init) {
			int newx=p[x];
			p[x]=-1;
			x=newx;
			len++;
		}
		cyc.PB(len);
	}

	mint valmod=(mint(2)^e.fst)*(mint(3)^e.snd);
	int final=solvecyc(cyc);
	printf("%d %d\n",valmod.get(),final);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t=rint();
  for (int i=0;i<t;i++) go();
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