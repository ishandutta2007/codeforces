/*
PROG: cf894e
LANG: C++
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
 */
#include <bits/stdc++.h>

using namespace std;

long long readi()
{
	long long input = 0;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	bool negative = false;
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = 10 * input + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	return input;
}
void printi(long long output)
{
	if (output == 0)
	{
		putchar('0');
		return;
	}
	if (output < 0)
	{
		putchar('-');
		output = -output;
	}
	int aout[20];
	int ilen = 0;
	while(output)
	{
		aout[ilen] = ((output % 10));
		output /= 10;
		ilen++;
	}
	for (int i = ilen - 1; i >= 0; i--)
	{
		putchar(aout[i] + '0');
	}
	return;
}
string reads()
{
	string input = "";
	char c = ' ';
	while (c <= ' ')
	{
		c = getchar();
	}
	while (c > ' ')
	{
		input += c;
		c = getchar();
	}
	return input;
}
int sgn(long long x)
{
	if (x < 0) 
	{
		return -1;
	}
	if (x > 0) 
	{
		return 1;
	}
	return 0;
}
long long randomize(long long x)
{
	return (((1ll << 31) * rand()) + rand()) % x;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define MAXN 1000010

#define SINF 10007
#define INF 1000000007
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 1000010

long long normalize(long long x)
{
	return (((x % INF) + INF) % INF);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M, S, K, T;
vector<pair<pll, int> > edge[MAXN];
int num[MAXN], low[MAXN];
vector<int> scc;
int id[MAXN];
ll arr[MAXN], dp[MAXN];
vector<pll> adj[MAXN];
ll ans;
ll multi[MAXN];
bool seen[MAXN];

ll earn(ll x)
{
	ll lo = 0, hi = INF;
	while(hi > lo)
	{
		ll mid = (hi + lo + 1)/2;
		if (mid * (mid - 1)/2 > x)
		{
			hi = mid - 1;
		}
		else
		{
			lo = mid;
		}
	}
	return lo * x - ((lo - 1) * (lo) * (lo + 1))/6;
}
void dfs(int u)
{
	scc.PB(u);
	T++;
	num[u] = T;
	low[u] = T;
	for (int i = 0; i < edge[u].size(); i++)
	{
        int v = edge[u][i].se;
        if (!num[v])
		{
			dfs(v);
		}
		low[u] = min(low[v], low[u]);
	}
	if (num[u] == low[u])
	{
		while(scc.back() != u)
		{
			int v = scc.back();
			id[v] = K;
			low[v] = INF;
			scc.pop_back();
		}
		id[u] = K;
		low[u] = INF;
		scc.pop_back();
		K++;
	}
	return;
}
ll solve(int u)
{
	if (seen[u])
	{
		return dp[u];
	}
	seen[u] = true;
	for (pll e : adj[u])
	{
		dp[u] = max(dp[u], solve(e.se) + e.fi);
	}
	dp[u] += arr[u];
	return dp[u];
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	//	cout << fixed << setprecision(10);	
	//	cerr << fixed << setprecision(10);
	//	if (fopen("cf894e.in", "r"))
	//	{	
	//		freopen ("cf894e.in", "r", stdin);
	//		freopen ("cf894e.out", "w", stdout);
	//	}
	N = readi();
	M = readi();
	for (int i = 0; i < M; i++)
	{
		int u, v; ll d;
		u = readi();
		v = readi();
		d = readi();
		u--;
		v--;
		if (u == v)
		{
			multi[u] += earn(d);
			continue;
		}
		edge[u].PB(MP(MP(d, earn(d)), v));
//		cerr << d << ' ' << earn(d) << endl;
	}
	S = readi(); S--;
	for (int i = 0; i < N; i++)
	{
		if (!num[i])
		{
			dfs(i);
		}
	}
	for (int i = 0; i < N; i++)
	{
//		cerr << id[i] << endl;
		for (auto e : edge[i])
		{
			int v = e.se;
			if (id[i] == id[v])
			{
				arr[id[i]] += e.fi.se;
			}
			else
			{
				adj[id[i]].PB(MP(e.fi.fi, id[v]));
			}
		}
		arr[id[i]] += multi[i];
	}
	ans = solve(id[S]);
	printi(ans);
	putchar('\n');
	return 0;

}