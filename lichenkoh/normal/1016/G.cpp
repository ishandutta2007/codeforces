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


const int MAXN=1e6+4;
const int MAXP=MAXN;
bitset<MAXP+1> sieve_array;
int ap[MAXP+1];
vector<int> gpv;

void sieve() {
	sieve_array.set();
  for (int i = 0; i <= MAXP; i++) {
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


pair<ll,int> factorize_dest[500];
ll factorize_tmp[500];
int factorize(ll x) {
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
  if (x>1) {
  	factorize_tmp[tsz++]=x;
  }
  sort(factorize_tmp,factorize_tmp+tsz);
  int didx=0;
  for (int tidx=0;tidx<tsz;tidx++) {
    ll p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=MP(p,1);
    }
    else factorize_dest[didx-1].snd++;
  }
  return didx;
}
vector<ll> primecand;
int factorize2(ll x) {
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
  for (auto &w:primecand) {
  	while (x%w==0) {
  		factorize_tmp[tsz++]=w;
  		x/=w;
  	}
  }
  if (x>1) {
  	factorize_tmp[tsz++]=x;
  }
  sort(factorize_tmp,factorize_tmp+tsz);
  int didx=0;
  for (int tidx=0;tidx<tsz;tidx++) {
    ll p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=MP(p,1);
    }
    else factorize_dest[didx-1].snd++;
  }
  return didx;
}


void fail() {
	printf("0\n"); exit(0);
}
const int mn=2e5+2;
ll a[mn];
int psz;
vector<ll> vp;
vector<int> getc(ll tmpgcd) {
	vector<int> vg;
 	for (int i=0;i<psz;i++) {
 		ll p=vp[i];
 		int cnt=0;
 		while(tmpgcd%p==0) {
 			++cnt;
 			tmpgcd/=p;
 		}
 		vg.PB(cnt);
 	}	
 	return vg;
}
vector<int> vv[mn];
int *f;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int n=rint(); ll gcd=rlong(); ll lcm=rlong();
 	if (lcm%gcd) fail();
 	for (int x=0;x<n;x++) {
 		a[x]=rlong();
 		if (a[x]>1) primecand.PB(a[x]);
 		//for (int i=0;i<sz;i++) primecand.PB(factorize_dest[i].fst);
 	}
 	{
 		int sz=factorize(gcd);
 		for (int i=0;i<sz;i++) primecand.PB(factorize_dest[i].fst);
 	}
 	sort(primecand.begin(),primecand.end());
 	psz=factorize2(lcm);
 	 for (int i=0;i<psz;i++) {
 	 	//printf("%lld %d\n",factorize_dest[i].fst,factorize_dest[i].snd);
 	 	vp.PB(factorize_dest[i].fst);
 	 }
 	vector<int> vl; for (int i=0;i<psz;i++) vl.PB(factorize_dest[i].snd);
 	vector<int> vg=getc(gcd);
 	for (int i=0;i<n;i++) {vv[i]=getc(a[i]);}
 	f = new int[1<<psz];
 	memset(f,0,sizeof(int)*(1<<psz));
 	for (int x=0;x<n;x++) {
 		if (a[x]%gcd) continue;
 		int sig=0;
 		for (int i=0;i<psz;i++) {
 			if (vv[x][i]!=vg[i]&&vl[i]!=vg[i]) sig|=1<<i;
 		}
 		//printf("%lld sig:%d\n",a[x],sig);
 		++f[sig];
 	}
  for (int i=0;i<psz;i++) {
    for (int z=0;z<(1<<psz);z++) {
      if (z&(1<<i)) {
        f[z]+=f[z^(1<<i)];
      }
    }
  }
  ll final=0;
 	for (int x=0;x<n;x++) {
 		if (lcm%a[x]) continue;
 		int sig=0;
 		for (int i=0;i<psz;i++) {
 			if (vv[x][i]!=vl[i]) sig|=1<<i;
 		}
 		int negsig=((1<<psz)-1)&(~sig);
 		//printf("%lld sig:%d negsig:%d\n",a[x],sig,negsig);
 		final+=f[negsig];
 	}
 	printf("%lld\n",final);
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