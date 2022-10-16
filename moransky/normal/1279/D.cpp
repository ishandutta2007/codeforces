#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1000005, P = 998244353;
typedef long long LL;
int n, K[N], cnt[N];
vector<int> a[N];
int power(int a, int b) {
	int res = 1;
	while(b) {
		if (b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", K + i);
		for (int j = 0; j < K[i]; j++) {
			int x; scanf("%d", &x);
			a[i].push_back(x); cnt[x]++;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < K[i]; j++) {
			ans = (ans + (LL)cnt[a[i][j]] * power((LL)n * K[i] % P * n % P, P - 2) % P) % P;
		}
	}
 
	printf("%d\n", ans);
	return 0;
	
}