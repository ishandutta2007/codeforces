#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) (int)a.size()
const int N = 3e5 + 100;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		set <pair <int, int> > st1, st2;
		vector <int> used(n);
		queue <int> q;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			st1.insert({a[i], i});
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			st2.insert({b[i], i});
		}
		int v1 = st1.rbegin() -> y;
		used[v1] = 1;
		q.push(v1);
		st1.erase(*st1.rbegin());
		int v2 = st2.rbegin() -> y;
		if (v2 != q.front()) {
			used[v2] = 1;
			q.push(v2);
			st2.erase(*st2.rbegin());
			st1.erase({a[v2], v2});
		}
		st2.erase({b[v1], v1});
		while (sz(q)) {
			int v = q.front();
			q.pop();
			while (sz(st1) && st1.rbegin() -> x > a[v]) {
				int t = st1.rbegin() -> y;
				st1.erase({a[t], t});
				st2.erase({b[t], t});
				used[t] = 1;
				q.push(t);
			}
			while (sz(st2) && st2.rbegin() -> x > b[v]) {
				int t = st2.rbegin() -> y;
				st1.erase({a[t], t});
				st2.erase({b[t], t});
				used[t] = 1;
				q.push(t);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << used[i];
		}
		cout << "\n";
	}
	return 0;
}