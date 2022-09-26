#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N], cnt[N];
int prf[N], suf[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		prf[i] = prf[i - 1];
		if (!cnt[a[i]]) prf[i]++;
		cnt[a[i]]++;
	}
	memset(cnt, 0, sizeof cnt);
	int res = 0;
	for (int i = n; i >= 1; --i) {
		if (!cnt[a[i]]) res += prf[i - 1];
		cnt[a[i]]++;
	}
	cout << res;
}