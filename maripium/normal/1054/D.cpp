#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k;
int a[N];
map<int,int> cnt;

long long C2(int x) {
	return (1LL * (x) * (x - 1)) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	int tot = (1 << k) - 1;
	for (int i = 1; i <= n; ++i) cin >> a[i], a[i] ^= a[i - 1];
	for (int i = 0; i <= n; ++i) {
		int tmp = a[i] ^ tot;
		if (a[i] > tmp) a[i] = tmp;
		cnt[a[i]]++;
	}
	long long res = C2(n + 1);
	for (auto it : cnt) {
		int num = it.second;
		int num0 = num / 2, num1 = (num + 1) / 2;
		res -= C2(num0);
		res -= C2(num1);
	}
	cout << res << '\n';
}