#include <iostream>
#define llint long long
#define mod 998244353

using namespace std;

llint h, w, n;
bool usedX[3605], usedY[3605];
llint dpX[3605][3605][2], dpY[3605][3605][2];

const int FACT_MAX = 10005;
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

void calc(bool used[3605], llint dp[3605][3605][2], llint n)
{
	dp[0][0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; k < 2; k++){
				(dp[i+1][j][0] += dp[i][j][k]) %= mod;
				if(j+1 <= n && k == 0 && i+1 < n && !used[i+1] && !used[i+2]){
					(dp[i+1][j+1][1] += dp[i][j][k]) %= mod;
				}
			}
		}
	}
}

int main(void)
{
	cin >> h >> w >> n;
	
	llint x, y;
	for(int i = 0; i < 2*n; i++){
		cin >> y >> x;
		usedX[x] = usedY[y] = true;
	}
	make_fact();
	
	calc(usedX, dpX, w);
	calc(usedY, dpY, h);
	
	llint ans = 0, cntX = 0, cntY = 0;
	for(int i = 1; i <= w; i++) if(!usedX[i]) cntX++;
	for(int i = 1; i <= h; i++) if(!usedY[i]) cntY++;
	
	for(int i = 0; i <= cntX/2; i++){
		for(int j = 0; j <= cntY/2; j++){
			if(cntX-2*i < j || cntY-2*j < i) continue;
			llint tmp = dpX[w][i][0] * comb(cntX-2*i, j) % mod * fact[j] % mod;
			tmp *= dpY[h][j][0] * comb(cntY-2*j, i) % mod * fact[i] % mod, tmp %= mod;
			ans += tmp, ans %= mod;
		}
	}
	cout << ans << endl;
	
	return 0;
}