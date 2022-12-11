/*
PROG: cf839e
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
#define MAXN 40

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N;
ld K;
bool edge[MAXN][MAXN];
int siz;
bool clique[1 << (MAXN/2)];
int dp[1 << (MAXN/2)];
ld ans;

int32_t main()
{
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf839e.in", "r"))
	{	
		freopen ("cf839e.in", "r", stdin);
		//freopen ("cf839e.out", "w", stdout);
	}
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> edge[i][j];
			if (i == j)
			{
				edge[i][j] = true;
			}
		}
	}
	if (N <= 20)
	{
		for (int mask = 0; mask < (1 << N); mask++)
		{
			bool works = true;
			for (int i = 0; i < N; i++)
			{
				if (!(mask & (1 << i)))
				{
					continue;
				}
				for (int j = 0; j < N; j++)
				{
					if (!(mask & (1 << j)))
					{
						continue;
					}
					if (!edge[i][j])
					{
						works = false;
					}
				}
			}
			if (works)
			{
				siz = max(siz, __builtin_popcount(mask));
			}
		}
	}
	else
	{
		for (int mask = 0; mask < (1 << 20); mask++)
		{
			clique[mask] = true;
			for (int i = 0; i < 20; i++)
			{
				if (!(mask & (1 << i)))
				{
					continue;
				}
				for (int j = 0; j < 20; j++)
				{
					if (!(mask & (1 << j)))
					{
						continue;
					}
					if (!edge[i][j])
					{
						clique[mask] = false;
					}
				}
			}
			if (clique[mask])
			{
				siz = max(siz, __builtin_popcount(mask));
				dp[mask] = max(dp[mask], __builtin_popcount(mask));
			}
			for (int i = 0; i < 20; i++)
			{
				if (mask & (1 << i))
				{
					continue;
				}
				dp[mask + (1 << i)] = max(dp[mask + (1 << i)], dp[mask]);
			}
		}
		for (int mask = 0; mask < (1 << (N - 20)); mask++)
		{
			bool works = true;
			for (int i = 20; i < N; i++)
			{
				if (!(mask & (1 << (i - 20))))
				{
					continue;
				}
				for (int j = 20; j < N; j++)
				{
					if (!(mask & (1 << (j - 20))))
					{
						continue;
					}
					if (!edge[i][j])
					{
						works = false;
					}
				}
			}
			if (!works)
			{
				continue;
			}
			int best = 0;
			for (int i = 0; i < 20; i++)
			{
				bool can = true;
				for (int j = 20; j < N; j++)
				{
					if (!(mask & (1 << (j - 20))))
					{
						continue;
					}
					if (!edge[i][j])
					{
						can = false;
					}
				}
				if (can)
				{
					best += (1 << i);
				}
			}
			siz = max(siz, __builtin_popcount(mask) + dp[best]);
		}
	}
	ans = (K * K * ((ld) (siz - 1)) * 0.5) / ((ld) (siz));
	cout << ans << '\n';
	return 0;
}