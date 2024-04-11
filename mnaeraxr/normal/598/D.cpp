#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

char M[1020][1020];
int id[1020][1020];

int f[1000100];
int c[1000100];
int val[1000100];

int root(int a){
	return a == f[a] ? a : f[a] = root(f[a]);
}

bool join(int a, int b){
	a = root(a); b = root(b);
	if (a == b) return false;
	if (c[a] > c[b]) swap(a, b);
	c[b] += c[a];
	f[a] = b;
	val[b] += val[a];
	return true;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i)
		cin >> M[i];

	int cid = 1;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j) if (M[i][j] == '.'){
			c[cid] = 1, f[cid] = cid;
			id[i][j] = cid++;
			for (int k = 0; k < 4; ++k){
				int cx = i + dx[k], cy = j + dy[k];
				if (M[cx][cy] == '*') ++val[id[i][j]];
			}
		}
	}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j) if (M[i][j] == '.'){
			for (int k = 0; k < 4; ++k){
				int cx = i + dx[k], cy = j + dy[k];
				if (M[cx][cy] == '.') join(id[i][j], id[cx][cy]);
			}
		}
	}

	while (q--){
		int x, y; cin >> x >> y;
		--x; --y;
		int v = root(id[x][y]);
		cout << val[v] << endl;
	}

	return 0;
}