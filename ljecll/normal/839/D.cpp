/*
PROG: cf839d
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

int N;
ll pw2[MAXN];
ll net[MAXN];
ll cnt[MAXN];
ll num[MAXN];
ll ans;

ll ADD(ll a, ll b)
{
	return (a + b) % MOD;
}
ll SUBT(ll a, ll b)
{
	return (a - (b % MOD) + MOD) % MOD;
}
ll MULT(ll a, ll b)
{
	return (a * b) % MOD;
}

int32_t main()
{
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf839d.in", "r"))
	{	
		freopen ("cf839d.in", "r", stdin);
		//		freopen ("cf839d.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		ll x;
		cin >> x;
		cnt[x]++;
	}
	pw2[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		pw2[i] = MULT(pw2[i - 1], 2);
	}
	for (ll i = 2; i < MAXN; i++)
	{
		net[i] = i;
	}
	for (ll i = 2; i < MAXN; i++)
	{
		for (ll j = 2 * i; j < MAXN; j += i)
		{
			net[j] -= net[i];
		}
	}
	for (ll i = 2; i < MAXN; i++)
	{
		for (ll j = i; j < MAXN; j += i)
		{
			num[i] += cnt[j];
		}
	}
	for (ll i = 2; i < MAXN; i++)
	{
		if (num[i] == 0)
		{
			continue;
		}
		ans = ADD(ans, MULT(net[i], MULT(num[i], pw2[num[i] - 1])));
	}
	cout << ans << '\n';
	return 0;
}