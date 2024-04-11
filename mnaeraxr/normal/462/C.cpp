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
const int MAXN = (int)3e5 + 10;

int v[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v, v + n);
	int64 ans = 0;
	for (int i = 0; i < n; ++i){
		ans += 1LL * v[i] * (2 + i);
	}
	ans -= v[n - 1];
	cout << ans << endl;

	return 0;
}