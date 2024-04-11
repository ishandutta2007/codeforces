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
const int MAXN = 510;
const int oo = 1 << 29;

int n;
char B[MAXN][MAXN];
char M[MAXN][MAXN];
char BOUT[MAXN][MAXN];

bool valid(int x, int y){
	if (0 <= x && x < n && 0 <= y && y < n)
		return B[x][y] != '.';
	return true;
}

void shoot(int x, int y){
	if (0 <= x && x < n && 0 <= y && y < n && M[x][y] == '.')
		M[x][y] = 'x';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<pii> V;
	for (int i = 0; i < n; ++i){
		cin >> B[i];
		for (int j = 0; j < n; ++j){
			if (B[i][j] == 'o'){
				V.push_back(MP(i,j));
				M[i][j] = 'o';
			}
			else{
				M[i][j] = '.';
			}
		}
	}

	vector<pii> ans;
	for (int i = -n + 1; i < n; ++i){
		for (int j = -n + 1; j < n; ++j){
			bool ok = true;
			for (int k = 0; k < (int)V.size() && ok; ++k){
				pii &cur = V[k];
				if (!valid(cur.first + i, cur.second + j)) ok = false;
			}
			if (ok){
				ans.push_back(MP(i,j));
			}
		}
	}

	for (int i = 0; i < (int)V.size(); ++i){
		pii p = V[i];
		for (int j = 0; j < (int)ans.size(); ++j){
			pii a = ans[j];
			shoot(p.first + a.first, p.second + a.second);
		}
	}

	bool ok = true;
	for (int i = 0; i < n && ok; ++i){
		for (int j = 0; j < n && ok; ++j){
			if (B[i][j] != M[i][j])
				ok = false;
		}
	}

	if (!ok) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		
		for (int i = 0; i < 2 * n - 1; ++i)
			for (int j = 0; j < 2 * n - 1; ++j)
				BOUT[i][j] = '.';

		for (int i = 0; i < (int)ans.size(); ++i){
			pii a = ans[i];
			BOUT[n - 1 + a.first][n - 1 + a.second] = 'x';
		}
		BOUT[n - 1][n - 1] = 'o';

		for (int i = 0; i < 2 * n - 1; ++i){
			for (int j = 0; j < 2 * n - 1; ++j)
				cout << BOUT[i][j];
			cout << endl;
		}
	}

	return 0;
}