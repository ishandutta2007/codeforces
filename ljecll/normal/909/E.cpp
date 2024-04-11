/*
PROG: cf909e
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
long long randomize(long long mod)
{
	return ((1 << 30) * rand() + (1 << 15) * rand() + rand()) % mod;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-30;

#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 100010

long long normalize(long long x, long long mod)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
bool typ[MAXN];
vector<int> edge[MAXN];
int early[MAXN];
int parent[MAXN];
bool head[MAXN];
int ans;
bool seen[MAXN];

void solve(int u)
{
	if (seen[u])
	{
		return;
	}
	seen[u] = true;
	for (int v : edge[u])
	{
		solve(v);
		if (typ[u])
		{
			if (typ[v])
			{
				early[u] = max(early[u], early[v]);
			}
			else
			{
				early[u] = max(early[u], early[v] + 1);
			}
		}
		else
		{
			early[u] = max(early[u], early[v]);
		}
	}
	return;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf909e.in", "r"))
	{	
		freopen ("cf909e.in", "r", stdin);
		freopen ("cf909e.out", "w", stdout);
	}
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> typ[i];
		early[i] = typ[i];
		head[i] = true;
	}
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		edge[u].PB(v);
		head[v] = false;
	}
	for (int i = 0; i < N; i++)
	{
		if (!seen[i])
		{
			solve(i);
			ans = max(ans, early[i]);
		}
	}
	cout << ans << '\n';
	return 0;
}