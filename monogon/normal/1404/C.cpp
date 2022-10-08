#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, q; cin >> n >> q;
	vector<int> a(n+1), ans(q), leftBound(q);
	vector<vector<int>> endHere(n+1);

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = i - a[i];
	}

	for (int i = 0; i < q; ++i) {
		int x, y; cin >> x >> y;
		int l = 1+x, r = n-y;
		leftBound[i] = l;
		endHere[r].push_back(i);
	}

	vector<int> BIT(n+1);
	int global = 0;
	for (int r = 1; r <= n; ++r) {
		int target = a[r];
		if (target >= 0) {
			// Find rightmost pos such that s[pos] >= target
			int pos = 0, cur = global;
			for (int jump = 1 << __lg(n); jump >= 1; jump /= 2)
				if (pos+jump <= r && cur - BIT[pos+jump] >= target)
					pos += jump, cur -= BIT[pos];

			// Increment prefix (+1 on whole array, -1 on suffix)
			++global;
			for (int i = pos+1; i <= n; i += i & -i)
				++BIT[i];
		}

		for (int iQuery : endHere[r]) {
			ans[iQuery] = global;
			for (int i = leftBound[iQuery]; i > 0; i -= i & -i)
				ans[iQuery] -= BIT[i];	
		}
	}

	for (int i = 0; i < q; ++i)
		cout << ans[i] << "\n";
}