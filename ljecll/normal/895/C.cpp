/*
PROG: cf895c
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
const long double EPS = 0.00000000000000000001;

#define SINF 10007
#define INF 1000000007
#define LLINF 2696969696969696969ll
#define CO 1000037
#define MAXN 1000
#define int long long

long long normalize(long long x)
{
	return (((x % INF) + INF) % INF);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int cnt[MAXN];
int primes[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
bool sqf[MAXN];
int dp[2][(1 << 19) + 10];
int pow2[MAXN * MAXN];
int mask[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf895c.in", "r"))
	{	
		freopen ("cf895c.in", "r", stdin);
		freopen ("cf895c.out", "w", stdout);
	}
	cin >> N;
	for (int i = 1; i <= 70; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (i % (primes[j]) == 0)
			{
				mask[i] += (1 << j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		for (int j = 2; j < 10; j++)
		{
			while (x % (j * j) == 0)
			{
				x /= (j * j);
			}
		}
		cnt[x]++;
	}
	pow2[0] = 1;
	for (int i = 1; i < MAXN * MAXN; i++)
	{
		pow2[i] = pow2[i - 1] * 2;
		pow2[i] %= INF;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= 70; i++)
	{
		if (cnt[i] == 0)
		{
			continue;
		}
		for (int j = 0; j < (1 << 19); j++)
		{
			dp[1][j xor mask[i]] += dp[0][j] * pow2[cnt[i] - 1];
			dp[1][j xor mask[i]] = normalize(dp[1][j xor mask[i]]);
			dp[1][j] += dp[0][j] * pow2[cnt[i] - 1];
			dp[1][j] = normalize(dp[1][j]);
		}
		for (int j = 0; j < (1 << 19); j++)
		{
			dp[0][j] = normalize(dp[1][j]);
			dp[1][j] = 0;
		}
	}
	dp[0][0]--;
	dp[0][0] = normalize(dp[0][0]);
	cout << dp[0][0] << '\n';
	return 0;
}