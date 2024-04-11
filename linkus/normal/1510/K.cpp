#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//	ordered_set<int> s;

vector <int> f(vector <int> v) {
	for (int i = 0; i < (int)v.size(); i += 2) {
		swap(v[i], v[i + 1]);
	}
	return v;
}

vector <int> f2(vector <int> v) {
	vector <int> u;
	int n = v.size() / 2;
	for (int i = n; i < 2 * n; ++i) {
		u.push_back(v[i]);
	}
	for (int i = 0; i < n; ++i) {
		u.push_back(v[i]);
	}
	return u;
}

bool ok(vector <int> v) {
	for (int i = 1; i < (int)v.size(); ++i) {
		if (v[i] < v[i - 1]) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	vector <int> v;
	for (int i = 0; i < 2 * n; ++i) {
		int x;
		scanf("%d", &x);
		//x = 2 * n - i;
		v.push_back(x);
	}
	map <vector <int>, bool> m;
	queue <pair <int, vector <int> > > q;
	q.push({0, v});
	while (!q.empty()) {
		auto xd = q.front();
		q.pop();
		if (m[xd.second]) {
			continue;
		}
		m[xd.second] = true;
		if (ok(xd.second)) {
			printf("%d\n", xd.first);
			return 0;
		}
		q.push({xd.first + 1, f(xd.second)});
		q.push({xd.first + 1, f2(xd.second)});
	}
	printf("-1\n");
	return 0;
}