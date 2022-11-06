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
ll ilog2(ll x) {return 63-__builtin_clzll(x);}
const ll mk=50;
ll f[mk][mk][mk][2];
ll ga,gb,gtarget;
void go(ll startpos) {
	for (ll pos=startpos;pos>=0;pos--) {
		memset(f[pos],0,sizeof f[pos]);
		for (ll popa=0;popa<=ga;popa++) { // More optimizations here?
			for (ll popb=0;popb<=gb;popb++) {
				for (ll carry=0;carry<=1;carry++) {
					ll val=f[pos+1][popa][popb][carry]; // At pos needing carry bit from pos-1
					if (val==0) continue;
					ll need=((gtarget>>pos)&1)|(carry<<1);
					//if (val) printf("%lld %lld %lld %lld: %lld. need:%lld. gtarget:%lld gt>>pos%lld\n",pos+1,popa,popb,carry,val,need,gtarget,(gtarget>>pos));
					ll bitalim=(pos<ga-1)?1:0;
					for (ll bita=0;bita<=bitalim;bita++) {
						ll bitblim=(pos<gb-1)?1:0;
						for (ll bitb=0;bitb<=bitblim;bitb++) {
							ll needcarry=(need-bita-bitb);
							if (needcarry!=0&&needcarry!=1) continue;
							f[pos][popa+bita][popb+bitb][needcarry]+=val;
							//if (val) printf("Add to %lld %lld %lld %lld: %lld\n",pos,popa+bita,popb+bitb,needcarry,val);
						}
					}
				}
			}
		}
	}
}
ll solve(ll a,ll b,ll oldtarget) {
	//if (target>maxcan) return 0;
	ll final=0;
	map<ll,vector<pll> > h;
	for (ll popa=0;popa<=a;popa++) {
		for (ll popb=0;popb<=b;popb++) {
			ll want=oldtarget+popa+popb;
			if (want&1) continue;
			want/=2;
			h[want].PB(MP(popa,popb));
		}
	}
	ll prev=-1;
	ga=a,gb=b;
	ll tlim=max(a,b); //if (tlim>3) tlim--;
	memset(f[tlim+1],0,sizeof f[tlim+1]);
	f[tlim+1][0][0][0]=1;
	for (auto &w:h) {
		gtarget=w.first;
		ll startpos;
		if (prev==-1) {
			startpos=tlim;
		}
		else {
			startpos=ilog2(prev^w.first);
		}
		//printf("a:%lld b:%lld startpos:%lld\n",a,b,startpos);
		go(startpos);
		prev=gtarget;
		ll current=0;
		if (gtarget>=(1LL<<tlim)) continue;
		for (auto &got:w.second) {
			//printf("wf:%lld gf:%lld gs:%lld gtarget:%lld got:%lld\n",w.first,got.first,got.second,gtarget,f[0][got.first][got.second][0]);
			current+=f[0][got.first][got.second][0];
		}
		final+=current;
	}
	return final;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll target; scanf("%lld",&target);
	ll klim=ilog2(target);
	//printf("target:%lld klim:%lld\n",target,klim);
	ll final=0;
	for (ll a=0;a<=klim;a++) for (ll b=0;b<=klim;b++) {
		ll incr=-1;
		for (ll i=0;i<=a;i++) incr+=1LL<<i;
		for (ll i=0;i<=b;i++) incr+=1LL<<i;
		ll base=0;
		for (ll i=0;i<=a;i++) base+=1LL<<i;
		for (ll i=1;i<=b;i++) base+=3LL<<(i-1);
		if (base>target) continue;
		ll lca=((target-base)/incr)+1;
		ll newtarget=target-base-incr*(lca-1);
		//ll cand=-12345;
		//if(a==1&&b==0) {
			ll cand=solve(a,b,newtarget);
			//printf("a:%lld b:%lld lca:%lld newtarget:%lld cand:%lld\n",a,b,lca,newtarget,cand);
		//}
		final+=cand;
	}
	printf("%lld\n",final);
}