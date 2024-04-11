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

const int maxn = 2e6 + 100;

ll n, dx[maxn], dy[maxn], tx, ty;

bool test(ll k)
{
	for (ll l = 0; l + k <= n; l++) {
		ll nx = dx[n] + dx[l] - dx[l + k];
		ll ny = dy[n] + dy[l] - dy[l + k];
		if (abs(nx - tx) + abs(ny - ty) <= k) {
			// cerr << k << " " << l << " valid" << endl;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	cin >> n >> S;

	dx[0] = dy[0] = 0;
	REP(i, n) {
		char ch = S[i];
		dx[i + 1] = dx[i];
		dy[i + 1] = dy[i];
		if (ch == 'U') dy[i+1]++;
		if (ch == 'D') dy[i+1]--;
		if (ch == 'L') dx[i+1]--;
		if (ch == 'R') dx[i+1]++;
	}

	cin >> tx >> ty;

	if (!test(n) || (n - tx - ty) % 2 != 0) {
		cout << "-1" << endl;
		return 0;
	}

	ll lo = -1, hi = n;

	assert(!test(lo));
	assert(test(hi));

	while (hi - lo > 1) {
		ll mi = (lo + hi) / 2;
		if (test(mi)) hi = mi;
		else lo = mi;
	}
	assert(test(hi));
	cout << hi << endl;
	return 0;
}