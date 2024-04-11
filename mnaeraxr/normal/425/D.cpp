#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

vector<int> X[MAXN], Y[MAXN];
unordered_set<int> USX[MAXN];
int vX[MAXN], vY[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		vX[i] = x, vY[i] = y;
		X[x].push_back(y);
		Y[y].push_back(x);
		USX[x].insert(y);
	}

	for (int i = 0; i < MAXN; ++i){
		sort(X[i].begin(), X[i].end());
		sort(Y[i].begin(), Y[i].end());
	}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		int x = vX[i], y = vY[i];
		int lx = lower_bound(Y[y].begin(), Y[y].end(), x) - Y[y].begin();
		int ly = lower_bound(X[x].begin(), X[x].end(), y) - X[x].begin();

		if (lx < ly){
			for (int i = 0; i < lx; ++i){
				int _x = Y[y][i];
				int d = x - _x;
				if (USX[_x].count( y - d) && USX[x].count( y - d))
					++ans;
			}
		}
		else{
			for (int i = 0; i < ly; ++i){
				int _y = X[x][i];
				int d = y - _y;
				if (x - d >= 0 && USX[x - d].count( y ) && USX[x - d].count( _y))
					++ans;
			}
		}
	}

	cout << ans << endl;

	return 0;
}