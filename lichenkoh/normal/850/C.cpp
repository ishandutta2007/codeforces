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



const int MAXN=1e6;
const int MAXP=MAXN;
bool sieve_array[MAXP+1];
int ap[MAXP+1];
vector<int> gpv;

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
    ap[i]=1<<30;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = (int)(ceil(sqrt(MAXP)))+2;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
        ap[j]=i;
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
      ap[i]=i;
    }
  }
}

pair<int,int> factorize_dest[500];
int factorize_tmp[500];
int factorize(int x) {
  int power=1;
  // Needed for factorizing MAXN^3 numbers
  //int xsqrt=round(sqrt(x));
  //if (xsqrt*(ll)xsqrt==x) {
  //  power=2;
  //  x=xsqrt;
  //}
  // End needed for factorizing MAXN^3 numbers
  int tsz=0;
  while(x>=MAXP) {
    bool found=false;
    for (auto &p:gpv) {
      if (p*(ll)p>x) break;
      while ((x%p)==0) {
        //printf("x:%lld p:%d\n",x,p);
        x/=p;
        factorize_tmp[tsz++]=p;
        found=true;
      }
    }
    if (x<MAXP) break;
    if (!found) break;
  }
  if (x<MAXP) {
    while(x>1) {
      int p=ap[x];
      x/=p;
      factorize_tmp[tsz++]=p;
    }
  }
  if (x>1) factorize_tmp[tsz++]=x;
  sort(factorize_tmp,factorize_tmp+tsz);
  int didx=0;
  for (int tidx=0;tidx<tsz;tidx++) {
    int p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=MP(p,power);
    }
    else factorize_dest[didx-1].snd+=power;
  }
  return didx;
}

char mex(vector<char> &v) {
	sort(v.begin(),v.end());
	char ans=0;
	for (auto &w:v) {
		if (w==ans) ans++;
	}
	return ans;
}
int ilog2(int x) {
  return 31-__builtin_clz(x);
}
const int mz=128<<20;
char dp[mz];
char nim(int z) {
	if (z<mz&&dp[z]!=-1) return dp[z];
	vector<char> v;
  bool can=0;
	for (int x=ilog2(z);x>=0;x--) {
		int msk=1<<x;
    if (z&msk) can=true;
		if (can) {
			int nz=(z&(msk-1))|(z>>(x+1));
			v.PB(nim(nz));
			//printf("z:%d nz:%d nim:%d\n",z,nz,nim(nz));
		}
	}
	char ans=mex(v);
	if (z<mz) dp[z]=ans;
	return ans;
}

int main() 
{
  memset(dp,-1,sizeof dp);
  dp[0]=0;
	/*for (int x=1;x<=64;x++) {
		//printf("%d,",nim(x));
		if (nim(x)&1) {
			cout<<bitset<8>(x)<<endl;
			//printf("%d,",x);
			//printf("x:%d nim:%d\n",x,nim(x));
		}
	}
	return 0;*/
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int n=rint();
  map<int,int> h;
  for (int i=0;i<n;i++) {
  	int x=rint();
  	int fsz=factorize(x);
  	for (int j=0;j<fsz;j++) {
  		int p=factorize_dest[j].fst;
  		int e=factorize_dest[j].snd;
  		assert(e>=1);
  		h[p]|=1<<(e-1);
  	}
  }

  int sum=0;
  for (auto &w:h) {
  	int nimed=nim(w.snd);
  	sum^=nimed;
  }
  if (sum!=0) printf("Mojtaba\n");
  else printf("Arpa\n");
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