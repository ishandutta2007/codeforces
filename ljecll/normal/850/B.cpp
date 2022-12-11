/*
PROG: cf850b
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

#define SINF 10001
#define INF 1000000861
#define LLINF 1000000000000000861ll
#define MOD 1000000007
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
ll X, Y, G;
ll cnt[2 * MAXN];
ll sum[2 * MAXN];
bool prime[MAXN];
ll ans = LLINF;

ll rcnt(int L, int R)
{
	return cnt[R] - cnt[L - 1];
}
ll rsum(int L, int R)
{
	return sum[R] - sum[L - 1];
}

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf850b.in", "r"))
	{	
		freopen ("cf850b.in", "r", stdin);
		//freopen ("cf850b.out", "w", stdout);
	}
	cin >> N >> X >> Y;
	for (int i = 0; i < N; i++)
	{
		ll x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 1; i < 2 * MAXN; i++)
	{
		sum[i] = cnt[i] * i;
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i < 2 * MAXN; i++)
	{
		cnt[i] += cnt[i - 1];
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
	for (ll i = 0; i < MAXN; i++)
	{
		if (!prime[i])
		{
			continue;
		}
		ll cost = 0ll;
		for (ll j = i; j < 2 * MAXN; j += i)
		{
			ll mid = max(j - i + 1, j - (X/Y));
			cost += (rcnt(j - i + 1, mid - 1)) * X;
			cost += ((rcnt(mid, j) * j) - rsum(mid, j)) * Y;
		}
		ans = min(ans, cost);
	}
	cout << ans << '\n';
	return 0;
}