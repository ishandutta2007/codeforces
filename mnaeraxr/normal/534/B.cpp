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

	int v1, v2, t, d, ans = 0;
	cin >> v1 >> v2 >> t >> d;

	ans = v1 + v2;
	for (int i = 2; i < t; ++i){
		if (v2 < v1) swap(v1, v2);
		v1 += d;
		ans += v1;
	}
	cout << ans << endl;

	return 0;
}