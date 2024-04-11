#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 5005, P = 998244353;
int power(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1; 
	}
	return res;
}
int n, cnt[N], inv[N], sc[N], memo[N], f[N][N];
/*
f[i][j]  i  j  

*/
int main(){
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) 
		scanf("%d", &x), ++cnt[x];
	
	for(int i = 1; i <= n; i++){
		sc[i] = sc[i - 1] + cnt[i];
		inv[i] = power(i, P - 2);
	}
	
	for (int j = n; j; j--) {
		for (int i = 1; i <= n; i++) {
			if(sc[j - 1] + 1 < i) continue;
			f[i][j] = ((LL)cnt[j] - 1 + memo[i + 1]) % P * inv[n - i] % P;
			memo[i] = ((LL)memo[i] + (LL)cnt[j] * f[i][j]) % P;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + (LL)cnt[i] * f[1][i]) % P;
	}
	ans = ((LL)ans * inv[n]) % P;
	printf("%d\n", ans);
	return 0;
}