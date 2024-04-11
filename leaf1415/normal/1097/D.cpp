#include <iostream>
#include <vector>
#define llint long long
#define mod 1000000007

using namespace std;

llint n, k;
bool prime[40000005];
vector<llint> pvec;
vector<llint> fnum, fvec;
llint dist[60][60];
llint dp[10005][60];

llint fact[20005], fact_inv[20005];

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
	for(int i = 1; i < 20005; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	for(int i = 0; i < 20005; i++){
		fact_inv[i] = modpow(fact[i], mod-2);
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


llint N;
vector<llint> tmp;

llint ans;
void dfs(int p)
{
	if(p >= N){
		llint ret = 1;
		for(int i = 0; i < N; i++){
			ret *= modpow(fvec[i], tmp[i]);
			ret %= mod;
		}
		for(int i = 0; i < N; i++){
			ret *= dist[i][tmp[i]];
			ret %= mod;
		}
		ans += ret, ans %= mod;
		return;
	}
	
	for(int i = 0; i <= fnum[p]; i++){
		tmp.push_back(i);
		dfs(p+1);
		tmp.pop_back();
	}
}

int main(void)
{
	make_fact();
	
	cin >> n >> k;
	for(int i = 2; i < 7005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 40000005; j+=i) prime[j] = true;
	}
	for(int i = 2; i < 40000005; i++) if(!prime[i]) pvec.push_back(i);
	
	for(int i = 0; i < pvec.size(); i++){
		int v = pvec[i], cnt = 0;
		while(n % v == 0){
			n /= v;
			cnt++;
		}
		if(cnt){
			fvec.push_back(v);
			fnum.push_back(cnt);
		}
	}
	if(n > 1){
		fvec.push_back(n);
		fnum.push_back(1);
	}
	N = fnum.size();
	
	//for(int i = 0; i < N; i++) cout << fvec[i] << " "; cout << endl;
	//for(int i = 0; i < N; i++) cout << fnum[i] << " "; cout << endl;
	
	for(int t = 0; t < N; t++){
		int M = fnum[t];
		for(int i = 0; i <= k; i++){
			for(int j = 0; j <= M; j++){
				dp[i][j] = 0;
			}
		}
		dp[0][M] = 1;
		
		for(int i = 1; i <= k; i++){
			llint sum = 0;
			for(int j = M; j >= 0; j--){
				sum += dp[i-1][j] * modpow(j+1, mod-2) % mod, sum %= mod;
				dp[i][j] = sum;
			}
		}
		for(int i = 0; i <= M; i++) dist[t][i] = dp[k][i];
	}
	
	/*for(int t = 0; t < N; t++){
		for(int i = 0; i <= fnum[t]; i++) cout << dist[t][i] << " "; cout << endl;
	}*/
	
	dfs(0);
	cout << ans << endl;
	
	return 0;
}