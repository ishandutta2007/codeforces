#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int64 k;
	cin >> n >> k;
	vector<int64> a(n);

	int64 mx = 0;
	int64 sm = 0;

	for (int i = 0; i < n; ++i){
		cin >> a[i];
		mx = max(mx, a[i]);
		sm += a[i];
	}

	if (k > sm){
		cout << -1 << endl;
		exit(0);
	}

	int64 lo = 0, hi = mx + 1;

	while (lo + 1 < hi){
		int64 m = (lo + hi) / 2;

		int64 ss = 0;
		int64 t = 0;

		for (int i = 0; i < n; ++i){
			ss += min(a[i], m);
			if (a[i] > m) t++;
		}

		if (ss > k) hi = m;
		else lo = m;
	}

//	cout << lo << endl;

	vector<int> ans;
	int64 ss = 0;
	for (int i = 0; i < n; ++i)
	{
		ss += min(a[i], lo);
		if (a[i] > lo) ans.push_back(i + 1);
	}

	k -= ss;
	for (int i = k; i < (int)ans.size(); ++i) cout << ans[i] << " ";
	for (int i = 0; i < k; ++i) if (a[ans[i] - 1] > lo + 1) cout << ans[i] << " ";
	cout << endl;

	return 0;
}