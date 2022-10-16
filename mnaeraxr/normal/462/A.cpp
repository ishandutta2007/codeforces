#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define SZ(x) ((int)x.size())
#define DB(x) cout << #x << "=" << x << endl
#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1e-7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 10;

char M[110][110];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inside(int x, int y, int n){
	return 0 <= x && x < n && 0 <= y && y < n;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> M[i];
	}

	bool ok = true;
	for (int i = 0; i < n && ok; ++i){
		for (int j = 0; j < n && ok; ++j){
			int tot = 0;
			for (int k = 0; k < 4; ++k){
				int x = i + dx[k], y = j + dy[k];
				if (inside(x, y, n) && M[x][y] == 'o') ++tot;
			}
			if (tot & 1) ok = false;
		}
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}