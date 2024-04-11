/*
PROG: cf893f
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
void yes()
{
	cout << "Yes\n";
	exit(0);
}
void no()
{
	cout << "No\n";
	exit(0);
}
void minus1()
{
	cout << "-1\n";
	exit(0);
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

const long double PI = 4.0 * atan(1.0);
const long double EPS = 0.000000000000001;

#define SINF 10007
#define INF 1000000007
#define LLINF 2696969696969696969ll
#define CO 1000037
#define MAXN 100010

long long normalize(long long x)
{
	return (((x % INF) + INF) % INF);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, R, Q, T;
int arr[MAXN];
vector<int> edge[MAXN];
int parent[MAXN];
int depth[MAXN];
int st[MAXN], ft[MAXN];
pii id[MAXN];
int ans;
int V, K;

void dfs_par(int u)
{
	for (int v : edge[u])
	{
		parent[v] = u;
		edge[v].erase(find(edge[v].begin(), edge[v].end(), u));
		dfs_par(v);
	}
	return;
}
void dfs(int u)
{
	st[u] = T;
	ft[u] = T;
	T++;
	for (int v : edge[u])
	{
		depth[v] = depth[u] + 1;
		dfs(v);
		ft[u] = max(ft[u], ft[v]);
	}
	return;
}

vector<pii> vals[4 * MAXN];
vector<int> prefs[4 * MAXN];
void build(int w, int L, int R)
{
	if (L == R)
	{
		vals[w].PB(id[L]);
		prefs[w].PB(id[L].se);
		return;
	}
	int mid = (R + L)/2;
	build(2 * w, L, mid);
	build(2 * w + 1, mid + 1, R);
	for (pii x : vals[2 * w])
	{
		vals[w].PB(x);
	}
	for (pii x : vals[2 * w + 1])
	{
		vals[w].PB(x);
	}
	sort(vals[w].begin(), vals[w].end());
	prefs[w].resize(vals[w].size());
	int smallest = INF;
	for (int i = 0; i < vals[w].size(); i++)
	{
		smallest = min(smallest, vals[w][i].second);
		prefs[w][i] = smallest;
	}
}
int query(int w, int L, int R, int a, int b, int mx)
{
	if (b < L || R < a)
	{
		return INF;
	}
	if (a <= L && R <= b)
	{
		int lo = -1, hi = vals[w].size() - 1;
		while(hi > lo)
		{
			int mid = (hi + lo + 1)/2;
			if (vals[w][mid].fi > mx)
			{
				hi = mid - 1;
			}
			else
			{
				lo = mid;
			}
		}
		if (lo == -1)
		{
			return INF;
		}
		return prefs[w][lo];
	}
	int mid = (L + R)/2;
	return min(query(2 * w, L, mid, a, b, mx), query(2 * w + 1, mid + 1, R, a, b, mx));
}


int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	srand(time(0));
	//	cout << fixed << setprecision(10);	
	//	cerr << fixed << setprecision(10);
	if (fopen("cf893f.in", "r"))
	{	
		freopen ("cf893f.in", "r", stdin);
		freopen ("cf893f.out", "w", stdout);
	}
	N = readi(); R = readi();
	R--;
	for (int i = 0; i < N; i++)
	{
		arr[i] = readi();
	}
	for (int i = 1; i < N; i++)
	{
		int u, v;
		u = readi(); v = readi();
		u--;
		v--;
		edge[u].PB(v);
		edge[v].PB(u);
	}
	parent[R] = N;
	depth[R] = 0;
	dfs_par(R);
	dfs(R);
	//pair(depth, val)
	for (int i = 0; i < N; i++)
	{
		id[st[i]] = MP(depth[i], arr[i]);
	}
	build(1, 0, N - 1);
	Q = readi();
	while(Q--)
	{
		V = readi(); K = readi();
		V = (V + ans) % N;
		K = (K + ans) % N;
		int hi = min(N - 1, depth[V] + K);
		ans = query(1, 0, N - 1, st[V], ft[V], hi);
		printi(ans); putchar('\n');
	}
}