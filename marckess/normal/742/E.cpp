#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, a, b;
vvi adj;
vi col;
queue<int> x, y;

void colorear (int u, int c) {
	col[u] = c;

	for (int v : adj[u])
		if (col[v] == -1)
			colorear(v, 1-c);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	adj = vvi(2*n+2);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
		x.push(a);
		y.push(b);

		if (a % 2) {
			adj[a].push_back(a+1);
			adj[a+1].push_back(a);
		}

		if (b % 2) {
			adj[b].push_back(b+1);
			adj[b+1].push_back(b);
		}
	}

	col = vi(2*n+2, -1);
	for (int i = 1; i <= 2*n; i++) {
		if (col[i] == -1) {
			colorear(i, 0);
		}
	}

	while (n--) {
		cout << col[x.front()] + 1 << " " << col[y.front()] + 1 << endl;
		x.pop();
		y.pop();
	}

	return 0;
}