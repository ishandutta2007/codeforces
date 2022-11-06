#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;

using namespace std;

int n;
const uint U1 = 1;
const int N = 501;

struct matrix
{
	bitset <N> a[N];
};

void make_null(matrix & m1)
{
	for (int i = 0; i < N; i++) m1.a[i].reset();
}

matrix mul(const matrix &m1, const matrix &m2)
{
	matrix ans;
	make_null(ans);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
		{
			if (m1.a[i][j] == 0) continue;
			ans.a[i] |= m2.a[j];
		}
	return ans;
}


const int MV = 62;
matrix mt[2][MV];
bitset <N> b;
bitset <N> nb;
const ll INF = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
int main()
{
	int m;
	cin >> n >> m;
	make_null(mt[0][0]);
	make_null(mt[1][0]);
	for (int i = 0; i < m; i ++)
	{
		int u, v, t;
		cin >> u >> v >> t;
		mt[t][0].a[u][v] = 1;
	}
	for (int i = 1; i < MV; i ++)
	{
		mt[0][i] = mul(mt[0][i - 1], mt[1][i - 1]);
		mt[1][i] = mul(mt[1][i - 1], mt[0][i - 1]);
	}
	int ct = 0;
	ll ans = 0;
	b.reset();
	b[1] = 1;
	for (int i = MV - 1; i >= 0; i--)
	{
		nb.reset();
		for (int st = 1; st <= n; st++)
		{
			if (!b[st]) continue;
			nb |= mt[ct][i].a[st];
		}
		if (nb.count() != 0)
		{
			b = nb;
			ct = 1 - ct;
			ans += (1ll << i);
		}
	}
	if (ans > INF) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}