/*
PROG: cf859d
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

#define MAGIC 400
#define SINF 10001
#define INF 1000000861
#define LLINF 1000000000000000861ll
#define MOD 1000000007
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 69

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N;
ld p[MAXN][MAXN];
ld pwin[MAXN][MAXN];
ld gain[MAXN][MAXN];
ld ans;
ld dp[MAXN][MAXN];
bool seen[MAXN][MAXN];

bool face(int rond, int a, int b)
{
	//can a and b face in rond x?
	if (rond < 0)
	{
		return false;
	}
	int val = a xor b;
	if (val >= (2 << rond) || val < (1 << rond))
	{
		return false;
	}
	return true;
}
ld solve(int rond, int w)
{
	if (rond < 0)
	{
		return 0.0;
	}
	if (seen[rond][w])
	{
		return dp[rond][w];
	}
	seen[rond][w] = true;
	ld res = 0.0;
	for (int j = 0; j <= rond; j++)
	{
		ld best = 0.0;
		for (int i = 0; i < (1 << N); i++)
		{
			if (!face(j, i, w))
			{
				continue;
			}
			best = max(best, solve(j - 1, i));
		}
		res += best;
	}
	res += gain[rond][w];
	dp[rond][w] = res;
	return dp[rond][w];
}

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf859d.in", "r"))
	{	
		freopen ("cf859d.in", "r", stdin);
		//freopen ("cf859d.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < (1 << N); i++)
	{
		for (int j = 0; j < (1 << N); j++)
		{
			cin >> p[i][j];
			p[i][j] /= 100.0;
		}
	}
	for (int i = 0; i < (1 << N); i += 2)
	{
		pwin[0][i] = p[i][i + 1];
		pwin[0][i + 1] = p[i + 1][i];
		gain[0][i] = pwin[0][i];
		gain[0][i + 1] = pwin[0][i + 1];
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < (1 << N); j++)
		{
			for (int k = 0; k < (1 << N); k++)
			{
				if (!face(i, j, k))
				{
					continue;
				}
				pwin[i][j] += pwin[i - 1][j] * pwin[i - 1][k] * p[j][k];
			}
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < (1 << N); j++)
		{
			gain[i][j] = pwin[i][j] * ((ld) (1 << i));
			gain[i][j] += gain[i - 1][j];
//			cerr << gain[i][j] << ' ';
		}
	}
	for (int i = 0; i < (1 << N) - 1; i++)
	{
		ans = max(ans, solve(N - 1, i));
	}
	cout << ans << '\n';
	return 0;
}