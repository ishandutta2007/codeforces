#include <bits/stdc++.h>

using namespace std;
typedef double db;
typedef long long i64;
const int N = 1e6 + 10;
int n, k;
int vis[N], mu[N], p[N], T[N], tot = 0;
int id[N];
void sieve(int n) {
	vis[0] = vis[1] = mu[1] = T[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) p[++tot] = i ,mu[i] = -1, T[i] = i - 1;
		for(int j = 1; j <= tot && i * p[j] <= n; j++) {
			vis[i * p[j]] = 1;
			if(i % p[j] == 0) {
				T[i * p[j]] = T[i] * p[j];
				break;
			}
			T[i * p[j]] = T[i] * (p[j] - 1);
		}
	}
	for(int i = 3; i <= n; i++) id[i - 2] = i;
	sort(id + 1, id + n - 1, [&] (int x, int y) {
		if(T[x] != T[y]) return T[x] < T[y];
		return x < y;
	});
	return;
}

int main() {
	cin >> n >> k;
	if(k == 1) {
		cout << 3 << endl;
		return 0;
	}
	sieve(n);
	i64 ans = 0;
	for(int i = 1; i <= k; i++) {
		ans += T[id[i]];
	}
	ans += 2;
	cout << ans << endl;
    return 0;
}