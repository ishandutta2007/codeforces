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

int v[26];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	string s; cin >> s;

	for (int i = 0; i < n; ++i)
		v[s[i] - 'A']++;

	sort(v, v + 26);
	int64 ans = 0;
	for (int i = 25; i >= 0 && m; --i){
		if (m >= v[i]) ans += 1LL * v[i] * v[i], m -= v[i];
		else{
			ans += 1LL * m * m;
			m = 0;
		}
	}

	cout << ans << endl;

	return 0;
}