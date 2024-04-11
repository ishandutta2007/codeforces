#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXN = 200005;
const LL MOD = 1000000007LL;

int n; LL f[MAXN], inv[MAXN], cof[MAXN], cof_[MAXN];

inline LL C(int a, int b){return (f[a] * inv[b] % MOD) * inv[a - b] % MOD;}
int main(){
	int i, k, t; LL sum = 0LL;
	scanf("%d", &n);
	f[0] = inv[0] = f[1] = inv[1] = 1;
	for(i = 2; i <= n; ++ i){
		f[i] = f[i - 1] * i % MOD;
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	}
	for(i = 2; i <= n; ++ i)
		(inv[i] *= inv[i - 1]) %= MOD;
	k = n >> 2;
	switch(n % 4){
		case 0:
			for(i = 0; i < 2 * k; ++ i){
				cof[i * 2 + 1] = C(2 * k - 1, i);
				cof[i * 2 + 2] = (MOD - cof[i * 2 + 1]) % MOD;
			} break;
		case 1:
			for(i = 0; i <= 2 * k; ++ i){
				cof[i * 2 + 1] = C(2 * k, i);
				cof[i * 2 + 2] = 0;
			} break;
		case 2:
			for(i = 0; i <= 2 * k; ++ i)
				cof[i * 2 + 1] = cof[i * 2 + 2] = C(2 * k, i);
			break;
		case 3:
			for(i = 0; i <= 2 * k; ++ i)
				cof_[i * 2 + 1] = cof_[i * 2 + 2] = C(2 * k, i);
			cof_[n] = 0, cof[1] = 1;
			for(i = 2; i <= n; ++ i)
				if(i & 1) cof[i] = (cof_[i] - cof_[i - 1] + MOD) % MOD;
				else cof[i] = (cof_[i] + cof_[i - 1]) % MOD;
			break;
	}
	for(i = 1; i <= n; ++ i){
		scanf("%d", &t);
		sum = (sum + cof[i] * t) % MOD;
	} cout << sum << endl;
}