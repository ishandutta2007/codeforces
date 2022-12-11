/*
PROG: cf898f
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
long long randomize(long long x)
{
	return (((1ll << 31) * rand()) + rand()) % x;
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

#define SBIG 10007
#define CO 10
#define INF 1000000007
#define BIG 1000000931
#define MOD BIG + 2
#define LARGE 1696969696967ll
#define HUGE 2564008813937411ll
#define LLBIG 2696969696969696969ll
#define MAXN 1000010

long long normalize(long long x, long long mod)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string s;
ll arr[MAXN];
pll pw[MAXN];
pll pref[MAXN];

pll range(int lt, int rt)
{
	if (lt <= 0 || lt > N || rt <= 0 || rt > N || lt > rt)
	{
		return MP(LLBIG, LLBIG);
	}
	if (arr[lt] == 0 && rt != lt)
	{
		return MP(LLBIG, LLBIG);
	}
	pll res;
	int sz = (rt - lt + 1);
	res.fi = normalize(pref[rt].fi - pw[sz].fi * pref[lt - 1].fi, BIG);
	res.se = normalize(pref[rt].se - pw[sz].se * pref[lt - 1].se, MOD);
	return res;
}
void print(int lt, int rt)
{
	for (int i = 1; i < lt; i++)
	{
		cout << arr[i];
	}
	cout << '+';
	for (int i = lt; i < rt; i++)
	{
		cout << arr[i];
	}
	cout << "=";
	for (int i = rt; i <= N; i++)
	{
		cout << arr[i];
	}
	cout << '\n';
	exit(0);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);
	//	cerr << fixed << setprecision(12);
	if (fopen("cf898f.in", "r"))
	{	
		freopen ("cf898f.in", "r", stdin);
		freopen ("cf898f.out", "w", stdout);
	}
	cin >> s;
	N = s.length();
	for (int i = 1; i <= N; i++)
	{
		arr[i] = s[i - 1] - '0';
	}
	pw[0] = MP(1, 1);
	for (int i = 1; i <= N; i++)
	{
		pw[i].fi = normalize(pw[i - 1].fi * CO, BIG);
		pw[i].se = normalize(pw[i - 1].se * CO, MOD);
	}
	pref[0] = MP(0, 0);
	for (int i = 1; i <= N; i++)
	{
		pref[i].fi = normalize(pref[i - 1].fi * CO + arr[i], BIG);
		pref[i].se = normalize(pref[i - 1].se * CO + arr[i], MOD);
	}
	for (int i = N; i >= 1; i--)
	{
		int sz = N - i + 1;
		pll sum = range(i, N);
		int split;
		pll lt, rt;
		split = i - sz;
		if (normalize(range(1, split - 1).fi + range(split, i - 1).fi, BIG) == sum.fi &&
				normalize(range(1, split - 1).se + range(split, i - 1).se, MOD) == sum.se)
		{
			print(split, i);
		}
		split = i - sz + 1;
		if (normalize(range(1, split - 1).fi + range(split, i - 1).fi, BIG) == sum.fi &&
				normalize(range(1, split - 1).se + range(split, i - 1).se, MOD) == sum.se)
		{
			print(split, i);
		}
		split = sz;
		if (normalize(range(1, split - 1).fi + range(split, i - 1).fi, BIG) == sum.fi &&
				normalize(range(1, split - 1).se + range(split, i - 1).se, MOD) == sum.se)
		{
			print(split, i);
		}
		split = sz + 1;
		if (normalize(range(1, split - 1).fi + range(split, i - 1).fi, BIG) == sum.fi &&
				normalize(range(1, split - 1).se + range(split, i - 1).se, MOD) == sum.se)
		{
			print(split, i);
		}
	}
	cout << "-1\n";
	return 0;
}