/*
PROG: cf765e
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
#define MAXN 200010

long long normalize(long long x)
{
	return (((x % INF) + INF) % INF);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
vector<int> edge[MAXN];
int parent[MAXN];
int head = 0;
int ans;

void dfs_par(int u)
{
	for (int v : edge[u])
	{
		if (v == parent[u])
		{
			continue;
		}
		parent[v] = u;
		dfs_par(v);
	}
	return;
}
int solve(int u)
{
	set<int> res;
	if (edge[u].size() == 1 && edge[u][0] == parent[u])
	{
		return 0;
	}
	for (int v : edge[u])
	{
		if (v == parent[u])
		{
			continue;
		}
//		cerr << u << "->" << v << endl;
		res.insert(solve(v) + 1);
//		cerr << v << ' ' << solve(v) + 1 << endl;
	}
	if (res.find(0) != res.end())
	{
		return -1;
	}
	if (res.size() > 2)
	{
		minus1();
	}
	if (res.size() == 2)
	{
//		cerr << u << ' ' << *res.begin() << ' ' << *res.rbegin() << endl;
		if (u == head)
		{
			 int val = *res.begin() + *res.rbegin();
			 while(val % 2 == 0)
			 {
				 val /= 2;
			 }
			 return val;
		}
		head = u;
		return -1;
	}
	return *res.begin();
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	srand(time(0));
	//	cout << fixed << setprecision(10);	
	//	cerr << fixed << setprecision(10);
	if (fopen("cf765e.in", "r"))
	{	
		freopen ("cf765e.in", "r", stdin);
		freopen ("cf765e.out", "w", stdout);
	}
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		edge[u].PB(v);
		edge[v].PB(u);
	}
	for (int i = 0; i < N; i++)
	{
		parent[i] = N;
	}
	dfs_par(0);
	int val = solve(0);
//	cerr << val << endl;
	if (val != -1)
	{
		while(val % 2 == 0)
		{
			val /= 2;
		}
		cout << val << '\n';
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		parent[i] = N;
	}
	dfs_par(head);
//	cerr << head << endl;
	val = solve(head);
	while(val % 2 == 0)
	{
		val /= 2;
	}
	cout << val << '\n';
}