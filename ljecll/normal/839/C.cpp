/*
PROG: cf839c
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
	vector<char> vout;
	while(output)
	{
		vout.push_back((output % 10) + '0');
		output /= 10;
	}
	for (int i = vout.size() - 1; i >= 0; i--)
	{
		putchar(vout[i]);
	}
	return;
}
void prints(string output)
{
	for (int i = 0; i < output.length(); i++)
	{
		putchar(output[i]);
	}
	return;
}

#define MP make_pair
#define PB push_back

#define SINF 10001
#define INF 1000000861
#define MOD 1000000007
#define LLINF 1000000000000000861ll
#define SQR 400
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 100010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N;
vector<int> edge[MAXN];
int parent[MAXN];
ll dist[MAXN];
ld p[MAXN];
ld ans;

void dfs_par(int u)
{
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (parent[u] == v)
		{
			continue;
		}
		parent[v] = u;
		dfs_par(v);
	}
	return;
}
void dfs_dist(int u)
{
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (parent[u] == v)
		{
			continue;
		}
		dist[v] = dist[u] + 1;
		dfs_dist(v);
	}
	return;
}
void dfs_p(int u)
{
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (parent[u] == v)
		{
			continue;
		}
		if (u == 0)
		{
			p[v] = p[u] / (ld) (edge[u].size());
		}
		else
		{
			p[v] = p[u] / (ld) (edge[u].size() - 1);
		}
		dfs_p(v);
	}
}

int32_t main()
{
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf839c.in", "r"))
	{	
		freopen ("cf839c.in", "r", stdin);
		freopen ("cf839c.out", "w", stdout);
	}
	cin >> N;
	if (N == 1)
	{
		cout << "0\n";
		return 0;
	}
	for (int i = 1; i < N; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		edge[u].PB(v);
		edge[v].PB(u);
	}
	parent[0] = N;
	dfs_par(0);
	dist[0] = 0;
	dfs_dist(0);
	p[0] = 1.0;
	dfs_p(0);
	for (int i = 1; i < N; i++)
	{
		if (edge[i].size() == 1)
		{
		ans += ((ld) dist[i]) * p[i];
		}
	}
	cout << ans << '\n';
	return 0;
}