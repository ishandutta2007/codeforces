#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(100);
}

#define int ll
int grid[2][1000000];
void solve(){
	int n, query;
	cin >> n >> query;
	queue<pair<int, int>> places;
	REP(i, query) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (grid[a][b] == 0) {
			grid[a][b] = 1;
			places.push(mp(a, b));
		}
		else {
			grid[a][b] = 0;
		}
		while (places.empty() == false) {
			pair<int, int> now = places.front();
			places.pop();
			if (grid[now.first][now.second] == 0) continue;
			int ok = 0;
			for (int q = -1; q <= 1; ++q) {
				int next_x = (now.first + 1) % 2;
				int next_y = now.second + q;
				if (next_y >= 0 && next_y < n) {
					if (grid[next_x][next_y] == 1) {
						ok = 1;
						break;
					}
				}
			}
			if (ok == 1) {
				places.push(now);
				break;
			}
			continue;
		}
		if (places.empty() == true) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return;
}

#undef int
int main() {
	init();
	solve();
}