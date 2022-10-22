#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144*2LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}

int colorALL[40][40];
int distALL[40][1001][1001];

vector<pair<int, int>> should_go[40];
vector<vector<int>> inputs;
queue<pair<int, int>> next_go[50];

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	REP(i, n) {
		inputs.push_back(vector<int>());
		REP(q, m) {
			int a;
			cin >> a;
			a--;
			inputs.back().push_back(a);
			should_go[a].push_back(mp(i, q));
		}
	}

	REP(i, k) {
		REP(q, k) {
			colorALL[i][q] = -1;
		}
		REP(q, n) {
			REP(j, m) {
				distALL[i][q][j] = 1e7;
			}
		}
	}

	REP(i, n) {
		REP(q,m){
			distALL[inputs[i][q]][i][q] = 0;
			next_go[inputs[i][q]].push(mp(i, q));
		}
	}

	REP(i, k) {
		while (next_go[i].empty() == false) {
			pair<int, int> now = next_go[i].front();
			next_go[i].pop();
			int now_dist = distALL[i][now.first][now.second];
			if (colorALL[i][inputs[now.first][now.second]] == -1) {
				colorALL[i][inputs[now.first][now.second]] = now_dist + 1;
				

				REP(t, should_go[inputs[now.first][now.second]].size()) {
					int q = should_go[inputs[now.first][now.second]][t].first;
					int j = should_go[inputs[now.first][now.second]][t].second;
					if (inputs[now.first][now.second] == inputs[q][j]) {
						if (distALL[i][q][j] > now_dist + 1) {
							distALL[i][q][j] = now_dist + 1;
							next_go[i].push(mp(q, j));
						}
					}
				}


			}
			int dx[4] = {1,-1,0,0};
			REP(q, 4) {
				int x = now.first + dx[q];
				int y = now.second + dx[3 - q];
				if (x >= 0 && x < n && y >= 0 && y < m) {
					if (distALL[i][x][y] > now_dist + 1) {
						distALL[i][x][y] = now_dist + 1;
						next_go[i].push(mp(x, y));
					}
				}
			}
		}
	}

	int query;
	cin >> query;
	REP(te, query) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		int colorALLdist[40] = {};
		REP(j, 40) {
			colorALLdist[j] = 1e7;
		}
		colorALLdist[inputs[a][b]] = 1;

		int ans = abs(a - c) + abs(d - b);

		queue<tuple<int, int, int>> now_here;
		now_here.push(make_tuple(0, a, b));
		while (now_here.empty() == false) {
			tuple<int, int, int> now = now_here.front();
			now_here.pop();
			int dx[4] = { 1,-1,0,0 };
			REP(t, 4) {
				int x = get<1>(now) + dx[t];
				int y = get<2>(now) + dx[3-t];
				if (x >= 0 && x < n && y >= 0 && y < m) {
					colorALLdist[inputs[x][y]] = min(colorALLdist[inputs[x][y]], get<0>(now) + 2);
					if (colorALLdist[inputs[x][y]] == get<0>(now) + 2) {
						//ok
						now_here.push(make_tuple(get<0>(now) + 1, x, y));
					}
				}
			}
		}
		int donot[50] = {};
		REP(t, k) {
			int now_min = 0;
			REP(q, k) {
				if (donot[q] == 1e7) continue;
				if (donot[now_min] == 1e7||colorALLdist[q] < colorALLdist[now_min]) {
					now_min = q;
				}
			}
			ans = min(ans, colorALLdist[now_min] + distALL[now_min][c][d]);
			REP(j, k) {
				colorALLdist[j] = min(colorALLdist[j], colorALLdist[now_min] + colorALL[now_min][j]);
			}
			donot[now_min] = 1e7;
		}
		cout << ans << endl;
	}
}
#undef int

int main() {
	init();
	solve();
}