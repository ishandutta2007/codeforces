#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj(2005);
vi v;
int n, k, a;

int obtRes (int u) {
	vi d(2005, -1);
	queue<int> q;

	for (int v : adj[u]) {
		d[v] = 1;
		q.push(v);
	}

	while (q.size()) {
		u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}

	return d[1000];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> a;
		v.push_back(a-n);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i <= 2000; i++) {
		for (int j : v) {
			a = i + j;

			if (0 <= a && a <= 2000)
				adj[i].push_back(a);
		}
	}

	cout << obtRes(1000) << endl;

	return 0;
}