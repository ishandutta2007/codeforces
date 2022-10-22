#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
const int N = 3e5 + 10, V = 3e5 + 1;

struct BIT {
	i64 t[N];
	
	void Add(int x, int v) {
		x++;
		for(int i = x; i <= V; i += i & (-i)) {
			t[i] += v;
		}
	}
	
	i64 Sum(int x) {
		x++;
		x = min(x, V);
		i64 res = 0;
		for(int i = x; i > 0; i -= i & (-i)) {
			res += t[i];
		}
		return res;
	}
}T1, T2;

int n, a[N];


int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	i64 ans = 0, res = 0;
	for(int i = 1; i <= n; i++) {
		ans += res + 1ll * a[i] * (i - 1);
		ans -= T2.Sum(a[i]);
		for(int j = 0; j <= V; j += a[i]) {
			ans -= (T1.Sum(j + a[i] - 1) - T1.Sum(j - 1)) * j;
			T2.Add(j + a[i], a[i]);
		}
		T1.Add(a[i], 1);
		res += a[i];
		cout << ans <<" ";
	}
	cout << endl;
	return 0;
}