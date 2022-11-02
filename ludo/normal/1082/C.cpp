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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vvi v(m);

	REP(i, n) {
		int s, t;
		cin >> s >> t;
		v[s - 1].pb(t);
	}

	vi ps(n, 0);
	REP(i, m) {
		sort(all(v[i]), greater<int>());
		for (int j = 1; j < (int) v[i].size(); j++) {
			v[i][j] += v[i][j - 1];
		}
		REP(j, (int) v[i].size()) {
			ps[j] += max(0, v[i][j]);
		}
	}

	int ret = 0;
	REP(i, n) ret = max(ret, ps[i]);
	cout << ret << endl;
	return 0;
}