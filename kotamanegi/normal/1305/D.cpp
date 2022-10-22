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
vector<int> vertexs[2000];
int die[2000];
int query(int a, int b) {
	a++; b++;
	cout << "? " << a << " " << b << endl;
	int ge;
	cin >> ge;
	ge--;
	return ge;
}

int depth[2000];
void depth_dfs(int now,int back) {
	for (auto x : vertexs[now]) {
		if (x == back) continue;
		if (die[x] == true) continue;
		depth[x] = depth[now] + 1;
		depth_dfs(x, now);
	}
}

int check_dfs(int now,int back,pair<int, int> bads) {
	if (now == bads.first || now == bads.second) return 1;
	for (auto x : vertexs[now]) {
		if (x == back) continue;
		if (die[x] == true) continue;
		if (check_dfs(x, now, bads) == 1) {
			return 1;
		}
	}
	return 0;
}

void erase_dfs(int now, int back) {
	die[now] = 1;
	for (auto x : vertexs[now]) {
		if (x == back) continue;
		if (die[x] == true) continue;
		erase_dfs(x, now);
	}
}

void solve(){
	int n;
	cin >> n;
	REP(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}

	while (true) {
		REP(i, n) {
			depth[i] = 0;
		}
		REP(i, n) {
			if (die[i] == true) continue;
			depth_dfs(i, -1);
			int now_max = 0;
			REP(q, n) {
				if (depth[q] > depth[now_max]) {
					now_max = q;
				}
			}
			depth[now_max] = 0;
			depth_dfs(now_max, -1);
			int target = now_max;
			REP(q, n) {
				if (depth[q] > depth[now_max]) {
					now_max = q;
				}
			}
			int ans = query(target, now_max);
			for (auto x : vertexs[ans]) {
				if (die[x] == true) continue;
				if (check_dfs(x, ans, mp(target, now_max)) == 1) {
					erase_dfs(x, ans);
				}
			}
			break;
		}

		int ok = 0;
		REP(i, n) {
			if (die[i] == false) ok++;
		}
		if (ok == 1) break;
	}

	REP(i, n) {
		if (die[i] == 0) {
			cout << "! " << i + 1 << endl;
			return;
		}
	}
	assert(0 == 1); //shouldn't reach here.
}

#undef int

int main() {
	init();
	solve();
}