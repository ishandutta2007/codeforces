/*
PROG: cf949c
LANG: C++11
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

template<class T>
void readi(T &x)
{
	T input = 0;
	bool negative = false;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = input * 10 + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	x = input;
}
template<class T>
void printi(T output)
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
template<class T>
void ckmin(T &a, T b)
{
	a = min(a, b);
}
template<class T>
void ckmax(T &a, T b)
{
	a = max(a, b);
}
long long randomize(long long mod)
{
	return ((1ll << 30) * rand() + (1ll << 15) * rand() + rand()) % mod;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-20;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 200013

template<class T>
T normalize(T x, T mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M, H, K, T;
int arr[MAXN];
vector<int> edge[MAXN];
int disc[MAXN], low[MAXN], id[MAXN];
vector<int> scc;
bool dead[MAXN];
int sz[MAXN];
int idx = -1;
bool seen[MAXN];
vector<int> ans;

void dfs(int u)
{
	seen[u] = true;
	disc[u] = T;
	low[u] = T;
	T++;
	scc.PB(u);
	for (int v : edge[u])
	{
        	if (!seen[v])
		{
			dfs(v);
		}
		low[u] = min(low[v], low[u]);
	}
	if (disc[u] == low[u])
	{
		while(scc.back() != u)
		{
			int v = scc.back();
			scc.pop_back();
			id[v] = K;
			low[v] = INF;
		}
		scc.pop_back();
		id[u] = K;
		low[u] = INF;
		K++;
	}
	return;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf949c.in", "r"))
	{	
		freopen ("cf949c.in", "r", stdin);
		freopen ("cf949c.out", "w", stdout);
	}
	cin >> N >> M >> H;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		if ((arr[u] + 1) % H == arr[v])
		{
			edge[u].PB(v);
//			cerr << u << ' ' << v << endl;
		}
		if ((arr[v] + 1) % H == arr[u])
		{
			edge[v].PB(u);
//			cerr << v << ' ' << u << endl;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (edge[i].empty())
		{
			cout << 1 << '\n' << i + 1 << '\n';
			return 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		sort(edge[i].begin(), edge[i].end());
		edge[i].erase(unique(edge[i].begin(), edge[i].end()), edge[i].end());
	}
	for (int i = 0; i < N; i++)
	{
		if (!seen[i])
		{
			dfs(i);
		}
	}
	for (int i = 0; i < N; i++)
	{
		sz[id[i]]++;
		for (int v : edge[i])
		{
			if (id[v] != id[i])
			{
				dead[id[i]] = true;
			}
		}
	}
	for (int i = 0; i < K; i++)
	{
		if (dead[i])
		{
			continue;
		}
		if (idx == -1 || sz[i] < sz[idx])
		{
			idx = i;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (id[i] == idx)
		{
			ans.PB(i);
		}
	}
	cout << ans.size() << '\n';
	cout << ans[0] + 1;
	for (int i = 1; i < ans.size(); i++)
	{
		cout << ' ' << ans[i] + 1;
	}
	cout << '\n';
	//else the answer is H

	//if there is vertex w/o outgoing edge, answer is 1
	//if
	//if you incr a, you must incr b
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}