/*
PROG: cf995c
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
#define MAXN 100013

long long normalize(long long x, long long mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, int> ppi;

int N;
int ans[MAXN];
vector<ppi> v;
pll best;

ll arg(pll a)
{
	return (a.fi * a.fi) + (a.se * a.se);
}
bool cmp(ppi a, ppi b)
{
	return arg(a.fi) > arg(b.fi);
}
bool cmp1(ppi a, ppi b)
{
	return (abs(a.fi.fi) > abs(b.fi.fi));
}
bool cmp2(ppi a, ppi b)
{
	return (abs(a.fi.fi) + abs(a.fi.se) > abs(b.fi.fi) + abs(b.fi.se));
}
bool cmp3(ppi a, ppi b)
{
	return (abs(a.fi.fi) > abs(b.fi.fi));
}
void run()
{
	best = MP(0, 0);
	for (int i = 0; i < N; i++)
	{
		pll cur1 = MP(best.fi + v[i].fi.fi, best.se + v[i].fi.se);
		pll cur2 = MP(best.fi - v[i].fi.fi, best.se - v[i].fi.se);
		if (arg(cur1) < arg(cur2))
		{
			best = cur1;
			ans[v[i].se] = 1;
		}
		else
		{
			best = cur2;
			ans[v[i].se] = -1;
		}
	}
	if (arg(best) < 2250000000000ll)
	{
		for (int i = 0; i < N; i++)
		{
			if (i) cout << ' ';
			cout << ans[i];
		}
		exit(0);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf995c.in", "r"))
	{	
		freopen ("cf995c.in", "r", stdin);
		freopen ("cf995c.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.PB(MP(MP(x, y), i));
	}
	sort(v.begin(), v.end(), cmp);
	run();
	sort(v.begin(), v.end(), cmp1);
	run();
	assert(false);
	//sort by x?
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}