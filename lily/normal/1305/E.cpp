#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


int n, m;

int check(int mid) {
	int ans = 0;
	for ( mid -= 2; mid > 0; mid -= 2) ans += mid;
	return ans;
}
int check(int K, int mid) {
	int ans = check(K - 1);
	for (int i = 1; i < K; i++) {
		if (i < mid - i && mid - i < K) ans++;
	}
	return ans;
}


int main() {
	read(n); read(m);
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid) >= m) r = mid;
		else l = mid + 1;
	}
	if (r > n) return puts("-1"), 0;
	int K = l;
	r = 2 * l;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(K, mid) <= m) r = mid;
		else l = mid + 1;
	}
	for (int i = 1; i < K; i++) printf("%d ", i); 
	printf("%d ", l);
	for (int i = K + 1; i <= n; i++) {
		printf("%d ", int(5e8) + 20000 * i);
	}
}