/*
PROG: cf877e
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
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound

#define SINF 10007
#define MOD 1000000007
#define INF 1000000861
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 200010

typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, T;
int parent[MAXN];
vector<int> edge[MAXN];
int t[MAXN], rt[MAXN];
int Q;

struct segtree
{
	int tree[4 * MAXN];
	bool lazy[4 * MAXN];
	void down(int w, int L, int R)
	{
		if (!lazy[w])
		{
			return;
		}
		tree[w] = (R - L + 1) - tree[w];
		lazy[w] = false;
		if (L == R)
		{
			return;
		}
		lazy[2 * w] = lazy[2 * w] xor true;
		lazy[2 * w + 1] = lazy[2 * w + 1] xor true;
		lazy[w] = false;
	}
	void rangeupdate(int w, int L, int R, int a, int b)
	{
		//toggle
		down(w, L, R);
		if (b < L || R < a)
		{
			return;
		}
		if (a <= L && R <= b)
		{
			tree[w] = (R - L + 1) - tree[w];
			if (L != R)
			{
				lazy[2 * w] = lazy[2 * w] xor true;
				lazy[2 * w + 1] = lazy[2 * w + 1] xor true;
			}
			return;
		}
		int mid = (L + R)/2;
		rangeupdate(2 * w, L, mid, a, b);
		rangeupdate(2 * w + 1, mid + 1, R, a, b);
		tree[w] = tree[2 * w] + tree[2 * w + 1];
	}
	int query(int w, int L, int R, int a, int b)
	{
		down(w, L, R);
		if (b < L || R < a)
		{
			return 0;
		}
		if (a <= L && R <= b)
		{
			return tree[w];
		}
		int mid = (L + R)/2;
		return query(2 * w, L, mid, a, b) + query(2 * w + 1, mid + 1, R, a, b);
	}
};
void dfs_t(int u)
{
	t[u] = T;
	rt[u] = T;
	T++;
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		dfs_t(v);
		rt[u] = max(rt[u], rt[v]);
	}
	return;
}
segtree seg;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
//	cout << fixed << setprecision(10);	
//	cerr << fixed << setprecision(10);
//	if (fopen("cf877e.in", "r"))
//	{	
//		freopen ("cf877e.in", "r", stdin);
//		freopen ("cf877e.out", "w", stdout);
//	}
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		cin >> parent[i];
		parent[i]--;
		edge[parent[i]].PB(i);
	}
	dfs_t(0);
//	for (int i = 0; i < N; i++)
//	{
//		cerr << t[i] << endl;
//	}
	for (int i = 0; i < N; i++)
	{
		bool f;
		cin >> f;
		if (!f)
		{
			continue;
		}
		seg.rangeupdate(1, 0, N - 1, t[i], t[i]);
	}
	cin >> Q;
	while(Q--)
	{
		string s;
		cin >> s;
		int u;
		cin >> u;
		u--;
		if (s[0] == 'p')
		{
			seg.rangeupdate(1, 0, N - 1, t[u], rt[u]);
		}
		else
		{
			cout << seg.query(1, 0, N - 1, t[u], rt[u]) << '\n';
		}
	}
	return 0;
}