#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
//template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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

static const int buf_len = (1 << 14), buf_max = (1 << 04);
static char buf_out[buf_len], buf_num[buf_max];
static int buf_pos = 0;

inline void writeChar(int x){if(buf_pos==buf_len)fwrite(buf_out,1,buf_len,stdout),buf_pos=0;buf_out[buf_pos++]=x;}
inline void writeInt(int x,char end=0){if(x<0)writeChar('-'),x=-x;int n=0;do{buf_num[n++]=x%10+'0';}while(x/=10);while(n--)writeChar(buf_num[n]);if(end)writeChar(end);}
struct Flusher{~Flusher(){if(buf_pos)fwrite(buf_out, 1, buf_pos, stdout),buf_pos=0;}}flusher;


const int mq=10;
const int mn=1500;
const int mt=10;
int n,q;

int tmp[mq*2];
struct S {
	int sz=0;
	int a[mq];
	void addS(S const& s) {
		if (sz>mq) return;
		if (s.sz>mq) {sz=INF; return;}
		int si=0,ai=0,ti=0;
		int last=-1;
		while(si<s.sz&&ai<sz) {
			int x;
			int L=s.a[si],R=a[ai];
			if (L<R) {
				x=L; si++;
			} else {
				x=R; ai++;
			}
			if (last!=x) {
				last=x;
				tmp[ti++]=x;
			}
		}
		if (si<s.sz) {
			if (last==s.a[si]) si++;
			while(si<s.sz) {
				int x=s.a[si++];
				tmp[ti++]=x;
			}
		}
		if (ai<sz) {
			if (last==a[ai]) ai++;
			while(ai<sz) {
				int x=a[ai++];
				tmp[ti++]=x;
			}
		}
		if (ti>mq) {sz=INF;return;}
		for (int i=0;i<ti;i++) a[i]=tmp[i];
		sz=ti;
	}
	void uni() {
		sort(a,a+sz);
		sz = unique(a,a+sz) - a;
	}
};

int b[mn][mn];
S f[2][mn][mn];
void init1() {
	int t=0;
	for (int x=0;x<n-1;x++) for (int y=0;y<n-1;y++) {
		S & s=f[1][x][y];
		for (int z=0;z<4;z++) {
			s.a[z]=b[x+(z&1)][y+((z>>1)&1)];
		}
		s.sz=4;
		s.uni();
	}
}
void trans(int t, int in, int out) {
	int k=1<<(t-1);
	for (int sx=0;sx<=n-k*2;sx++) for (int sy=0;sy<=n-k*2;sy++) {
		S & res=f[out][sx][sy]; res.sz=0;
		for (int i=0;i<2;i++) for (int j=0;j<2;j++) {
			int x=sx+k*i,y=sy+k*j;
			S & src=f[in][x][y];
			res.addS(src);
		}
	}
}

int ilog2(int x) {
	return 31-__builtin_clz(x);
}
bool can(int in, int sx, int sy, int k) {
	if (k==1) return true;
	int t=ilog2(k);
	assert(t>0);
	int len=1<<t;
	S d;
	for (int i=0;i<2;i++) for (int j=0;j<2;j++) {
		int x=min(sx+len*i, sx+k-len),y=min(sy+len*j, sy+k-len);
		S & src=f[in][x][y];
		d.addS(src);
		if (d.sz>q) return false;
	}
	return true;
}
int gethi(int sx,int sy) {
	return min(n-sx,n-sy);
}
int getk(int in, int sx, int sy, int lo, int hi) {
	chkmin(hi,gethi(sx,sy));
	if (lo>hi) return -1;
	int imin=lo,imax=hi+1;
	while(imin<imax) {
		int imid=(imin+imax)/2;
		if (can(in,sx,sy,imid)) imin=imid+1;
		else imax=imid;
	}
	return imin-1;
}


int pre[mn+1];
int vans[mn][mn];

void go(int t, int x, int y) {
	int lo=1<<t,hi=(1<<(t+1))-1;
	int k=getk(t&1,x,y,lo,hi);
	chkmax(vans[x][y],k);
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();q=rint();
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) b[x][y]=rint();
  init1();
	for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
		if (gethi(x,y) <=1 || f[1][x][y].sz > q) vans[x][y]=1;
	}
	for (int t=2;t<=mt;t++) {
		trans(t,(t&1)^1,t&1);
		for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
			if (vans[x][y]==0 && (gethi(x,y) <(1<<t) || f[t&1][x][y].sz>q)) {
				go(t-1,x,y);
			}
		}
	}
	for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
		if (vans[x][y]==0) {
			assert(gethi(x,y)>= (1<<mt));
			go(mt,x,y);
		}
	}
	for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
		int k=vans[x][y];
		assert(k>0);
		pre[k]++;
	}
	for (int i=n-1;i>=0;i--) {
		pre[i]+=pre[i+1];
	}
	for (int i=1;i<=n;i++) writeInt(pre[i],'\n');
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