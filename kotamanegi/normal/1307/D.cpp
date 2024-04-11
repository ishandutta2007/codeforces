#include "bits/stdc++.h"
#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS

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

#define int ll
vector<int> vertexs[300000];
int specials[300000];
int dist[2][300000];
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	REP(i, k) {
		int a;
		cin >> a;
		a--;
		specials[a] = 1;
	}
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	REP(t, 2) {
		REP(i, n) {
			dist[t][i] = 1e9;
		}
		queue<int> next;
		if (t == 0) {
			dist[t][0] = 0;
			next.push(0);
		}
		else {
			dist[t][n - 1] = 0;
			next.push(n - 1);
		}
		while (next.empty() == false) {
			int now = next.front();
			next.pop();
			REP(q, vertexs[now].size()) {
				int go = vertexs[now][q];
				if (dist[t][go] > dist[t][now] + 1) {
					dist[t][go] = dist[t][now] + 1;
					next.push(go);
				}
			}
		}
	}
	int ans = 0;
	vector<pair<int, int>> going;
	REP(i, n) {
		if (specials[i] == 0) continue;
		going.push_back(mp(dist[0][i], i));
	}
	sort(ALL(going));
	priority_queue<pair<int, int>> next;
	REP(i, n) {
		next.push(mp(dist[1][i], i));
	}
	REP(i, going.size()) {
		specials[going[i].second] = 0;
		while (next.empty() == false && specials[next.top().second] == 0) {
			next.pop();
		}
		if (next.empty() == true) break;
		int val = going[i].first + 1;
		val += next.top().first;
		ans = max(ans, val);
	}
	ans = min(ans, dist[0][n-1]);
	cout << ans << endl;
}

#undef int
int main() {
	init();
	solve();
}