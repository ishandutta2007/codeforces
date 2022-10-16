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
	vector<int64> value(n);

	int64 sum = 0;

	for (int i = 0; i < n; ++i){
		cin >> value[i];
		sum += value[i];
	}

	sort(value.begin(), value.end());

	int64 lo = value[0], hi = value[0] + k + 1;

	while (lo + 1 < hi){
		int64 mid = (lo + hi) / 2;
		int64 ans = 0;
		for (int i = 0; i < n && mid > value[i]; ++i){
			ans += mid - value[i];
		}
		if (ans <= k) lo = mid;
		else hi = mid;
	}

	int64 poorest = lo;

	lo = -1, hi = value.back();

	while (lo + 1 < hi){
		int64 mid = (lo + hi) / 2;
		int64 ans = 0;
		for (int i = n - 1; i >= 0 && mid < value[i]; --i){
			ans += value[i] - mid;
		}
		if (ans <= k) hi = mid;
		else lo = mid;
	}

	int64 richest = hi;

	if (poorest >= richest){
		if (sum % n == 0) cout << 0 << endl;
		else cout << 1 << endl;
	}
	else{
		cout << richest - poorest << endl;
	}


	return 0;
}