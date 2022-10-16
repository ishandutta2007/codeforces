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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int prevd = 0, prevh = 0;
	int curd, curh;
	int ans = 0;

	for (int i = 0; i < m; ++i){
		cin >> curd >> curh;

		if (!i){
			ans = curh + curd - 1;
			prevd = curd, prevh = curh;
			continue;
		}

		if (abs(curh - prevh) > curd - prevd){
			cout << "IMPOSSIBLE" << endl;
			exit(0);
		}
		ans = max(ans, max(curh, prevh) + (curd - prevd - (abs(curh - prevh))) / 2);

		prevd = curd, prevh = curh;
	}

	ans = max(ans, curh + n - curd);

	cout << ans << endl;

	return 0;
}