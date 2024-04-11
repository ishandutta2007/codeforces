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

const int maxn = 200000;

int N, K, X[maxn];
int mask;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	mask = (1 << K) - 1;
	REP(i, N) cin >> X[i];

	map<int, int> occ;
	occ[0]++;
	int pf = 0;
	REP(i, N) {
		pf ^= X[i];
		occ[min(pf, ~pf & mask)]++;
	}

	ll ret = 1LL * N * (N + 1) / 2;
	for (auto it : occ) {
		int n = it.y;
		int ln = n / 2, rn = n - ln;
		ret -= 1LL * ln * (ln - 1) / 2;
		ret -= 1LL * rn * (rn - 1) / 2;
	}
	cout << ret << endl;

	return 0;
}