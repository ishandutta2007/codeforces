#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
typedef long long ll;


int main() {
	int N, M; cin >> N >> M;
	vector<int> a(N);
	rep(i, N) cin >> a[i], a[i]--;
	vector<int> num(M);
	rep(j, M) cin >> num[j];
	int tot = 0;
	rep(j, M) tot += num[j];
	int lb = 0, ub = N + 1;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		vector<int> cnt(M);
		rep(i, mid) cnt[a[i]]++;
		bool ok = true;
		rep(j, M) if (cnt[j] < num[j]) ok = false;
		if (ok) ub = mid;
		else lb = mid;
	}
	int l = 0, r = ub;
	if (r == N + 1) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> cnt(M);
	rep(i, r) cnt[a[i]]++;
	int ans = r;
	while (l < N) {
		int j = a[l++];
		cnt[j]--;
		for (; r < N && cnt[j] < num[j]; cnt[a[r++]]++);
		if (cnt[j] < num[j]) break;
		ans = min(ans, r - l);
	}
	cout << ans - tot << endl;
}