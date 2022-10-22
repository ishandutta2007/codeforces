#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1000000007;

ll power(ll a, ll b) {
	if (!b)
		return 1;
	ll res = power(a, b / 2);
	res = (res * res) % inf;
	if (b & 1)
		res = (res * a) % inf;
	return res;
}

vector<vector<pair<ll, bool> > > edges;
vector<short int> color;

bool dfs(ll v, short int clr) {
	bool res = true;
	color[v] = clr;
	short int newclr;
	for (ll i = 0; i < edges[v].size(); i++) {
		newclr = (edges[v][i].second ? clr : -clr);
		if (color[edges[v][i].first] == 0)
			res = res && dfs(edges[v][i].first, newclr);
		if (!res || (color[edges[v][i].first] == -newclr))
			return false;
	}
	return res;
}

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, m, i, a, b, c;
	cin >> n >> m;
	edges = vector<vector<pair<ll, bool> > >(n);
	color = vector<short int>(n, 0);
	for (i = 0; i < m; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));
	}

	ll res = -1;
	bool succ = true;
	for (i = 0; (i < n) && succ; i++)
		if (!color[i]) {
			succ = succ && dfs(i, 1);
			res++;
		}

	if (!succ)
		cout << 0;
	else
		cout << power(2, res);

	return 0;
}