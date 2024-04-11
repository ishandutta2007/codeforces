#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)



int main() {
	int T;
	read(T);
	while (T--) {
		int n, K;
		read(n); read(K);
		vector <int> a;
		for (int i = 1; i <= n; i++) {
			int x; read(x);
			a.push_back(x > K);
		}
		int ans = 0;
		for (int i = 0; i < K; i++) {
			ans += a[i];
		}
		printf("%d\n", ans);
	}
}