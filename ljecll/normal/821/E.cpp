/*
PROG: cf821e
LANG: C++
 */
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MP make_pair
#define PB push_back

#define SINF 10001
#define INF 1000000007
#define MOD INF
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 110

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<ll> row;
typedef vector<row> mat;

int N;
ll K;
pll coor[MAXN];
int height[MAXN];
mat beg[MAXN], fin[MAXN], trans[MAXN];
ll ans;

ll add(ll a, ll b)
{
	return (a + b) % MOD;
}
ll multiply(ll a, ll b)
{
	return (a * b) % MOD;
}
mat mult(mat a, mat b)
{
	mat res;
	int x = a.size(), y = b.size(), z = b[0].size();
	assert(y == a[0].size());
	res.resize(x);
	for (int i = 0; i < x; i++)
	{
		res[i].resize(z);
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{
				res[i][k] = add(res[i][k], multiply(a[i][j], b[j][k]));
			}
		}
	}
	return res;
}
mat expo(mat a, ll num)
{
	if (num == 1)
	{
		return a;
	}
	mat pre = expo(a, num/2);
	if (num % 2)
	{
		return mult(mult(pre, pre), a);
	}
	return mult(pre, pre);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf821e.in", "r"))
	{	
		freopen ("cf821e.in", "r", stdin);
		freopen ("cf821e.out", "w", stdout);
	}
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> coor[i].first >> coor[i].second >> height[i];
		coor[i].second = min(K, coor[i].second);
		height[i]++;
		beg[i].resize(1);
		beg[i][0].resize(height[i]);
		fin[i].resize(1);
		trans[i].resize(height[i]);
		for (int j = 0; j < height[i]; j++)
		{
			trans[i][j].resize(height[i]);
		}
	}
	beg[0][0][0]++;
	for (int i = 0; i < N; i++)
	{
		//		cerr << i << endl;
		for (int j = 0; j < height[i]; j++)
		{
			for (int k = 0; k < height[i]; k++)
			{
				if (abs(j - k) <= 1)
				{
					trans[i][j][k]++;
				}
				//				cerr << trans[i][j][k] << ' ';
			}
			//			cerr << endl;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (coor[i].second == coor[i].first)
		{
			fin[i] = beg[i];
		}
		else
		{
			fin[i] = mult(beg[i], expo(trans[i], coor[i].second - coor[i].first));
		}
//		cerr << i << endl;
		if (i == N - 1)
		{
			break;
		}
		for (int j = 0; j < beg[i + 1][0].size() && j < fin[i][0].size(); j++)
		{
			beg[i + 1][0][j] = fin[i][0][j];
		}
	}
	ans = fin[N - 1][0][0];
	cout << ans << '\n';
	return 0;
}