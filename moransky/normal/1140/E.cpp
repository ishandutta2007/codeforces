#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 200010, MOD = 998244353;
int n, k, a[N], b[N], l1 = 0, l2 = 0, f[N][2];
int inline mul(int x, int y){
	return ((LL)x * y) % MOD;
}
int inline add(int x, int y){
	return ((LL)x + y) % MOD;
}
int power(int q, int m){
	int res = 1;
	while(m){
		if(m & 1) res = (LL)res * q % MOD;
		q = (LL)q * q % MOD;
		m >>= 1;
	}
	return res;
}
int work(int w[], int len){
	if(n == 0) return 1;
	int l = 1, r = len;
	while(l <= len && w[l] == -1) l++;
	if(l == len + 1) return mul(k, power(k - 1, len - 1));
	while(r && w[r] == -1) r--;
	int res = mul(power(k - 1, l - 1), power(k - 1, len - r));
	int first = l;
	for(l = first + 1; l <= r; l++){
		if(w[l] == -1) continue;
		res = mul(res, f[l - first - 1][w[first] == w[l]]);
		first = l;
	}
	return res;
}
int main(){
	scanf("%d%d", &n, &k);
	f[0][0] = 1;
	for(int i = 1; i <= n; i++){
		f[i][0] = add(mul(k - 2, f[i - 1][0]), f[i - 1][1]);
		f[i][1] = mul(k - 1, f[i - 1][0]);
	}
	for(int i = 1; i <= n; i++) {
		if(i & 1) scanf("%d", &a[++l1]);
		else scanf("%d", &b[++l2]);
	}
	printf("%d\n", mul(work(a, l1), work(b, l2)));
	return 0;
}