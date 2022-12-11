/*
PROG: cf838b
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
#define MAXN 400010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, Q, T;
pii eid[MAXN];
ll siz[MAXN];
ll len[MAXN];
ll dist[MAXN];
vector<pll> edge[MAXN];
int parent[MAXN];
int t[MAXN], deepest[MAXN];
ll tree[MAXN];
ll minst[4 * MAXN];
ll lazy[4 * MAXN];

void dfs_t(int u)
{
	t[u] = T;
	deepest[u] = T;
	T++;
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i].second;
		if (v == parent[u])
		{
			continue;
		}
		dfs_t(v);
		deepest[u] = max(deepest[u], deepest[v]);
	}
	return;
}
void dfs_dist(int u)
{
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i].second;
		ll d = edge[u][i].first;
		if (v == parent[u])
		{
			continue;
		}
		dist[v] = dist[u] + d;
		dfs_dist(v);
	}
	return;
}
void upd(int lt, int rt, ll val)
{
	for (int e = lt + 1; e <= N; e += e & (-e))
	{
		tree[e] += val;
	}
	for (int e = rt + 2; e <= N; e += e & (-e))
	{
		tree[e] -= val;
	}
	return;
}
ll qu(int idx)
{
	ll sum = 0;
	for (int e = idx + 1; e > 0; e -= e & (-e))
	{
		sum += tree[e];
	}
	return sum;
}
void down(int w, int L, int R)
{
	minst[w] += lazy[w];
	if (L != R)
	{
		lazy[2 * w] += lazy[w];
		lazy[2 * w + 1] += lazy[w];
	}
	lazy[w] = 0;
	return;
}
void rangeupdate(int w, int L, int R, int a, int b, ll val)
{
	down(w, L, R);
	if (b < L || R < a)
	{
		return;
	}
	if (R <= b && a <= L)
	{
		minst[w] += val;
		if (L != R)
		{
			lazy[2 * w] += val;
			lazy[2 * w + 1] += val;
		}
		return;
	}
	int mid = (L + R)/2;
	rangeupdate(2 * w, L, mid, a, b, val);
	rangeupdate(2 * w + 1, mid + 1, R, a, b, val);
	minst[w] = min(minst[2 * w] + lazy[2 * w], minst[2 * w + 1] + lazy[2 * w + 1]);
	return;
}
ll minquery(int w, int L, int R, int a, int b)
{
	down(w, L, R);
	if (b < L || R < a)
	{
		return LLINF;
	}
	if (a <= L && R <= b)
	{
		return minst[w];
	}
	int mid = (L + R)/2;
	return min(minquery(2 * w, L, mid, a, b), minquery(2 * w + 1, mid + 1, R, a, b));
}

int32_t main()
{
	if (fopen("cf838b.in", "r"))
	{	
		freopen ("cf838b.in", "r", stdin);
//		freopen ("cf838b.out", "w", stdout);
	}
	N = readi();
	Q = readi();
	for (int i = 1; i < N; i++)
	{
		ll a, b, c;
		a = readi();
		b = readi();
		c = readi();
		a--;
		b--;
		edge[a].PB(MP(c, b));
		edge[b].PB(MP(c, a));
		parent[b] = a;
		eid[i] = MP(a, b);
		siz[i] = c;
	}
	for (int i = 1; i < N; i++)
	{
		ll a, b, c;
		a = readi();
		b = readi();
		c = readi();
		a--;
		b--;
		len[a] = c;
		siz[i + N - 1] = c;
		eid[i + N - 1] = MP(a, b);
	}
	parent[0] = N;
	dfs_t(0);
	dfs_dist(0);
	for (int i = 0; i < N; i++)
	{
		upd(t[i], t[i], dist[i]);
	}
	for (int i = 0; i < N; i++)
	{
		rangeupdate(1, 0, N - 1, t[i], t[i], dist[i] + len[i]);
	}
	while(Q--)
	{
		int qid;
		qid = readi();
		if (qid == 1)
		{
			int a; ll b;
			a = readi();
			b = readi();
			int u = eid[a].first, v = eid[a].second;
			ll was = siz[a];
			ll gain = b - was;
			if (v)
			{
				int t0 = t[v], t1 = deepest[v];
				upd(t0, t1, gain);
				rangeupdate(1, 0, N - 1, t0, t1, gain);
			}
			else
			{
				int t0 = t[u];
				rangeupdate(1, 0, N - 1, t0, t0, gain);
			}
			siz[a] = b;
		}
		else
		{
			ll ans = LLINF;
			int u, v;
			u = readi();
			v = readi();
			u--;
			v--;
			if (t[u] <= t[v] && t[v] <= deepest[u])
			{
				//you can go directly
				ans = min(ans, qu(t[v]) - qu(t[u]));
			}
			ans = min(ans, minquery(1, 0, N - 1, t[u], deepest[u]) - qu(t[u]) + qu(t[v]));
			printi(ans);
			putchar('\n');
		}
	}
}