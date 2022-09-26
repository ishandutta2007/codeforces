#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, q;
int a[N];
int fw[N];
vector<int> vec[N];

void upd(int p) {
	for (; p <= n; p += p & -p) fw[p]++;
}
int get(int p) {
	int ret = 0;
	for (; p > 0; p -= p & -p) ret += fw[p];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> q; 
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		vec[a[i]].push_back(i);
	}
	
	for (int i = 1; i <= q; ++i) {
		for (int j = 1; j < vec[i].size(); ++j) {
			int l = vec[i][j - 1], r = vec[i][j];
			if (get(r) - get(l - 1)) {
				return cout << "NO\n",0;
			}
		}
		for (int j : vec[i]) upd(j);
	}
	if (!vec[0].size() && !vec[q].size()) return cout << "NO\n",0;
	if (!vec[q].size()) a[vec[0][0]] = q;
	a[0] = 1;
	for (int i = 1; i <= n; ++i) if (a[i] == 0) {
		a[i] = a[i - 1];
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << '\n';
}