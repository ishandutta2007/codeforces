#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
const ll LIM=1e7+1;
ll ipow(ll x, ll n) {
	if (n==0) return 1;
	ll y=1;
	while(n>1) {
		if (n%2==0) {
			x=x*x;
			if (x>LIM||x*y>LIM) return -1;
			n/=2;
		}
		else {
			y=x*y;
			x=x*x;
			if (y>LIM||x>LIM||x*y>LIM) return -1;
			n=(n-1)/2;
		}
	}
	return x*y;
}
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<_b;++i)
template<class T> inline int SZ(const T&c) { return c.size(); }
const ll MAXN=3162+5;
int mu[MAXN]; bool prime[MAXN], sq[MAXN];
vector<int> D[MAXN];
void initmobius() {
	int N=MAXN;
      FOR(i,1,N)
            for (int j = i; j < N; j += i)
                  D[j].push_back(i);
      REP(i,N) prime[i] = true;
      prime[0] = prime[1] = false;
      FOR(i,2,N)
            if(prime[i])
                  for(int j=i+i;j<N;j+=i)
                        prime[j] = false;
      for(int i=2;i*i<N;i++) {
            int t = i * i;
            for(int j=t;j<N;j+=t)
                  sq[j] = true;
      }
      FOR(i,1,N) {
            if (sq[i]) continue;
            int parity = 0;
            REP(j,SZ(D[i])) if(prime[D[i][j]]) parity++;
            int t = parity & 1;
            mu[i] = t ? -1 : 1;
      }
}


int main() 
{
	initmobius();
	ll n,leftlim,rightlim; scanf("%lld %lld %lld",&n,&leftlim,&rightlim);
	if (n==1) {
		printf("%lld\n",rightlim-leftlim+1); return 0;
	}
	else if (n==2) {
		ll num=(rightlim-leftlim+1);
		printf("%lld\n",(num*(num-1))); return 0;
	}
	ll final=0;
	for (ll d=1;;d++) {
		ll dp=ipow(d,n-1);
		if (dp==-1||dp>rightlim) break;
		vector<pll> v;
		for (ll x=d;;x+=d) {
			ll xp=ipow(x,n-1);
			if (xp==-1||xp>rightlim) break;
			ll lk = (leftlim+xp-1)/xp;
			ll rk = rightlim/xp;
			v.PB(MP(lk,1));
			v.PB(MP(rk+1,-1));
		}
		sort(v.begin(),v.end());
		ll prev=v[0].first;
		ll cnt=0;
		ll ans=0;
		for (auto &w: v) {
			ll x=w.first,t=w.second;
			if (x!=prev) {
				//printf("prev:%lld x:%lld cnt:%lld\n",prev,x,cnt);
				ll num=(x-prev);
				ans+=(cnt*(cnt-1))*num;
				prev=x;
			}
			cnt+=t;
		}
		final+=mu[d]*ans;
	}
	printf("%lld\n",final);
}