#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int ds[maxn];

int root(int a){
	return ds[a] < 0 ? a : ds[a] = root(ds[a]);
}

bool join(int a, int b){
	a = root(a), b = root(b);
	if (a == b) return false;
	if (ds[a] > ds[b]) swap(a, b);
	ds[a] += ds[b];
	ds[b] = a;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (m != n - 1){
		cout << "no" << endl;
		exit(0);
	}

	memset(ds, -1, sizeof ds);

	for (int i = 0; i < m; ++i)
	{
		int u, v; cin >> u >> v;
		if (!join(u, v)){
			cout << "no" << endl;
			exit(0);
		}
	}

	cout << "yes" << endl;

	return 0;
}