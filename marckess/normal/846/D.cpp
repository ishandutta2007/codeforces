#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

struct BIT {
	vvi ft;

	BIT (int n, int m) : ft(n+1, vi(m+1)) {}

	void update (int a, int b, int k) {
		for (int i = a; i < ft.size(); i += (i & -i)) 
			for (int j = b; j < ft[i].size(); j += (j & -j))
				ft[i][j] += k;
	}

	int sum (int a, int b) {
		int ans = 0;
		for (int i = a; i; i -= (i & -i))
			for (int j = b; j; j -= (j & -j))
				ans += ft[i][j];
		return ans;
	}

	int query (int x1, int y, int x2, int y2) {
		return sum (x2, y2) - sum (x2, y-1) - sum (x1-1, y2) + sum (x1-1, y-1);
	}
};

const int M = 500*500 + 5;
int x[M], y[M], t[M], v[M];
int n, m, k, q, ant = -1;
BIT ft(0, 0);

bool comp (int a, int b) {
	return t[a] < t[b];
}

bool esPos (int mit) {
	if (mit == q) 
		return false;

	while (ant < mit) {
		ant++;
		int i = v[ant];
		ft.update(x[i], y[i], 1);
	}

	while (ant > mit) {
		int i = v[ant];
		ft.update(x[i], y[i], -1);
		ant--;
	}

	for (int i = 1; i + k - 1 <= n; i++)
		for (int j = 1; j + k - 1 <= m; j++)
			if (ft.query(i, j, i+k-1, j+k-1) == k*k) {
				return true;
			}
	
	return false;
}

int busBin () {
	int ant = -1, i = 0, j = q, m = (i+j) / 2, rep = 20;
	while (rep--) {
		if (esPos(m))
			j = m;
		else
			i = m;
		m = (i+j)/2;
	}

	if (esPos(i))
		return i;
	if (esPos(j))
		return j;
	return -1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k >> q;
	ft = BIT(n+5, m+5);

	for (int i = 0; i < q; i++) {
		cin >> x[i] >> y[i] >> t[i];
		v[i] = i;
	}
	sort (v, v+q, comp);

	int res = busBin();
	if (res == -1)
		cout << -1 << endl;
	else
		cout << t[v[res]] << endl;

	return 0;
}