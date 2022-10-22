#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

int m, n;
char bit[55][1005];

llint fact[1005], fact_i[1005];

llint pow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (pow(a, n-1)%mod)) % mod;
	}
	else{
		return pow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < 1005; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	for(int i = 0; i < 1005; i++){
		fact_i[i] = pow(fact[i], mod-2);
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_i[k], ret %= mod;
	ret *= fact_i[n-k], ret %= mod;
	return ret;
}


int parent[1005];
void init()
{
	for(int i = 0; i < m; i++) parent[i] = i;
}

int root(int i)
{
	if(parent[i] == i) return i;
	return parent[i] = root(parent[i]);
}

bool same(int i, int j)
{
	return root(i) == root(j);
}

void unite(int i, int j)
{
	int root_i = root(i), root_j = root(j);
	if(root_i == root_j) return;
	parent[root_i] = root_j;
}

llint dp[1005];
int cnt[1005];

int main(void)
{
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> bit[i][j];
		}
	}
	init();
	make_fact();
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			if(i >= j) continue;
			for(int k = 0; k < n; k++){
				if(bit[k][i] != bit[k][j]) goto pass;
			}
			unite(i, j);
			pass:;
		}
	}
	
	dp[0] = 1;
	for(int i = 1; i < 1005; i++){
		for(int j = 1; j <= i; j++){
			dp[i] += (comb(i-1, j-1) * dp[i-j]) % mod;
			dp[i] %= mod;
		}
	}
	
	
	llint ans = 1;
	for(int i = 0; i < m; i++) root(i);
	for(int i = 0; i < m; i++){
		cnt[parent[i]]++;
	}
	for(int i = 0; i < m; i++){
		if(cnt[i]){
			ans *= dp[cnt[i]];
			ans %= mod;
		}
	}
	
	cout << ans << endl;
	return 0;
}