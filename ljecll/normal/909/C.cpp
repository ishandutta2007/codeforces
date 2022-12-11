/*
PROG: cf909c
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
long long randomize(long long mod)
{
	return ((1 << 30) * rand() + (1 << 15) * rand() + rand()) % mod;
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
#define MAXN 5010

long long normalize(long long x, long long mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
bool typ[MAXN];
int dif[MAXN][MAXN];
int dp[MAXN][MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf909c.in", "r"))
	{	
		freopen ("cf909c.in", "r", stdin);
		freopen ("cf909c.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char ch;
		cin >> ch;
		if (ch == 'f')
		{
			typ[i] = true;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (!typ[i])
			{
				dif[i + 1][0] += dp[i][j];
				dif[i + 1][0] = normalize(dif[i + 1][0]);
				dif[i + 1][j + 1] -= dp[i][j];
				dif[i + 1][j + 1] = normalize(dif[i + 1][j + 1]);
			}
			else
			{
				dif[i + 1][j + 1] += dp[i][j];
				dif[i + 1][j + 1] = normalize(dif[i + 1][j + 1]);
				dif[i + 1][j + 2] -= dp[i][j];
				dif[i + 1][j + 2] = normalize(dif[i + 1][j + 2]);
			}
		}
		dp[i + 1][0] = dif[i + 1][0];
		for (int j = 1; j <= i + 1; j++)
		{
			dp[i + 1][j] = dp[i + 1][j - 1] + dif[i + 1][j];
			dp[i + 1][j] = normalize(dp[i + 1][j]);
		}
	}
	cout << dp[N][0] << '\n';
	return 0;
}