#include <bits/stdc++.h>
#include <cstring>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
const ll mc=20;
ll C[mc][mc];
void init()
{
	ll n=mc,k=mc;
    ll i, j;
 
    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

ll starbar(ll stars, ll parts) {
	if (parts==0) {
		return (stars==0)?1:0;
	}
	return C[stars+parts-1][parts-1];
}
const ll mn=9;
const ll md=16;
ll pat[mn];
ll rem[md];
ll desiredlen;
bool leadzeros;
ll gt;
ll dp[md+2][mn+2];
ll h(ll digit, ll len) {
	if (len>desiredlen) return 0;
	if (digit==-1) {
		if (leadzeros&&len==desiredlen) return 1;
		if (!leadzeros&&len<=desiredlen) return 1;
		return 0;
	}
	if (dp[digit][len]!=-1) return dp[digit][len];
	ll parts=len+1;
	if (!leadzeros && digit==0) parts=len;
	ll ans=0;
	for (ll stars=0;stars<=rem[digit];stars++) {
		ans+=h(digit-1,len+stars)*starbar(stars,parts);
	}
	//printf("dig:%lld len:%lld ans:%lld\n",digit,len,ans);
	return dp[digit][len]=ans;
}
ll g(bool lz, ll dlen) {
	leadzeros=lz; desiredlen=dlen;
	memset(dp,-1,sizeof dp);
	return h(15,0);
}
ll f() {
	ll ans=0;
	ll all=0;
	for (ll x=0;x<mn;x++) { // First changing digit
		for (ll d=0;d<pat[x];d++) {
			for (ll c=0;c<md;c++) rem[c]=gt;
			bool isz=true;
			for (ll y=0;y<x;y++) {
				if (pat[y]!=0) isz=false;
				if (!isz)rem[pat[y]]--;
			}
			if (d!=0) isz=false;
			if (!isz) rem[d]--;
			ll dlen=mn-x-1;
			if (0==(all|d)) {
				ll add=g(false,dlen)-1;
				//printf("AddA: x:%lld d:%lld. %d %lld %lld\n",x,d,false,dlen,add);
				ans+=add;
			}
			else {
				ll add=g(true,dlen);
				//printf("AddB: x:%lld d:%lld. %d %lld %lld\n",x,d,true,dlen,add);
				ans+=add;
			}
		}
		all|=pat[x];
	}
	return ans;
}
ll go(ll x) {
	x++;
	for (ll i=mn-1;i>=0;i--) {
		pat[i]=x&0xf;
		x>>=4;
	}
	return f();
}
int main() {
	init();
	memset(rem,0,sizeof rem);
	//gt=1;
	//printf("%lld\n",go(16));
	//return 0;
	//for (ll i=0;i<2;i++) rem[i]=2;
	//printf("%lld\n",g(false,2));
	//return 0;


	ll n,t;scanf("%lld%lld",&n,&t);
	gt=t;
	//printf("%lld\n",go(n));
	//return 0;
	ll imin=0,imax=1LL<<(4LL*mn);
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		ll got=go(imid);
		if (got<n) imin=imid+1;
		else imax=imid;
	}
	printf("%llx\n",imin);
}