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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, l, r, x;
	cin >> n >> l >> r >> x;
	vector<int> V(n);

	for (int i = 0; i < n; ++i) cin >> V[i];

	sort(V.begin(), V.end());

	int ans = 0;

	for (int i = 0; i < (1 << n); ++i){
		int tot = 0;
		int mx = V[0], mn = V[n - 1], s = 0;
		for (int j = 0; j < n; ++j){
			if (i & (1 << j)){
				mx = max(mx, V[j]);
				mn = min(mn, V[j]);
				++tot;
				s += V[j];
			}
		}
		if (tot < 2) continue;
		if (l <= s && s <= r && mx - mn >= x)
			ans++;
	}

	cout << ans << endl;

	return 0;
}