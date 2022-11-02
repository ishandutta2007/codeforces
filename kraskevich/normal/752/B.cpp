#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	string a, b;
	cin >> a >> b;
	vector<vector<bool>> was(256, vector<bool>(256));
	for (int i = 0; i < a.length(); i++)
		was[a[i]][b[i]] = was[b[i]][a[i]] = true;
	vector<pair<char, char>> v;
	for (int i = 0; i < 256; i++)
		for (int j = 0; j < 256; j++) {
			if (was[i][j] && i < j)
				v.push_back(make_pair(i, j));
			for (int k = j + 1; k < 256; k++)
				if (was[i][j] && was[i][k]) {
					cout << -1 << endl;
					return 0;
				}
		}
	cout << v.size() << endl;
	for (auto p : v)
		cout << p.first << " " << p.second << endl;
}