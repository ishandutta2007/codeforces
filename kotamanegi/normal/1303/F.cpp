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
	//iostream::sync_with_stdio(false);
	//cout << fixed << setprecision(20);
}

pair<int, int> union_tree[300][300];
pair<int, int> union_find(pair<int, int> now) {
	if (now == union_tree[now.first][now.second]) return now;
	return union_tree[now.first][now.second] = union_find(union_tree[now.first][now.second]);
}
int union_merge(pair<int, int> a, pair<int, int> b) {
	a = union_find(a);
	b = union_find(b);
	if (a == b) return 0;
	union_tree[a.first][a.second] = b;
	return 1;
}


int ans[4000000];

vector<int> nearest[400][400];

vector<vector<tuple<int, int, int>>> queries;

int ok[400][400];

priority_queue<tuple<int, int, int>> next_erase;

void solve(){
	int n, m, query;
	scanf("%d%d%d", &n, &m, &query);
	REP(i, n) {
		REP(q, m) {
			union_tree[i][q] = mp(i, q);
		}
	}
	queries.push_back(vector<tuple<int, int, int>>());

	REP(i, n) {
		REP(q, m) {
			queries[0].push_back(make_tuple(-1, i, q));
			nearest[i][q].push_back(-1);
		}
	}
	vector<tuple<int, int, int>> placeholder;
	map<int, int> compress;
	REP(i, query) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		nearest[a][b].push_back(i);
		compress[c] = 1;
		placeholder.push_back(make_tuple(a, b, c));
	}
	int tmp_comp = 1;
	for (auto x = compress.begin(); x != compress.end(); ++x) {
		x->second = tmp_comp;
		queries.push_back(vector<tuple<int, int, int>>());
		tmp_comp++;
	}
	REP(i, placeholder.size()) {
		int a = get<0>(placeholder[i]), b = get<1>(placeholder[i]), c = get<2>(placeholder[i]);
		c = compress[c];
		queries[c].push_back(make_tuple(i, a, b));
	}
	for (int c = 0; c < tmp_comp; ++c) {

		REP(j, queries[c].size()) {
			pair<int, int> now_place = mp(get<1>(queries[c][j]), get<2>(queries[c][j]));
			if (ok[now_place.first][now_place.second] == 1) continue;
			ok[now_place.first][now_place.second] = 1;
			int dx[4] = { 1,-1,0,0 };
			int cnter = 1;
			REP(t, 4) {
				int nx = now_place.first + dx[t];
				int ny = now_place.second + dx[3 - t];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (ok[nx][ny] == 1) {
						cnter -= union_merge(mp(nx, ny), now_place);
					}
				}
			}
			ans[max(0,get<0>(queries[c][j]))] += cnter;
		}

		REP(j, queries[c].size()) {
			pair<int, int> now_place = mp(get<1>(queries[c][j]), get<2>(queries[c][j]));
			union_tree[now_place.first][now_place.second] = now_place;
			ok[now_place.first][now_place.second] = 0;
		}


		for (int j = ((int)queries[c].size()) - 1; j >= 0;--j) {
			pair<int, int> now_place = mp(get<1>(queries[c][j]), get<2>(queries[c][j]));
			if (ok[now_place.first][now_place.second] != 0) continue;
			ok[now_place.first][now_place.second] = 1;
			auto x = lower_bound(ALL(nearest[now_place.first][now_place.second]), get<0>(queries[c][j]) + 1);
			if (x == nearest[now_place.first][now_place.second].end()) {
				//nothing happens.
				int dx[4] = { 1,-1,0,0 };
				REP(t, 4) {
					int nx = now_place.first + dx[t];
					int ny = now_place.second + dx[3 - t];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
						if (ok[nx][ny] == 1) {
							union_merge(mp(nx, ny), now_place);
						}
					}
				}
			}
			else {
				//delate next.
				ok[now_place.first][now_place.second] = 2;
				next_erase.push(make_tuple(*x, now_place.first, now_place.second));
			}
		}

		while (next_erase.empty() == false) {
			tuple<int, int, int> now = next_erase.top();
			next_erase.pop();
			pair<int, int> now_place = mp(get<1>(now), get<2>(now));

			ok[now_place.first][now_place.second] = 1;
			int dx[4] = { 1,-1,0,0 };
			int cnter = 1;
			REP(t, 4) {
				int nx = now_place.first + dx[t];
				int ny = now_place.second + dx[3 - t];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (ok[nx][ny] == 1) {
						cnter -= union_merge(mp(nx, ny), now_place);
					}
				}
			}
			ans[get<0>(now)] -= cnter;
		}

		REP(j, queries[c].size()) {
			pair<int, int> now_place = mp(get<1>(queries[c][j]), get<2>(queries[c][j]));
			union_tree[now_place.first][now_place.second] = now_place;
			ok[now_place.first][now_place.second] = 0;
		}

	}

	for (int i = 0; i < query; ++i) {
		printf("%d\n", ans[i]);
		ans[i + 1] += ans[i];
	}
	return;
}
#undef int
int main() {
	init();
	solve();
}