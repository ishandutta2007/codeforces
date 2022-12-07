#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

vector<vector<int>> keyboard = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
		{-1, 0, -1}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map<int,pii> M;

	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 3; ++j){
			if (keyboard[i][j] == -1) continue;
			int val = keyboard[i][j];

			M[val] = {i, j};
		}
	}

	int n; cin >> n;
	string s; cin >> s;

	vector<pii> diff;
	for (int i = 1; i < (int)s.length(); ++i){
		pii prev = M[s[i - 1] - '0'];
		pii cur = M[s[i] - '0'];

		diff.push_back({cur.first - prev.first, cur.second - prev.second});
	}

	int total = 0;

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 3; ++j){
			int x = i, y = j;
			if (keyboard[x][y] == -1) continue;
			bool ok = true;

			for (auto d : diff){
				x += d.first;
				y += d.second;

				if (x < 0 || x >= 4 || y < 0 || y >= 3 || keyboard[x][y] == -1){
					ok = false;
					break;
				}
			}

			if (ok) ++total;
		}

	cout << (total == 1 ? "YES" : "NO") << endl;

	return 0;
}