#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	set<pii> res;
	vector<int> x(3);
	vector<int> y(3);
	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < 3; i++) {
		int dx = 0;
		int dy = 0;
		for (int j = 0; j < 3; j++) {
			dx += x[j] - x[i];
			dy += y[j] - y[i];
		}
		res.insert(pii(x[i] + dx, y[i] + dy));
	}
	cout << res.size() << endl;
	for (auto p : res)
		cout << p.first << " " << p.second << endl;
}