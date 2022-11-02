#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int ways[101][10001] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vi v(n);
	for (int &x : v) cin >> x;
	sort(all(v));

	vi pf(n + 1, 0);
	REP(i, n) pf[i + 1] = pf[i] + v[i];

	vii vcnt;
	for (int i = 1, ccnt = 1; i <= n; i++) {
		if (i == n || v[i] != v[i - 1]) {
			vcnt.eb(v[i - 1], ccnt);
			ccnt = 0;
		}
		ccnt++;
	}

	// for (ii pr : vcnt) cerr << pr.x << " " << pr.y << endl;

	if (vcnt.size() <= 2)
		return cout << n << endl, 0;
	
	ways[0][0] = 1;
	int curcnt = 0, cursum = 0;
	for (ii pr : vcnt) {
		int oldcnt = curcnt;
		// int oldsum = cursum;
		curcnt += pr.y;
		cursum += pr.x * pr.y;

		for (int k = curcnt; k > 0; k--) {
			// construct a set of size k
			// count the number of ways.
			// we could pick 0 .. pr.y times object pr.x
			for (int val = cursum; val >= 0; val--) {
				if (ways[k][val] >= 2) continue; // already ambiguous
				for (int pick = max(1, k - oldcnt); pick <= min(k, pr.y) && val >= pick * pr.x; pick++) {
					ways[k][val] += ways[k - pick][val - pick * pr.x];
					if (ways[k][val] >= 2) break;
				}
			}
		}
	}

	int ret = 0;
	for (ii pr : vcnt) {
		for (int t = 1; t <= pr.y; t++) {
			if (ways[t][t * pr.x] == 1)
				ret = max(ret, t);
		}
	}
	cout << ret << endl;

	// now for bigger cases...
	// we can only query (n, n x m) for some (n,m) \in vcnt
	// but, this could collide with some other sum

	return 0;
}