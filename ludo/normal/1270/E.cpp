#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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

vi n[2][2] = {};

vi merge(vi &a, vi &b) {
	vi r;
	r.insert(r.end(), all(a));
	r.insert(r.end(), all(b));
	return r;
}

int output(vi v) {
	cout << v.size() << endl;
	for (int x : v) cout << (x+1) << " ";
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vii v(N);
	for (auto &pr : v) {
		cin >> pr.x >> pr.y;
		pr.x += 1000000;
		pr.y += 1000000;
	}

	while (true) {
		REP(i, 2) REP(j, 2) {
			n[i][j].clear();
		}

		REP(i, N) {
			n[v[i].x % 2][v[i].y % 2].pb(i);
		}

		bool cont = false;
		REP(i, 2) REP(j, 2) {
			if (n[i][j].size() == N) {
				REP(_, N) {
					v[_].x /= 2;
					v[_].y /= 2;
				}
				cont = true;
			}
		}
		if (cont) continue;

		// process.
		// (00+11), (01+10) both nonempty:
		vi A = merge(n[0][0], n[1][1]);

		if (A.size() != 0 && A.size() != N) {
			return output(A);
		}

		if (A.empty()) return output(n[0][1]);
		else           return output(n[0][0]);
	}

	return 0;
}