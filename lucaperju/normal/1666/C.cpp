#include <bits/stdc++.h>
using namespace std;

long long dist(int x, int y, int a, int b) {
	return 1LL * abs(x - a) + 1LL * abs(y - b);
}

struct usu {
	int a, b, c, d;
};

void solve() {
	int x[3], y[3];

	int xm = 1e9, ym = 1e9, xM = -1e9, yM = -1e9;
	for (int i = 0; i < 3 ; ++i) {
		cin >> x[i] >> y[i];
		xm = min(x[i], xm);
		ym = min(y[i], ym);
		xM = max(x[i], xM);
		yM = max(y[i], yM);
	}

	long long ans = 1e18;
	int wh;
	for (int i = 0; i < 3 ; ++i) {
		{
			// orizontal
			long long s = 1LL * xM - xm + abs(y[i] - y[0]) + abs(y[i] - y[1]) + abs(y[i] - y[2]); 
			if (s < ans)
				ans = s, wh = i;
		}

		{
			// vertical
			long long s = 1LL * yM - ym + abs(x[i] - x[0]) + abs(x[i] - x[1]) + abs(x[i] - x[2]); 
			if (s < ans)
				ans = s, wh = i + 3;
		}

	}

	vector <usu> sol;

	if (wh < 3) {
		int i = wh;
		sol.push_back({xm, y[i], xM, y[i]});
		for (int j = 0; j < 3 ; ++j)
			if (y[i] != y[j])
				sol.push_back({x[j], y[i], x[j], y[j]});
	} else {
		int i = wh - 3;
		sol.push_back({x[i], ym, x[i], yM});
		for (int j = 0; j < 3 ; ++j)
			if (x[i] != x[j])
				sol.push_back({x[i], y[j], x[j], y[j]});
	}
	
	cout << sol.size() << endl;
	for (auto it : sol)
		cout << min(it.a, it.c) << " " << min(it.b, it.d) << " " << max(it.a, it.c) << " " << max(it.b, it.d) << endl;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	t = 1;
	while (t--) solve();
	
	return 0;
}