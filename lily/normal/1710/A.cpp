#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

bool work() {
	int n, m, k;
	read(n); read(m); read(k);
	vector <int> a;
	for (int i = 1; i <= k; i++) {
		int x; read(x); a.push_back(x);
	}
	{
		LL ans = 0;
		for (auto i : a) if (i >= 2 * m) ans += i / m * m;
		if (ans >= (LL)n * m && n % 2 == 0) return 1;
		if (ans >= (LL)n * m) for (auto i : a) if (i >= 3ll * m) return 1;
	}
	swap(n, m);
	{
		LL ans = 0;
		for (auto i : a) if (i >= 2 * m) ans += i / m * m;
		if (ans >= (LL)n * m && n % 2 == 0) return 1;
		if (ans >= (LL)n * m) for (auto i : a) if (i >= 3ll * m) return 1;
	}
	return 0;
}

int main() {
	int T;
	read(T);
	while (T--) puts (work() ? "Yes" : "No");
}