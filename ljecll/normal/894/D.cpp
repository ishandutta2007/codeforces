/*
PROG: cf894d
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

int N, Q;
ll edge[MAXN];
ll dist[MAXN];
vector<ll> vals[MAXN];
vector<ll> pref[MAXN];

int sibling(int u)
{
	return u ^ 1;
}
pll query(int u, ll val)
{
	//gets the count and the sum of all the vertices with distance to u <= val in subtree of u
	int lo = -1, hi = vals[u].size() - 1;
	while(hi > lo)
	{
		int mid = (hi + lo + 1)/2;
		if (vals[u][mid] > dist[u] + val)
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
		return MP(0, 0);
	}
	return MP(lo + 1, pref[u][lo] - (lo + 1) * dist[u]);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	//	cout << fixed << setprecision(10);	
	//	cerr << fixed << setprecision(10);
	//	if (fopen("cf894d.in", "r"))
	//	{	
	//		freopen ("cf894d.in", "r", stdin);
	//		freopen ("cf894d.out", "w", stdout);
	//	}
	N = readi(); Q = readi();
	for (int i = 2; i <= N; i++)
	{
		edge[i] = readi();
	}
	dist[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		dist[i] = dist[i/2] + edge[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j != 0; j = j/2)
		{
			vals[j].PB(dist[i]);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		sort(vals[i].begin(), vals[i].end());
		for (int j = 0; j < vals[i].size(); j++)
		{
			if (j == 0)
			{
				pref[i].PB(vals[i][j]);
			}
			else
			{
				pref[i].PB(pref[i].back() + vals[i][j]);
			}
		}
	}
	while(Q--)
	{
		int u; ll K, ans = 0;
		u = readi(); K = readi();
		for (int i = u; i != 0; i = i/2)
		{
			if (dist[u] - dist[i] < K)
			{
				ans += (K - (dist[u] - dist[i]));
			}
//			cerr << i << endl;
			int v = sibling(i);
			if (v > N || v <= 0)
			{
				continue;
			}
			ll curdist = edge[v] + (dist[u] - dist[v/2]);
			pll w = query(v, K - curdist);
			ans += (K - curdist) * w.first - w.second;
		}
		pll w = query(u, K);
		ans += K * (w.first) - w.second;
		ans -= K;
		printi(ans);
		putchar('\n');
	}
}