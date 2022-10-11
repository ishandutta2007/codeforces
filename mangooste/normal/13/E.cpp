#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int k = 447;

void one_jump(int i, vector <int>& v, vector <pair <int, int>>& jump, int n) {
	int j = i + v[i];
	if (j >= n) {
		jump[i] = { i, 1 };
	}
	else if (i / k == j / k) {
		jump[i] = { jump[j].first, jump[j].second + 1 };
	}
	else {
		jump[i] = { i, 1 };
	}
}

void build(vector <int>& v, vector <pair <int, int>>& jump) {
	int n = v.size();
	jump.resize(n, { -1, -1 });
	for (int i = n - 1; i >= 0; i--) {
		one_jump(i, v, jump, n);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector <pair <int, int>> jump;
	build(v, jump);
	while (m--) {
		int type;
		cin >> type;
		if (type == 0) {
			int a, b;
			cin >> a >> b;
			v[a - 1] = b;
			one_jump(a - 1, v, jump, n);
			for (int i = a - 2; i >= 0 && i / k == (a - 1) / k; i--) {
				one_jump(i, v, jump, n);
			}
		}
		else {
			int a;
			cin >> a;
			a--;
			int last = a, sum = 0;
			while (true) {
				sum += jump[last].second;
				last = jump[last].first;
				if (last + v[last] >= n) {
					break;
				}
				last += v[last];
			}
			cout << last + 1 << ' ' << sum << '\n';
		}
	}
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <ctime>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define For(i, l, r) for (int i = l; i < r; i++)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fixed(n) cout << fixed << setprecision(n) <<  

using namespace std;

ull read(int x) {
	vector <ull> tmp(x);
	For(i, 0, x - 1) {
		cin >> tmp[i];
		char now;
		cin >> now;
	}
	cin >> tmp[x - 1];
	ull ans = 0;
	ull st = 1;
	for (int i = x - 1; i >= 0; i--) {
		ans += tmp[i] * st;
		st *= 256;
	}
	return ans;
}

signed main() {
	fastio;
	int n, x;
	cin >> n >> x;
	vector <ull> v(n);
	For(i, 0, n) {
		v[i] = read(x);
	}
	ull a, b;
	a = read(x);
	b = read(x);
	sort(v.begin(), v.end());
	int l = 0;
	for (l = 0; l < n && v[l] < a; l++);
	int r = 0;
	for (r = 0; r < n && v[r] <= b; r++);
	vector <ull> new_v;
	For(i, l, r) {
		new_v.push_back(v[i]);
	}
	new_v.resize(unique(new_v.begin(), new_v.end()) - new_v.begin());
	n = new_v.size();
	if (n == 0) {
		cout << b - a - ull(1) << '\n';
	}
	else {
		bool flag = false;
		For(i, 0, n - 1) {
			if (new_v[i + 1] - new_v[i] > 2) {
				flag = true;
				break;
			}
		}
		if (new_v[0] - a > 1 || b - new_v[n - 1] > 1) {
			flag = true;
		}
		if (!flag) {
			cout << "-1\n";
		}
		else {
			cout << b - a - ull(n) - ull(1) << '\n';
		}
	}
}
*/