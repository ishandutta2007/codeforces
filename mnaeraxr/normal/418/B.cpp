#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

struct Friend{
	int64 price;
	int mon, mask;

	bool operator <(const Friend &f) const{
		return mon < f.mon;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int64 b;

	cin >> n >> m >> b;

	vector<Friend> F(n);

	for (int i = 0; i < n; ++i){
		int64 x;
		int k, m;

		cin >> x >> k >> m;

		int mask = 0;

		for (int j = 0; j < m; ++j){
			int v; cin >> v;
			mask |= 1 << (v - 1);
		}

		F[i] = {x, k, mask};
	}

	int64 answer = oo;
	vector<int64> dp(1 << m, oo);
	dp[0] = 0;

	sort(F.begin(), F.end());

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < (1 << m); ++j){
			int np = F[i].mask | j;
			dp[ np ] = min( dp[np], dp[j] + F[i].price );
		}

		answer = min(answer, dp[ (1 << m) - 1 ] + b * F[i].mon);
	}

	if (answer == oo) cout << -1 << endl;
	else cout << answer << endl;

	// :)

	return 0;
}