#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int maxn = (int) 2e5 + 100;
const int mod = (int) 1e9 + 7;

void add(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}
void sub(int &a, int b)
{
	a -= b;
	if (a < 0)
		a += mod;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % mod;
}

int fact[maxn], rfact[maxn];
int ri[maxn];

void init()
{
	fact[0] = 1;
	rfact[0] = 1;
	ri[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		if (i == 1)
			ri[i] = 1;
		else ri[i] = (mod - mul(mod / i, ri[mod % i] ) ) % mod;
		fact[i] = mul(fact[i - 1], i);
		rfact[i] = mul(rfact[i - 1], ri[i] );
	}
}

int getC(int a, int b)
{
	if (b < 0 || b > a)
		return 0;
	return mul(fact[a], mul(rfact[a - b], rfact[b] ) );
}

int getCnt(int sx, int sy, int tx, int ty)
{
	int dx = tx - sx;
	int dy = ty - sy;
	if (dx < 0 || dy < 0)
		return 0;
	return getC(dx + dy, dx);
}

int cntFirst[maxn];

void solve()
{
	vector <pair <int, int> > v;
	int h, w;
	int n;
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		v.push_back(make_pair(x, y) );
	}
	sort(v.begin(), v.end() );
	v.push_back(make_pair(h - 1, w - 1) );

	for (int i = 0; i < (int) v.size(); i++)
	{
		int x = v[i].first;
		int y = v[i].second;

		int cnt = getCnt(0, 0, x, y);
		for (int j = 0; j < i; j++)
		{
			int cur = mul(cntFirst[j], getCnt(v[j].first, v[j].second, x, y) );
			sub(cnt, cur);
		}
		cntFirst[i] = cnt;
	}
	printf("%d\n", cntFirst[n] );
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	init();
	solve();

	return 0;
}