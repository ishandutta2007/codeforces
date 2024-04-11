#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 1e10;
const double eps = 1e-9;
const int maxn = 200000 + 10;
const int sqrtmaxn = 1000;


struct union_find
{
	vector<int> p;

	union_find(int n) : p(n, -1) {}

	bool join(int u, int v)
	{
		if ((u = root(u)) == (v = root(v)))
			return false;
		if (p[u] > p[v])
			swap(u, v);
		p[u] += p[v];
		p[v] = u;
		return true;
	}

	int root(int u)
	{
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<int> value(n);

	int comp = n;
	union_find ds(n);

	for (int i = 0; i < n; ++i){
		cin >> value[i]; value[i]--;

		if (ds.join(i, value[i]))
			comp--;
	}

	int x = 1;

	for (int i = 0; i < n; ++i){
		int xx; cin >> xx;

		x ^= xx;
	}

	if (comp == 1) comp = 0;

	cout << comp + x << endl;

	return 0;
}