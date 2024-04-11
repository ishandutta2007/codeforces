/*
PROG: cf893e
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
#define MAXN 1000010

long long normalize(long long x)
{
	return (((x % INF) + INF) % INF);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int Q;
bool prime[MAXN];
vector<int> pows[MAXN];
ll fact[2 * MAXN + 10], ifact[2 * MAXN + 10];
ll pow2[2 * MAXN + 10];

ll getpow(ll a, ll e)
{
	if (e == 0)
	{
		return 1ll;
	}
	ll was = getpow(a, e/2);
	if (e % 2)
	{
		return normalize(a * (normalize(was * was)));
	}
	return normalize(was * was);
}
void math()
{
	fact[0] = 1;
	for (int i = 1; i < 2 * MAXN; i++)
	{
		fact[i] = fact[i - 1] * i;
		fact[i] %= INF;
	}
	ifact[2 * MAXN - 1] = getpow(fact[2 * MAXN - 1], INF - 2);
	for (int i = 2 * MAXN - 2; i >= 0; i--)
	{
		ifact[i] = ifact[i + 1] * (i + 1);
		ifact[i] %= INF;
	}
//	cerr << "alive\n";
	pow2[0] = 1;
	for (int i = 1; i < 2 * MAXN; i++)
	{
		pow2[i] = pow2[i - 1] * 2;
		pow2[i] %= INF;
	}
//	cerr << "alive\n";
	return;
}
ll choose(ll n, ll k)
{
	return normalize(fact[n] * normalize(ifact[n - k] * ifact[k]));
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	srand(time(0));
	//	cout << fixed << setprecision(10);	
	//	cerr << fixed << setprecision(10);
	if (fopen("cf893e.in", "r"))
	{	
		freopen ("cf893e.in", "r", stdin);
		freopen ("cf893e.out", "w", stdout);
	}
	math();
	for (int i = 2; i < MAXN; i++)
	{
		prime[i] = true;
	}
	for (ll i = 2; i < MAXN; i++)
	{
		if (!prime[i])
		{
			continue;
		}
		for (ll j = i * i; j < MAXN; j += i)
		{
			prime[j] = false;
		}
	}
	for (ll i = 2; i < MAXN; i++)
	{
		if (!prime[i])
		{
			continue;
		}
		pows[i].PB(1);
		for (ll j = 2 * i; j < MAXN; j += i)
		{
			pows[j].PB(0);
			ll val = j;
			while(val % i == 0)
			{
				pows[j].back()++;
				val /= i;
			}
		}
	}
//	cerr << pows[4][0] << endl;
	Q = readi();
	while(Q--)
	{
		int val = readi(), K = readi();
		ll ans = 1ll;
		for (int N : pows[val])
		{
			ans *= choose(N + K - 1, K - 1);
			ans %= INF;
		}
		ans *= pow2[K - 1];
		ans = normalize(ans);
		printi(ans);
		putchar('\n');
	}
	return 0;
}