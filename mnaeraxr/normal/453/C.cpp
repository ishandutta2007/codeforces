#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100010;

vi ady[maxn];
int odd[maxn];
bool mk[maxn];
int path[maxn * 4], pnt;

void dfs(int s, int f){
	mk[s] = true;
	path[pnt++] = s;
	odd[s] ^= 1;
	for (auto e : ady[s]){
		if (mk[e]) continue;
		dfs(e, s);
		path[pnt++] = s;
		odd[s] ^= 1;
	}

	if (odd[s] && f != -1){
		odd[s] ^= 1;
		odd[f] ^= 1;
		path[pnt++] = f;
		path[pnt++] = s;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		ady[u].push_back(v);
		ady[v].push_back(u);
	}	

	int root = 1;

	for (int i = 1; i <= n; ++i){
		cin >> odd[i];
		if (odd[i]) root = i;
	}

	pnt = 0;
	dfs(root, -1);
	bool ok = true;
	for (int i = 1; i <= n && ok; ++i)
		if (odd[i] && i != root) ok = false;
	
	if (!ok){
		cout << -1 << endl;
		exit(0);
	}

	if (odd[root]) --pnt;

	cout << pnt << endl;
	for (int i = 0; i < pnt; ++i)
		cout << path[i] << " ";
	cout << endl;

	return 0;
}