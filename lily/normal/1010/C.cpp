/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second
#define read(a) scanf("%d", &a)

int n, K, g;
vector <int> ans;

int main() {
	read(n); read(K);
	g = K;
	for (int i = 0; i < n; i++) {
		int x; read(x);
		g = __gcd(x, g);
	}
	for (int i = 0; i < K; i++) if (i % g == 0) ans.push_back(i);
	printf("%d\n", (int)ans.size());
	for (auto v : ans) printf("%d ", v);
	return 0;
}