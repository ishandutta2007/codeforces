#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=777777777;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int MAXSEG = 77777+4;  // limit for array size
int segn;  // array size
const int mk=3;
typedef struct {
	int a[mk][mk];
} S;
S t[2 * MAXSEG];
S identity;
S combine(const S& lefts, const S& rights) {
	S res;
	for (int i=0;i<mk;i++) {
		for (int j=0;j<mk;j++) {
			ll ans=0;
			for (int k=0;k<mk;k++) {
				ans+=lefts.a[i][k]*(ll)rights.a[k][j];
			}
			res.a[i][j]=ans%MOD;
		}
	}
	return res;
}
void build() {  // build the tree
	int n=segn;
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}

void modify(int p, const S& value) { // set value at position p
	int n=segn;
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

S query(int l, int r) { // sum on interval [l, r]
	r++;
	int n=segn;
  S resl=identity, resr=identity;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}

S mat[4];

void printmat(S got) {
		for (int x=0;x<mk;x++) {
			for (int y=0;y<mk;y++) {
				printf("%d ",got.a[x][y]);
			}
			printf("\n");
		}
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int x=0;x<=2;x++) {
  	for (int y=0;y<=2;y++) {
  		mat[0].a[x][y]=rint();
  	}
  }
  for (int k=0;k<mk;k++) identity.a[k][k]=1;
  for (int t=1;t<=3;t++) {
  	for (int y=0;y<=2;y++) {
  		mat[t].a[t-1][y]=mat[0].a[t-1][y];
  	}
  }
  segn=n-1;
  for (int x=0;x<n-1;x++) t[segn+x]=mat[0];
  build();
	int last=0;
	for (int i=0;i<m;i++) {
		int pos=rint()-1,val=rint();
		if (pos==n-1) {
			last=val;
		}
		else {
			modify(pos,mat[val]);
			//printmat(mat[val]);
		}
		auto got=query(0,n-2);
		//printmat();
		ll ans=0;
		for (int x=0;x<mk;x++) {
			for (int y=0;y<mk;y++) {
				if (last==0||last-1==y) {
					//printf("x:%d y:%d add:%d\n",x,y,t[1].a[x][y]);
					ans+=got.a[x][y];
				}
			}
		}
		ans%=MOD;
		if (n==1) {
			if (last==0) ans=3;
			else ans=1;
		}
		printf("%d\n",(int)ans);
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