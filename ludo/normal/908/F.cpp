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

int cost = 0;

int find_route(vi &v, int a, int b)
{
	int l = 0, r = v.size() - 1, sum = 0;
	while (l <= r) {
		if (!b || (a && v[l] - a < b - v[r])) {
			sum += v[l] - a;
			a = v[l++];
		} else {
			sum += b - v[r];
			b = v[r--];
		}
	}
	v.clear();
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vi rs, bs;
	int lastG = 0;
	REP(i, N) {
		int P;
		char C;
		cin >> P >> C;

		if (C == 'G') {
			int opt1 = find_route(rs, lastG, P) + find_route(bs, lastG, P);
			int opt2 = P - lastG;
			if (lastG) cost += P - lastG;
			cost += lastG && opt2 < opt1 ? opt2 : opt1;
			lastG = P;
		} else if (C == 'R') {
			rs.pb(P);
		} else if (C == 'B') {
			bs.pb(P);
		}
	}
	if (lastG) {
		cost += find_route(rs, lastG, 0);
		cost += find_route(bs, lastG, 0);
	} else {
		if (!rs.empty()) cost += rs.back() - rs.front();
		if (!bs.empty()) cost += bs.back() - bs.front();
	}
	cout << cost << endl;
	return 0;
}