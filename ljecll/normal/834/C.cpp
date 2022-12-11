/*
PROG: cf834c
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
#define MAXN 1000010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int Q;
ll a, b;
map<ll, int> cubes;
bool prime[MAXN];
vector<int> primes[MAXN];

ll v_p(ll p, ll x)
{
	ll cnt = 0;
	while(x % p == 0)
	{
		x /= p;
		cnt++;
	}
	return cnt;
}

int32_t main()
{
	if (fopen("cf834c.in", "r"))
	{	
		freopen ("cf834c.in", "r", stdin);
		freopen ("cf834c.out", "w", stdout);
	}
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
		for (ll j = i; j < MAXN; j += i)
		{
			primes[j].PB(i);
		}
	}
	for (ll i = 1; i <= 1000000; i++)
	{
		cubes[i * i * i] = i;
	}
	Q = readi();
	while(Q--)
	{
		a = readi();
		b = readi();
		ll num = cubes[a * b];
		if (num == 0)
		{
			putchar('N');
			putchar('o');
			putchar('\n');
			continue;
		}
		if (a % num || b % num)
		{
			putchar('N');
			putchar('o');
			putchar('\n');
		}
		else
		{
			putchar('Y');
			putchar('e');
			putchar('s');
			putchar('\n');
		}
		continue;
	}
	return 0;
}