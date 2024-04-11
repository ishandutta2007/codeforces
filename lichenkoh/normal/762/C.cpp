#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=1e5+4;
ll fwd[mn],bak[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a,b; cin>>b>>a;
	ll asz=a.length(),bsz=b.length();
	memset(fwd,-1,sizeof fwd);
	memset(bak,-1,sizeof bak);
	fwd[0]=0;
	{
		ll j=0;
		for (ll i=0;i<asz;i++) {
			while(j<bsz&&b[j]!=a[i]) j++;
			if (j==bsz) break;
			fwd[j+1]=i+1; // b[0,j) can get up to a[0,i)
			//printf("F j:%lld i:%lld\n",j+1,i+1);
			j++;
		}
		for (ll j=1;j<=bsz;j++) {
			chkmax(fwd[j],fwd[j-1]);
		}
	}
	bak[bsz]=asz;
	{
		ll j=bsz-1;
		for (ll i=asz-1;i>=0;i--) {
			while(j>=0&&b[j]!=a[i]) j--;
			if (j<0) break;
			bak[j]=i; // b[j,bsz-1] can get up to a[i,asz-1]
			//printf("B j:%lld i:%lld\n",j,i);
			j--;
		}
		for (ll j=bsz-1;j>=0;j--) {
			if (bak[j]==-1) bak[j]=bak[j+1];
			chkmin(bak[j],bak[j+1]);
			//printf("j:%lld i:%lld\n",j,bak[j]);
		}
	}
	pll flen=MP(0LL,-1LL);
	for (ll j=0;j<=bsz;j++) {
		if (fwd[j]==-1||bak[j]==-1) break;
		ll len=min(fwd[j]+asz-bak[j],asz);
		chkmax(flen,MP(len,j));
	}
	if (flen.first==0) printf("-\n");
	else {
		ll j=flen.second;
		ll fi=fwd[j];
		ll bi=max(bak[j],fi);
		string ans=a.substr(0,fi)+a.substr(bi,asz-bi+1);
		cout<<ans<<endl;
	}
}