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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18
#define PI 3.1415926535897932384626433
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
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
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

llint perm(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

ll n;
ll d[55], p[55];
ll dp[55][55];
ll dp2[55][55];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n;
	rep(i, 1, n) cin >> d[i];
	
	p[0] = 1;
	rep(i, 2, n) p[i] = p[i-2] * (i-1) % mod;
	
	dp2[0][0] = 1;
	rep(i, 0, n){
		rep(j, 0, n){
			if(i+j == 0) continue;
			if(i > 0){
				rep(k, 0, j) dp2[i][j] += dp2[i-1][j-k] * perm(j, k) % mod, dp2[i][j] %= mod;
			}
			else{
				rep(k, 3, j){
					dp2[i][j] += dp2[i][j-k] * perm(j-1, k-1) % mod * fact_inv[2] % mod, dp2[i][j] %= mod;
				}
			}
		
		}
	}
	
	/*rep(i, 0, n){
		rep(j, 0, n) cout << dp2[i][j] << " ";
		cout << endl;
	}*/
	
	
	dp[1][d[1]] = 1;
	rep(i, 1, n-1){
		rep(j, 1, n){
			if(i+j > n || dp[i][j] == 0) continue;
			ll cnt2 = 0, cnt3 = 0;
			rep(k, i+1, i+j){
				if(d[k] == 2) cnt2++;
				else cnt3++;
			}
			rep(k, 0, cnt2) rep(l, 0, cnt3) rep(m, 0, cnt3-l){
				ll sum = cnt2-k + l + 2*(cnt3-(l+m));
				if(((k+l)&1) || i+j+sum > n) continue;

				ll tmp = p[k+l] * dp2[(k+l)/2][m] % mod;
				tmp *= comb(cnt2, k), tmp %= mod;
				tmp *= comb(cnt3, l), tmp %= mod;
				tmp *= comb(cnt3-l, m), tmp %= mod;
				
				tmp *= fact[sum], tmp %= mod;
				tmp *= modpow(fact_inv[2], cnt3-(l+m)), tmp %= mod;
				dp[i+j][sum] += tmp * dp[i][j] % mod, dp[i+j][sum] %= mod;
				//outl(i SP j SP k SP l SP m SP sum SP tmp);
				
			}
		}
	}
	cout << dp[n][0] << endl;
	
	/*rep(i, 1, n){
		rep(j, 0, n){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	return 0;
}