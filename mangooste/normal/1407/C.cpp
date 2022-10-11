#include <bits/stdc++.h>

using namespace std;

inline int query(int i, int j) {
	cout << "? " << i + 1 << ' ' << j + 1 << endl;
	int now;
	cin >> now;
	return now;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> inds(n);
	iota(inds.begin(), inds.end(), 0);

	while (inds.size() > 1) {
		int i = inds.back();
		inds.pop_back();
		int j = inds.back();
		inds.pop_back();
		int x = query(i, j);
		int y = query(j, i);
		if (x < y) {
			swap(x, y);
			swap(i, j);
		}
		p[i] = x;
		inds.push_back(j);
	}

	vector<char> used(n + 1, 0);
	for (auto x : p)
		used[x] = 1;
	int free = 1;
	while (free < n && used[free])
		free++;
	p[inds[0]] = free;
	cout << "! ";
	for (auto x : p)
		cout << x << ' ';
	cout << '\n';
}