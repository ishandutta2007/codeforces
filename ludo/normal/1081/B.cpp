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

	int n;
	cin >> n;
	vi A(n);
	for (int &x:A)cin>>x;

	vvi occ(n + 1);
	int it = 0;
	for (int x:A) occ[n-x].pb(it++);

	assert(occ[0].empty());
	vi ans(n);
	int cursum = 1;
	for (int i = 1; i <= n; i++) {
		if (occ[i].empty()) continue;
		int sz = (int) occ[i].size();
		if (sz % i != 0) return printf("Impossible\n"), 0;

		for (int j = 0; j < sz; j++)
			ans[occ[i][j]] = cursum + j / i;
		cursum += sz / i;
	}

	printf("Possible\n");
	REP(i, n) printf("%d%c", ans[i], " \n"[i==n-1]);

	return 0;
}