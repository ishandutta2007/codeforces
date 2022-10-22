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
vector<int> vertexs[300000];
int ans = 0;
tuple<int, int, int> kouho;
pair<int,int> cnt[300000];
void cnt_dfs(int now, int back) {
	cnt[now].second = now;
	for (auto x : vertexs[now]) {
		if (x == back) continue;
		cnt_dfs(x, now);
		if (cnt[now].first < cnt[x].first) {
			cnt[now] = cnt[x];
		}
	}
	cnt[now].first++;
	return;
}
void dp_dfs(int now, pair<pair<int,int>,int> back) {
	if (cnt[now].first == 1) return;
	vector<pair<pair<int, int>, int>> next;
	for (auto x : vertexs[now]) {
		if (x == back.second) continue;
		next.push_back(mp(cnt[x], x));
	}
	next.push_back(back);
	sort(ALL(next));
	reverse(ALL(next));
	if (next.size() >= 3) {
		int go = next[2].first.first + next[0].first.first + next[1].first.first;
		if (ans < go) {
			ans = go;
			kouho = make_tuple(next[2].first.second, next[0].first.second, next[1].first.second);
		}
	}
	else if (next.size() == 2&&back.second != now) {
		int go = next[0].first.first + next[1].first.first;
		if (ans < go) {
			ans = go;
			kouho = make_tuple(next[0].first.second, next[1].first.second, now);
		}
	}
	for (auto x : vertexs[now]) {
		if (x == back.second) continue;
		pair<pair<int, int>, int> next_go;
		for (int q = 0; q < next.size(); ++q) {
			if (next[q].second == x) continue;
			next_go = next[q];
			break;
		}
		next_go.first.first++;
		next_go.second = now;
		dp_dfs(x, next_go);
	}
}
void solve(){
	int n;
	cin >> n;
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	cnt_dfs(1, -1);
	dp_dfs(1, mp(mp(0, 1), 1));
	cout << ans << endl;
	cout << get<0>(kouho) << " " << get<1>(kouho) << " " << get<2>(kouho) << endl;
	return;
}
#undef int
int main() {
	init();
	solve();
}