#include <iostream>
#include <vector>

using namespace std;

const int inf = 1000 * 1000 * 1000;

int n;
vector< vector< int > > a;

bool read(int i, int j) {
	cin >> a[i][j];
	return (j < n?read(i, j + 1) : (i < n?read(i + 1, 1) : 0));
}

bool init(int i, int x) {
	a[i][i] = x;
	return (i < n?init(i + 1, x) : 0);
}

bool dfs(int k, int i, int j) {
	a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	return (j < n?dfs(k, i, j + 1) : (i < n?dfs(k, i + 1, 1) : (k < n?dfs(k + 1, 1, 1) : 0)));
}

int res = -inf;

bool sol(int i, int j) { 
	res = max(res, a[i][j]);
	return (j < n?sol(i, j + 1) : (i < n?sol(i + 1, 1) : 0));
}

int main() {

	cin >> n;

	a.resize(n + 1, vector< int >(n + 1));

	read(1, 1);
	init(1, inf);
	dfs(1, 1, 1);
	init(1, 0);
	sol(1, 1);

	cout << res << '\n';

	return 0;
}