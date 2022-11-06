#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif

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
//template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

const int mn=100000;
const int BLKSZ=sqrt(mn)/3;
const int NUMBLOCKS=(mn+BLKSZ-1)/BLKSZ;
vector<int> name2blk(mn);
vector<int> name2xpos(mn);
int val2s(int val) {
	return name2blk[val];
}

int ilog2(int n) {
	return 31-__builtin_clz(n);
}

struct Fenwick1D {
    vector<int> bit;  // binary indexed tree
    int n;
    int logn;
    void init(int _n) {
      n = _n;
      logn=ilog2(n);
      bit.resize(n);
    }

    //int sum(int r) {
    //  int ret = 0;
    //  for (; r >= 0; r = (r & (r + 1)) - 1) {
    //    ret += bit[r];
    //  }
    //  return ret;
    //}
    //int sum(int l, int r) {
    //  return sum(r) - sum(l - 1);
    //}

    void add(int _idx, int delta) {
      for (int idx=_idx; idx < n; idx = idx | (idx + 1)) {
        bit[idx] += delta;
      }
    }

    int atleast(int needsticks) {
    	int pre=0;
    	for (int k=logn;k>=0;k--) {
    		int askidx=pre + (1<<k) - 1;
    		if (askidx < n) {
    			int got = bit[askidx];
    			if (got < needsticks) {
    				needsticks -= got;
    				pre |= 1<<k;
    			}
    		}
    	}
    	return pre;
    }
};
Fenwick1D fen;

template<typename T> struct Prevec  {
  vector<T> a;
  int sz=0;
  void init(int newsz) {a.resize(newsz);}
  void push_back(T val) {a[sz++]=val;}
  T * begin() {return &a[0];}
  T * end() {return &a[sz];}
  T operator [](int i) const {return a[i];}
  T & operator [](int i) {return a[i];}
  int size() const {return sz;}
  void clear() {sz=0;}
  void resize(int newsz) {sz=newsz;}
};

Prevec<int> g[NUMBLOCKS];

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int x=1;x<NUMBLOCKS;x++) {
  	int init=x*BLKSZ;
  	int lim=min(mn,init+BLKSZ);
  	for (int y=init;y<lim;y++) {
  		name2blk[y]=x;
  	}
  }
  int n=rint();
	int blklim=name2blk[n-1]+1;
	fen.init(n);
	for (int x=0;x<n;x++) fen.add(x,1);
	for (int blk=0;blk<blklim;blk++) {
  	int ex=min(n,(blk+1)*BLKSZ)-1;
  	g[blk].init(ex+1);
	}
	vi vorder(n);
  for (int q=1;q<=n;q++) {
  	int name=q-1;
  	int order=q-1-rint();
  	vorder[name]=order;
  }
  int lastblk=-1;
  for (int name=n-1;name>=0;name--) {
  	int blk=name2blk[name];
  	if (blk!=lastblk && lastblk!=-1) {
  		for (auto &x:g[lastblk]) {
  			fen.add(x,1);
  		}
  	} 
  	int order=vorder[name];
  	int pos=fen.atleast(order+1);
  	fen.add(pos,-1);
  	g[blk].PB(pos);
  	name2xpos[name]=pos;
  	//printf("name:%d blk:%d pos:%d\n",name,blk,pos);
  	lastblk=blk;
  }
	for (auto &x:g[lastblk]) {
		fen.add(x,1);
	}
  for (int blk=0;blk<blklim;blk++) {
  	sort(g[blk].begin(),g[blk].end());
  }
  int numqueries=rint();
  for (int iq=0;iq<numqueries;iq++) {
  	int t=rint();
  	int q=rint();
  	int name=q-1;
		int myblk=name2blk[name];
		int blkend=min(n,(myblk+1) * BLKSZ) -1;
  	if (t==1) {
  		int neworder=q-1-rint();
  		g[myblk].clear();
  		vorder[name]=neworder;
  		int blkstart=myblk * BLKSZ;
			for (int x=blkend;x>=blkstart;x--) {
				int xpos = fen.atleast(vorder[x]+1);
				fen.add(xpos,-1);
				g[myblk].PB(xpos);
				name2xpos[x]=xpos;
			}
			for (auto &x:g[myblk]) {
				fen.add(x,1);
			}
			sort(g[myblk].begin(),g[myblk].end());
  	} else {
  		int mypos=name2xpos[name];
  		for (int blk=myblk+1;blk<blklim;blk++) {
  			//int nextpos=fen.atleast(mypos+1);
  			auto &v=g[blk];
  			int imin=0,imax=v.size();
  			while(imin<imax) {
  				int imid=(imin+imax)/2;
  				int ones=v[imid]+1-(imid+1);
  				//printf("imid:%d ones:%d\n",imid,ones);
  				if (ones<mypos+1) imin=imid+1;
  				else imax=imid;
  			}
  			int guess;
  			{
  				if (imin==0) {
  					guess=mypos;
  				} else {
  					int pos=v[imin-1];
  					int ones=pos+1-imin;
  					int rem=mypos+1-ones;
  					//printf("pos:%d ones:%d rem:%d\n",pos,ones,rem);
  					guess=pos+rem;
  				}
  			}
  			//for (auto &w:v) printf("%d ",w);
  			//printf(" end v\n guess:%d mypos:%d imin:%d\n",guess,mypos,imin);
  			//assert(guess==nextpos);
  			mypos=guess;
  		}
			int final=mypos;
  		printf("%d\n",final+1);
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
    char extra=*stdinPos;
    ++stdinPos;
    return extra;
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