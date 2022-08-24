#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 1200;
const int MAXM = 12000;
const ll INF = 1e9 + 1000;

struct edge {
	int u, v;
	ll w;
};
int n, m;

edge ed[MAXM];
ll dd[MAXN];
vector<pair<int, ll> > eds[MAXN];
set<pair<ll, int > > ss;
int s, t;

ll get(int x) {
	for (int i = 0; i < n; ++i)
		dd[i] = INF;
	dd[s] = 0;
	for (int i = 0; i < n; ++i)
		eds[i].clear();
	for (int i = 0; i < m; ++i) {
		if (ed[i].w != 0) {
			eds[ed[i].u].push_back(make_pair(ed[i].v, ed[i].w));
			eds[ed[i].v].push_back(make_pair(ed[i].u, ed[i].w));
		}
		else {
			if (i < x) {
				eds[ed[i].u].push_back(make_pair(ed[i].v, 1ll));
				eds[ed[i].v].push_back(make_pair(ed[i].u, 1ll));
			}
			else {
				eds[ed[i].u].push_back(make_pair(ed[i].v, INF));
				eds[ed[i].v].push_back(make_pair(ed[i].u, INF));
			}
		}
	}
	ss.clear();
	for (int i = 0; i < n; ++i)
		ss.insert(make_pair(dd[i], i));
	while (!ss.empty()) {
		int v = ss.begin()->second;
		ss.erase(ss.begin());
		for (pair<int, ll> e: eds[v]) {
			int u = e.first;
			if (dd[u] > dd[v] + e.second) {
				ss.erase(make_pair(dd[u], u));
				dd[u] = dd[v] + e.second;
				ss.insert(make_pair(dd[u], u));
			}
		}
	}
	return dd[t];
}

ll get2(int x, ll y) {
	for (int i = 0; i < n; ++i)
		dd[i] = INF;
	dd[s] = 0;
	for (int i = 0; i < n; ++i)
		eds[i].clear();
	for (int i = 0; i < m; ++i) {
		if (ed[i].w != 0) {
			eds[ed[i].u].push_back(make_pair(ed[i].v, ed[i].w));
			eds[ed[i].v].push_back(make_pair(ed[i].u, ed[i].w));
		}
		else {
			if (i < x) {
				eds[ed[i].u].push_back(make_pair(ed[i].v, 1ll));
				eds[ed[i].v].push_back(make_pair(ed[i].u, 1ll));
			}
			else if (i > x) {
				eds[ed[i].u].push_back(make_pair(ed[i].v, INF));
				eds[ed[i].v].push_back(make_pair(ed[i].u, INF));
			}
			else {
				eds[ed[i].u].push_back(make_pair(ed[i].v, y));
				eds[ed[i].v].push_back(make_pair(ed[i].u, y));
			}
		}
	}
	ss.clear();
	for (int i = 0; i < n; ++i)
		ss.insert(make_pair(dd[i], i));
	while (!ss.empty()) {
		int v = ss.begin()->second;
		ss.erase(ss.begin());
		for (pair<int, ll> e: eds[v]) {
			int u = e.first;
			if (dd[u] > dd[v] + e.second) {
				ss.erase(make_pair(dd[u], u));
				dd[u] = dd[v] + e.second;
				ss.insert(make_pair(dd[u], u));
			}
		}
	}
	return dd[t];
}

int main() {
	ll L;
	cin >> n >> m >> L >> s >> t;
	for (int i = 0; i < m; ++i)
		cin >> ed[i].u >> ed[i].v >> ed[i].w;
	if (get(0) < L || get(m) > L) {
		cout << "NO\n";
		return 0;
	}
	int l = -1;
	int r = m + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (get(mid) >= L)
			l = mid;
		else
			r = mid;
	}
	if (l != -1) {
		cout << "YES\n";
		ll xx = INF;
		if (get(l) != L) {
			ll lb = 1;
			ll rb = INF;
			while (rb - lb > 1) {
				ll mid = (lb + rb) >> 1;
				if (get2(l, mid) > L)
					rb = mid;
				else
					lb = mid;
			}
			xx = lb;
		}
		for (int i = 0; i < m; ++i) {
			cout << ed[i].u << " " << ed[i].v << " ";
			if (ed[i].w != 0) {
				cout << ed[i].w << "\n";
			}
			else {
				if (i < l)
					cout << 1 << "\n";
				else if (i > l)
					cout << INF << "\n";
				else
					cout << xx << "\n";
			}
		}
	}
	else {
		cout << "NO\n";
	}
	return 0;
}