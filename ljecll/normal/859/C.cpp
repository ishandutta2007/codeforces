/*
PROG: cf859c
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
#define MAXN 55

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N;
int arr[MAXN];
int dp[MAXN][2];
int tot;
int alice, bob;

int solve(int idx, bool flag)
{
	if (idx >= N)
	{
		return 0;
	}
	if (dp[idx][flag] != -1)
	{
		return dp[idx][flag];
	}
	if (flag)
	{
		//alice's turn
		dp[idx][1] = min(solve(idx + 1, 0), solve(idx + 1, 1) + arr[idx]);
	}
	else
	{
		dp[idx][0] = max(solve(idx + 1, 0), solve(idx + 1, 1) + arr[idx]);
	}
	return dp[idx][flag];
}

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf859c.in", "r"))
	{	
		freopen ("cf859c.in", "r", stdin);
		//freopen ("cf859c.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		tot += arr[i];
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	bob = solve(0, 0);
	alice = tot - bob;
	cout << alice << ' ' << bob << '\n';
	return 0;
}