/*
PROG: cf901b
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

#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 300

long long normalize(long long x, long long mod)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> poly;

int N;
poly lt, rt;

void print(poly a)
{
	cout << a.size() - 1 << '\n';
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << ' ';
	}
	cout << '\n';
}
poly add(poly a, poly b)
{
	while(a.size() < b.size())
	{
		a.PB(0);
	}
	while(b.size() < a.size())
	{
		b.PB(0);
	}
	poly c;
	c.resize(a.size());
	for (int i = 0; i < a.size(); i++)
	{
		c[i] = a[i] + b[i];
	}
	return c;
}
poly subtract(poly a, poly b)
{
	while(a.size() < b.size())
	{
		a.PB(0);
	}
	while(b.size() < a.size())
	{
		b.PB(0);
	}
	poly c;
	c.resize(a.size());
	for (int i = 0; i < a.size(); i++)
	{
		c[i] = a[i] - b[i];
	}
	return c;
}
poly timesx(poly a)
{
	poly c;
	c.resize(a.size() + 1);
	for (int i = 0; i < a.size(); i++)
	{
		c[i + 1] = a[i];
	}
	return c;
}
bool valid(poly a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (abs(a[i]) > 1)
		{
			return false;
		}
	}
	bool even = false, odd = false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i])
		{
			if (i % 2)
			{
				odd = true;
			}
			else
			{
				even = true;
			}
		}
	}
	if (odd && even)
	{
		return false;
	}
	return true;
}
void change()
{
	//a deg is > bdeg
	poly candidate = add(timesx(lt), rt);
	if (valid(candidate))
	{
		rt = lt;
		lt = candidate;
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		candidate = add(candidate, lt);
		if (valid(candidate))
		{
			rt = lt;
			lt = candidate;
			return;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		candidate = subtract(candidate, lt);
	}
	for (int i = 0; i < 5; i++)
	{
		candidate = subtract(candidate, lt);
		//		print(candidate);
		if (valid(candidate))
		{
			rt = lt;
			lt = candidate;
			return;
		}
	}
	candidate = subtract(timesx(lt), rt);
	if (valid(candidate))
	{
		rt = lt;
		lt = candidate;
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		candidate = add(candidate, lt);
		if (valid(candidate))
		{
			rt = lt;
			lt = candidate;
			return;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		candidate = subtract(candidate, lt);
	}
	for (int i = 0; i < 5; i++)
	{
		candidate = subtract(candidate, lt);
		//		print(candidate);
		if (valid(candidate))
		{
			rt = lt;
			lt = candidate;
			return;
		}
	}
	assert(false);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf901b.in", "r"))
	{	
		freopen ("cf901b.in", "r", stdin);
		freopen ("cf901b.out", "w", stdout);
	}
	cin >> N;
	if (N == 1)
	{
		cout << "1\n0 1\n0\n1\n";
		return 0;
	}
	lt.resize(3);
	lt[2] = 1;
	lt[1] = 0;
	lt[0] = -1;
	rt.resize(2);
	rt[1] = 1;
	rt[0] = 0;
	for (int i = 2; i < N; i++)
	{
		change();
	}
	print(lt);
	print(rt);
	return 0;
}