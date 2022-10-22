#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define pback push_back
#define inf 1e9
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

const int FACT_MAX = 200005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

llint comb(llint n, llint k)
{
	if(n < k) return 0;
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

llint n, m, r;
llint x[2005], y[2005], b[2005];
llint R[2005], R2[2005][2005];
llint sum[1005][1005];
llint w = 1000;

llint get(llint sx, llint sy, llint tx, llint ty)
{
	chmax(sx, 1LL), chmax(sy, 1LL);
	chmin(tx, w), chmin(ty, w);
	if(sx > tx || sy > ty) return 0;
	return sum[tx][ty] - sum[sx-1][ty] - sum[tx][sy-1] + sum[sx-1][sy-1];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n >> m >> r;
	rep(i, 1, n) cin >> x[i] >> y[i] >> b[i];
	rep(i, 1, n) sum[x[i]][y[i]]++;
	
	rep(x, 1, w){
		rep(y, 1, w){
			sum[x][y] += sum[x-1][y] + sum[x][y-1] - sum[x-1][y-1];
		}
	}
	
	rep(i, 1, n) R[i] = get(x[i]-r, y[i]-r, x[i]+r, y[i]+r);
	rep(i, 1, n){
		rep(j, 1, n){
			if(i >= j) continue;
			llint sx = max(x[i], x[j])-r, sy = max(y[i], y[j])-r;
			llint tx = min(x[i], x[j])+r, ty = min(y[i], y[j])+r;
			R2[i][j] = get(sx, sy, tx, ty);
		}
	}
	
	llint ans = 0;
	rep(i, 1, n){
		llint tmp = (comb(n, m) + mod - comb(n-R[i], m)) % mod;
		ans += b[i] * b[i] % mod * tmp % mod, ans %= mod;
	}
	rep(i, 1, n){
		rep(j, 1, n){
			if(i >= j) continue;
			llint z = R[i] + R[j] - R2[i][j];
			llint tmp = comb(n, m);
			tmp += mod - comb(n-R[i], m), tmp %= mod;
			tmp += mod - comb(n-R[j], m), tmp %= mod;
			tmp += comb(n-z, m) % mod, tmp %= mod;
			ans += b[i] * b[j] % mod * tmp % mod * 2 % mod, ans %= mod;
		}
	}
	cout << ans << endl;
	
	return 0;
}