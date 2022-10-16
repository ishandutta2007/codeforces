#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int64 M[3][maxn];
int64 D[3][maxn];

vector<vi> target[3] = {
		{
				{0, 3},
				{1, 4, 3},
				{2, 5, 4, 3},
				{8, 0, 1, 2, 3, 4, 5}
		},
		{
				{0, 3, 4},
				{1, 4},
				{2, 5, 4}
		},
		{
				{0, 3, 4, 5},
				{1, 4, 5},
				{2, 5},
				{6, 0, 1, 2, 3, 4, 5}
		}
};

int dx[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
int dy[9] = {-1, -1, -1, 0, 0, 0, -2, -2, -2};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < n; ++j){
			cin >> M[i][j];

			D[i][j] = -oo;
		}

	D[0][0] = M[0][0];
	D[1][0] = D[0][0] + M[1][0];
	D[2][0] = D[1][0] + M[2][0];

	for (int i = 1; i < n; ++i){
		for (int j = 0; j < 3; ++j){
			for (auto e : target[j]){
				int64 value = 0;

				for (int uu = 0; uu < (int)e.size(); ++uu){
					int u = e[uu];
					int x = dx[u];
					int y = i + dy[u];

					if (y == -1) continue;

					if (uu == 0) value += D[x][y];
					else value += M[x][y];
				}

				D[j][i] = max(D[j][i], value);
			}

//			cout << D[j][i] << " ";
		}
//		cout << endl;
	}

	cout << D[2][n - 1] << endl;

	return 0;
}