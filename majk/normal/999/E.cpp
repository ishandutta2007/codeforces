#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>
#include <iomanip>
#include <limits>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long MAX = 5100000;
const long long INF = 1LL << 60;
const long long MOD = 1'000'000'007LL;
const long long mod = 998244353LL;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	/*
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	*/

	ll n, m, s; scanf("%lld %lld %lld", &n, &m, &s);
	s--;
	vector<vector<int>> g(n);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		a--; b--;
		g[a].push_back(b);
	}
	vector<bool> visited(n, false);
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()) {
		ll t = q.front();
		q.pop();
		for (auto x : g[t]) {
			if (visited[x]) continue;
			visited[x] = true;
			q.push(x);
		}
	}


	vector<vector<int>> reach(n);
	for (ll i = 0; i < n; i++) {
		if (visited[i]) continue;
		queue<int> q;
		vector<bool> used(n, false);
		q.push(i);
		used[i] = true;
		while (!q.empty()) {
			ll t = q.front();
			q.pop();
			if (!visited[t]) reach[i].push_back(t);
			for (auto x : g[t]) {
				if (used[x]) continue;
				used[x] = true;
				q.push(x);
			}
		}
	}
	
	vector<pair<int, int>> vp(n);
	for (ll i = 0; i < n; i++) {
		vp[i] = make_pair(reach[i].size(), i);
	}
	sort(vp.rbegin(), vp.rend());
	
	ll res = 0;
	for (auto e : vp) {
		if (reach[e.second].size() > 0 && !visited[reach[e.second][0]]) res++;
		for (ll to : reach[e.second]) {
			visited[to] = true;
		}
	}
	cout << res << endl;
	
	return 0;

}