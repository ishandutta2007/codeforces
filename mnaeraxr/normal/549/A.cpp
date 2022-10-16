#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

char M[60][60];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	int ans = 0;

	for (int i = 0; i < n; ++i){
		cin >> M[i];

		if (i){
			for (int j = 1; j < m; ++j){
				string s = "";
				s += M[i][j];
				s += M[i - 1][j];
				s += M[i][j - 1];
				s += M[i - 1][j - 1];
				sort(s.begin(), s.end());
				if (s == "acef")
					++ans;
			}
		}
	}

	cout << ans << endl;

	return 0;
}