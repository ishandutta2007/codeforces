/*
PROG: cf832d
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
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 100010
#define MAXH 22

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, Q;
int parent[MAXN];
vector<int> edge[MAXN];
int depth[MAXN];
int ancestor[MAXH][MAXN];

void dfs_depth(int u)
{
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v == parent[u])
		{
			continue;
		}
		depth[v] = depth[u] + 1;
		dfs_depth(v);
	}
	return;
}
int lca(int a, int b)
{
	if (depth[a] > depth[b])
	{
		swap(a, b);
	}
	int d = depth[b] - depth[a];
	for (int i = 0; i < MAXH; i++)
	{
		if (d & (1 << i))
		{
			b = ancestor[i][b];
		}
	}
	if (a == b)
	{
		return a;
	}
	for (int i = MAXH - 1; i >= 0; i--)
	{
		if (ancestor[i][a] != ancestor[i][b])
		{
			a = ancestor[i][a];
			b = ancestor[i][b];
		}
	}
	return parent[a];
}
int get(int a, int b, int c, int d)
{
//	cerr << depth[lca(b, d)] - max(depth[a], depth[c]) << endl;
	return max(0, depth[lca(b, d)] - max(depth[a], depth[c]));
}
int solve(int a, int b, int c)
{
	int a1 = lca(a, c), b1 = a;
	int a2 = lca(a, c), b2 = c;
	int a3 = lca(b, c), b3 = b;
	int a4 = lca(b, c), b4 = c;
	return get(a1, b1, a3, b3) + get(a1, b1, a4, b4) + get(a2, b2, a3, b3) + get(a2, b2, a4, b4);
}
int32_t main()
{
	cout << fixed << setprecision(10);	
	ios_base::sync_with_stdio(false);
	if (fopen("cf832d.in", "r"))
	{	
		freopen ("cf832d.in", "r", stdin);
		freopen ("cf832d.out", "w", stdout);
	}
	cin >> N >> Q;
	for (int i = 1; i < N; i++)
	{
		cin >> parent[i];
		parent[i]--;
		edge[parent[i]].PB(i);
		//		cerr << parent[i] << ' ' << i << endl;
	}
	depth[0] = 0;
	dfs_depth(0);
	for (int i = 0; i < MAXH; i++)
	{
		ancestor[i][N] = N;
	}
	for (int i = 0; i < N; i++)
	{
		ancestor[0][i] = parent[i];
	}
	for (int j = 1; j < MAXH; j++)
	{
		for (int i = 0; i < N; i++)
		{
			ancestor[j][i] = ancestor[j - 1][ancestor[j - 1][i]];
		}
	}
	while(Q--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		c--;
		int ans = 0;
		ans = max(ans, solve(a, b, c));
		//		cerr << ans << endl;
		ans = max(ans, solve(b, c, a));
		//		cerr << ans << endl;
		ans = max(ans, solve(c, a, b));
		//		cerr << ans << endl;
		cout << ans + 1 << '\n';
	}
	return 0;
}