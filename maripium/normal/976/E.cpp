#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

const int N = 3e5 + 5;

int n, a, b;
bool cmp(const pair<int,int> &lhs,const pair<int,int> &rhs) {
	return lhs.fi - lhs.se > rhs.fi - rhs.se;
}

vector<pair<int,int> > mts;
bool used[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b;
	for (int i = 0;i < n;++i) {
		int hp, dmg; cin >> hp >> dmg;
		mts.pb(mp(hp, dmg));
	}
	
	if (b == 0) {
		int res = 0;
		for (int i = 0;i < n;++i) res += mts[i].se;
		return cout << res,0;
	}
	
	sort(mts.begin(), mts.end(), cmp);
	
	// for (int i = 0;i < n;++i) cout << mts[i].fi << ' ' << mts[i].se << endl;
	int i = 0;
	int mn = 0, sum = 0;
	while(i < n) {
		if (mts[i].fi <= mts[i].se) {
			--i;
			break;
		}
		sum += mts[i].fi;
		used[i] = true;
		if (i + 1 == b) {
			mn = mts[i].fi - mts[i].se;
			break;
		}
		++i;
	}
	
	++i;
	// cout << i << endl;
	while (i < n) {
		sum += mts[i].se;
		++i;
	}
	
	// cout << sum << endl;
	int res = sum;
	for (int i = 0;i < n;++i) {
		int last = max(0LL, mts[i].fi - mts[i].se);
		int nxt = max(0LL, (1LL << a) * mts[i].fi - mts[i].se);
		int cur = sum + nxt;
		if (used[i]) cur -= last;
		else cur -= mn;
		res = max(res, cur);
		// cout << res << endl;
	}
	
	cout << res << endl;
}