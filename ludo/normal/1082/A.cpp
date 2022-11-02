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

const ll INF = 1e12;

void run()
{
	ll n, x, y, d;
	cin >> n >> x >> y >> d;

	ll ans = INF;
	if (abs(y - x) % d == 0)
		ans = min(ans, abs(y - x) / d);
	
	// touch lhs
	if (abs(y - 1) % d == 0) {
		ans = min(ans, (x - 1 + d - 1) / d + abs(y - 1) / d);
	}

	// touch rhs
	if (abs(y - n) % d == 0) {
		ans = min(ans, (n - x + d - 1) / d + abs(y - n) / d);
	}

	if (ans == INF) ans = -1;
	cout << ans << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	while(n--) run();

	return 0;
}