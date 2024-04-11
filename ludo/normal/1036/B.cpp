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

ll run()
{
	ll dx, dy, k;
	cin >> dx >> dy >> k;

	if (dx > dy) swap(dx, dy);

	// dx <= dy
	if (k < dy) {
		// It is not possible to reach the goal in time.
		return -1;
	}

	ll diff = k - dy;
	assert(diff >= 0);

	if (dx == dy) {
		if (diff % 2 == 0) {
			// go back and forth, diagonally.
			return k;
		} else {
			// on the first move, go up, then right, and after that, continue diagonally.
			return k - 2;
		}
	}

	ll delta = dy - dx;

	if (delta % 2 == 0) {
		if (diff % 2 == 0) {
			return k;
		} else {
			return k - 2;
		}
	} else {
		// delta is odd...
		if (diff % 2 == 0) {
			return k - 1;
		} else {
			return k - 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int q;
	cin >> q;
	while (q--) {
		ll ans = run();
		cout << ans << endl;
	}
	return 0;
}