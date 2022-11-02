//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

ii nxt(ii cur, int width) {
	if (cur.x % 2 == 0) {
		// move right
		if (cur.y + 1 < width)
			return ii(cur.x, cur.y + 1);
		return ii(cur.x + 1, cur.y);
	} else {
		// move left
		if (cur.y > 0)
			return ii(cur.x, cur.y - 1);
		return ii(cur.x + 1, cur.y);
	}
}

char getch(int i) {
	if (i < 10) return '0' + i;
	if (i < 36) return 'a' + i - 10;
	return 'A' + i - 36;
}

void run() {
	int r, c, k;
	cin >> r >> c >> k;

	vector<vector<bool>> rice;
	vector<string> ans;

	int nrice = 0;
	REP(i, r) {
		string S;
		cin >> S;
		vector<bool> row(c, false);
		REP(j, c) {
			row[j] = (S[j] == 'R');
			nrice += row[j];
		}
		rice.pb(row);
		ans.pb(string(c, '.'));
	}

	int cur_k = 0, nseen = 0;

	int avg_chick = nrice / k;
	int ks_plus = nrice % k;

	ii cur(0,0);
	while (cur.x < r) {
		if (rice[cur.x][cur.y]) {
			nseen++;
			if (nseen > avg_chick + (cur_k < ks_plus)) {
				nseen = 1;
				cur_k++;
			}
		}

		ans[cur.x][cur.y] = getch(cur_k);
		cur = nxt(cur, c);
	}

	REP(i, r)
		cout << ans[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		run();
	}

	return 0;
}