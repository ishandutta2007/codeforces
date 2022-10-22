#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144 * 4LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = time(NULL);
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}

#define int ll
int ans[1000][1000];
pair<int, int> settings[1000][1000];
void solve() {
	int n;
	cin >> n;
	REP(i, n) {
		REP(q, n) {
			cin >> settings[i][q].first >> settings[i][q].second;
			if (settings[i][q].first != -1) {
				settings[i][q].first--;
				settings[i][q].second--;
			}
		}
	}
	REP(i, n) {
		REP(q, n) {
			ans[i][q] = -1;
		}
	}
	const int dx[4] = { 1,-1,0,0 };
	const int dy[4] = { 0,0,1,-1 };

	queue<pair<int, int>> next;
	REP(i, n) {
		REP(q, n) {
			if (settings[i][q] == mp(i, q)) {
				ans[i][q] = 0;
				next.push(mp(i, q));
			}
		}
	}

	while (next.empty() == false) {
		pair<int, int> now = next.front();
		next.pop();
		REP(q, 4) {
			int x = now.first + dx[q];
			int y = now.second + dy[q];
			if (x >= 0 && x < n && y >= 0 && y < n) {
				if (ans[x][y] == -1 && settings[x][y] == settings[now.first][now.second]) {
					ans[x][y] = 1 + (q ^ 1);
					next.push(mp(x, y));
				}
			}
		}
	}

	REP(i, n) {
		REP(q, n) {
			if (settings[i][q].first == -1) continue;
			if (ans[i][q] == -1) {
				cout << "INVALID" << endl;
				return;
			}
		}
	}

	REP(i, n) {
		REP(q, n) {
			if (settings[i][q].first == -1) {
				REP(j, 4) {
					int x = i + dx[j];
					int y = q + dy[j];
					if (x >= 0 && x < n && y >= 0 && y < n) {
						if (ans[x][y] == -1) {
							ans[x][y] = 1 + (1 ^ j);
							ans[i][q] = 1 + j;
							next.push(mp(x, y));
							next.push(mp(i, q));
							break;
						}
					}
				}
			}
		}
	}

	while (next.empty() == false) {
		pair<int, int> now = next.front();
		next.pop();
		REP(q, 4) {
			int x = now.first + dx[q];
			int y = now.second + dy[q];
			if (x >= 0 && x < n && y >= 0 && y < n) {
				if (ans[x][y] == -1) {
					ans[x][y] = 1 + (q ^ 1);
					next.push(mp(x, y));
				}
			}
		}
	}

	REP(i, n) {
		REP(q, n) {
			if (ans[i][q] == -1) {
				cout << "INVALID" << endl;
				return;
			}
		}
	}

	{
		string ans_st = "XDURL";
		cout << "VALID" << endl;
		REP(i, n) {
			REP(q, n) {
				cout << ans_st[ans[i][q]];
			}
			cout << endl;
		}
	}
	return;
}
#undef int

int main() {
	init();
	solve();
}