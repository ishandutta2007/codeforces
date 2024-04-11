#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 2 * 1e+10;

vector<vector<ll> > graph;
vector<bool> fail;
vector<ll> nearfail;
ll resnum = 0, resden = 1;
ll cnt;

void dfs(ll v) {
	fail[v] = true;
	cnt++;
	for (ll i = 0; i < graph[v].size(); i++)
		if (!fail[graph[v][i]]) {
			nearfail[graph[v][i]]++;
			if (nearfail[graph[v][i]] * resden > resnum * graph[graph[v][i]].size())
				dfs(graph[v][i]);
		}
}

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, m, k, i, a, b;
	cin >> n >> m >> k;
	graph = vector<vector<ll> >(n);
	vector<bool> strong(n, false);
	nearfail = vector<ll>(n);
	fail = vector<bool>(n);

	for (i = 0; i < k; i++) {
		cin >> a;
		strong[--a] = true;
	}

	for (i = 0; i < m; i++) {
		cin >> a >> b;
		graph[--a].push_back(--b);
		graph[b].push_back(a);
	}

	ll ansnum = 1, ansden = 1;
	
	while (resden < inf) {
		cnt = 0;
		for (i = 0; i < n; i++) {
			nearfail[i] = 0;
			fail[i] = false;
		}
		for (i = 0; i < n; i++)
			if (strong[i] && !fail[i])
				dfs(i);
		resnum <<= 1;
		resden <<= 1;
		if (cnt == n)
			resnum++;
		else {
			ansnum = resnum >> 1;
			ansden = resden >> 1;
			resnum--;
		}
	}
	
	cnt = 0;
	for (i = 0; i < n; i++) {
		nearfail[i] = 0;
		fail[i] = false;
	}
	resnum = ansnum;
	resden = ansden;
	for (i = 0; i < n; i++)
		if (strong[i] && !fail[i])
			dfs(i);

	cout << n - cnt << '\n';
	for (i = 0; i < n; i++)
		if (!fail[i])
			cout << i + 1 << ' ';

	return 0;
}