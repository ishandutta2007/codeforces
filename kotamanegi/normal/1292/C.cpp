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
vector<pair<int,int>> vertexs[3000];
int cnt[3000][3000]; //edgenum,vertex
void dfs(int now,int back,int edgenum) {
	cnt[edgenum][now] = 1;
	for (auto x : vertexs[now]) {
		if (x.first == back) continue;
		dfs(x.first, now, edgenum);
		cnt[edgenum][now] += cnt[edgenum][x.first];
	}
	return;
}
int dp[3000][3000];
int visited[3000][3000];
queue<tuple<int, int, int, int>> nexts;
void solve(){
	int n;
	cin >> n;
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		vertexs[a].push_back(mp(b, i));
		vertexs[b].push_back(mp(a, i));
	}
	REP(i, n) {
		for (auto x : vertexs[i]) {
			dfs(x.first, i, x.second);
			dfs(i, x.first, x.second);
			nexts.push(make_tuple(i, x.second, x.first, x.second));
			dp[i][x.first] += cnt[x.second][i] * cnt[x.second][x.first];
			visited[i][x.first] = 1;
		}
	}
	while (nexts.empty() == false) {
		tuple<int, int, int, int> now = nexts.front();
		nexts.pop();
		//first we need to append 0
		int first_cost = dp[get<0>(now)][get<2>(now)];
		{
			for (auto x : vertexs[get<2>(now)]) {
				if (x.second == get<3>(now)) continue;//already
				int cost = cnt[get<1>(now)][get<0>(now)] * cnt[x.second][x.first];
				cost += first_cost;
				if (dp[get<0>(now)][x.first] < cost) {
					dp[get<0>(now)][x.first] = cost;
				}
				if (visited[get<0>(now)][x.first] == 0) {
					visited[get<0>(now)][x.first] = 1;
					nexts.push(make_tuple(get<0>(now), get<1>(now), x.first, x.second));
				}
			}
		}
		//second we need to append 2
		{
			for (auto x : vertexs[get<0>(now)]) {
				if (x.second == get<1>(now)) continue;//already
				int cost = cnt[get<3>(now)][get<2>(now)] * cnt[x.second][x.first];
				cost += first_cost;
				if (dp[x.first][get<2>(now)] < cost) {
					dp[x.first][get<2>(now)] = cost;
				}
				if (visited[x.first][get<2>(now)] == 0) {
					visited[x.first][get<2>(now)] = 1;
					nexts.push(make_tuple(x.first, x.second, get<2>(now), get<3>(now)));
				}
			}
		}
	}
	int ans = 0;
	REP(i, n) {
		REP(q, n) {
			ans = max(ans, dp[i][q]);
		}
	}
	cout << ans << endl;
}

#undef int
int main() {
	init();
	solve();
}