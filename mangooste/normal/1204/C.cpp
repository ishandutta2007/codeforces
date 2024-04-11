//#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES

//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <cstdio>

#define FAST ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr)
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FIXED cout << fixed << setprecision(10)
#define all(a) begin(a), end(a)
#define pb(a) push_back(a)
#define rep(i, l, r) for(int i = l; i < r; ++i)
#define sz(a) a.size()

typedef long long ll;
typedef long double ld;

using namespace std;

const int N = 101;
const int inf = 1e9;

int n, m, dist[N][N];
char g[N][N];
vector <int> p;

signed main() {
	FAST;
	FIXED;
	cin >> n;
	rep(i, 0, n) {
		rep(j, 0, n) {
			char tmp; 
			cin >> tmp;
			g[i][j] = (tmp == '1') ? 1 : 0;
		}
	}
	cin >> m;
	p.resize(m);
	rep(i, 0, m) {
		cin >> p[i];
		p[i]--;
	}
	rep(i, 0, n) {
		rep(j, 0, n) {
			if (i == j) {
				dist[i][i] = 0;
				continue;
			}
			if (g[i][j]) {
				dist[i][j] = 1;
			}
			else {
				dist[i][j] = inf;
			}
		}
	}
	rep(k, 0, n) {
		rep(i, 0, n) {
			rep(j, 0, n) {
				if (dist[i][k] < inf && dist[k][j] < inf && i != j) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
	vector <int> ans = { p[0] + 1 };
	int pr = 0;
	rep(i, 1, m) {
		if (dist[p[pr]][p[i]] != i - pr) {
			pr = i - 1;
			ans.push_back(p[i - 1] + 1);
		}
	}
	ans.push_back(p[m - 1] + 1);
	cout << sz(ans) << '\n';
	rep(i, 0, sz(ans)) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}