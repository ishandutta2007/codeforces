#include <iostream>
#include <time.h>
#include <stdlib.h>
#define llint long long
#define mod 1000003

using namespace std;

llint mat[55][15];
llint a[15];

llint Rand()
{
	return rand() * RAND_MAX + rand();
}

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

void swap(int i, int j)
{
	for(int k = 0; k <= 11; k++){
		llint t = mat[i][k];
		mat[i][k] = mat[j][k];
		mat[j][k] = t;
	}
}

void solve()
{
	for(int i = 0; i <= 10; i++){
		llint max_val = 0, max_j;
		for(int j = i; j < 50; j++){
			if(mat[j][i] > max_val){
				max_val = mat[j][i];
				max_j = j;
			}
		}
		swap(i, max_j);
		
		llint div = mat[i][i];
		for(int j = 0; j <= 11; j++){
			mat[i][j] *= modpow(div, mod-2), mat[i][j] %= mod;
		}
		for(int j = 0; j < 50; j++){
			llint coe = mat[j][i];
			if(i == j) continue;
			for(int k = 0; k <= 11; k++){
				mat[j][k] += mod - coe * mat[i][k] % mod;
				mat[j][k] %= mod;
			}
		}
	}
}

llint calc(llint x)
{
	llint ret = 0;
	for(int i = 0; i <= 10; i++){
		ret += a[i] * modpow(x, i);
		ret %= mod;
	}
	return ret;
}

int main(void)
{
	srand(time(NULL));
	
	llint res;
	for(int i = 0; i < 50; i++){
		int x = Rand() % mod;
		cout << "? " << x << endl;
		cin >> res;
		if(res == -1) return 0;
		for(int j = 0; j <= 10; j++) mat[i][j] = modpow(x, j);
		mat[i][11] = res;
	}
	
	solve();
	
	for(int i = 0; i <= 10; i++) a[i] = mat[i][11];
	for(int i = 0; i < mod; i++){
		if(calc(i) == 0){
			cout << "! " << i << endl;
			return 0;
		}
	}
	cout << "! " << -1 << endl;
	
	return 0;
}