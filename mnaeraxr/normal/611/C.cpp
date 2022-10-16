#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 510;

int hor[maxn][maxn];
int ver[maxn][maxn];

int get(int r1, int c1, int r2, int c2, int table[maxn][maxn]){
	return table[r2][c2] - table[r2][c1 - 1] - table[r1 - 1][c2] + table[r1 - 1][c1 - 1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	string prev, cur;
	for (int i = 1; i <= h; ++i){
		swap(prev, cur);
		cin >> cur;
		for (int j = 1; j <= w; ++j){
			if (j != 1 && cur[j - 2] == '.' && cur[j - 1] == '.')
				hor[i][j] = 1;
			if (i != 1 && cur[j - 1] == '.' && prev[j - 1] == '.')
				ver[i][j] = 1;

			ver[i][j] = ver[i][j] + ver[i - 1][j] + ver[i][j - 1] - ver[i - 1][j - 1];
			hor[i][j] = hor[i][j] + hor[i - 1][j] + hor[i][j - 1] - hor[i - 1][j - 1];
		}
	}

	int q; cin >> q;
	while (q--){
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		if (r1 > r2) swap(r1, r2);
		if (c1 > c2) swap(c1, c2);
		int ans = get(r1 + 1, c1, r2, c2, ver) + get(r1, c1 + 1, r2, c2, hor);
		cout << ans << endl;
	}

	return 0;
}