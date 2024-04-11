/*
PROG: cf859e
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
long long getrand()
{
	long long rand1 = (rand() % 536870912);
	long long rand2 = (rand() % 536870912);
	return (rand1 * 536870912ll + rand2);
}

#define MP make_pair
#define PB push_back

#define MAGIC 400
#define SINF 10001
#define INF 1000000861
#define LLINF 1000000000000000861ll
#define MOD 1000000007
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 400010
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, spam;
int from[MAXN], to[MAXN];
int mp[MAXN];
int parent[MAXN];
int siz[MAXN];
int cyc;
bool freed[MAXN];
bool dumb[MAXN];
ll ans = 1ll;

int find_parent(int u)
{
	if (u == parent[u])
	{
		return u;
	}
	parent[u] = find_parent(parent[u]);
	return parent[u];
}
void merge(int u, int v)
{
	u = find_parent(u);
	v = find_parent(v);
	if (u == v)
	{
		return;
	}
	if (siz[u] > siz[v])
	{
		swap(u, v);
	}
	parent[u] = v;
	siz[v] += siz[u];
	siz[u] = 0;
	return;
}

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf859e.in", "r"))
	{	
		freopen ("cf859e.in", "r", stdin);
		//freopen ("cf859e.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < 2 * N; i++)
	{
		mp[i] = -1;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> from[i] >> to[i];
		from[i]--;
		to[i]--;
		mp[from[i]] = i;
	}
	spam = N;
	for (int i = 0; i < N; i++)
	{
		if (mp[to[i]] == -1)
		{
			mp[to[i]] = spam;
			spam++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		from[i] = mp[from[i]];
		to[i] = mp[to[i]];
		assert(from[i] < N);
	}
	for (int i = 0; i < spam; i++)
	{
		parent[i] = i;
		siz[i] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		if (i != to[i])
		{
			merge(i, to[i]);
		}
		else
		{
			dumb[find_parent(i)] = true;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (to[i] >= N)
		{
			freed[find_parent(i)] = true;
		}
	}
	for (int i = 0; i < spam; i++)
	{
		if (siz[i] <= 1 || dumb[i])
		{
			continue;
		}
		if (freed[i])
		{
			ans *= siz[i];
		}
		else
		{
			ans *= 2;
		}
		ans %= MOD;
	}
	cout << ans << '\n';
	return 0;
	//2^cycle *
}