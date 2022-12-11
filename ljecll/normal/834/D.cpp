/*
PROG: cf834d
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
#define MAXK 53
#define MAXN 35010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, K;
int arr[MAXN];
int dp[MAXK][MAXN];
int nxt[MAXN];
int late[MAXN];

void solve(int i, int L, int R, int optl, int optr)
{
	if (L > R)
	{
		return;
	}
	int mid = (L + R)/2;
	int opt = -1;
	int cost = 0;
	for (int k = min(optr, mid - 1) + 2; k <= mid; k++)
	{
		if (nxt[k] > mid)
		{
			cost++;
		}
	}
	for (int k = min(optr, mid - 1); k >= optl; k--)
	{
		if (nxt[k + 1] > mid)
		{
			cost++;
		}
		if (dp[i - 1][k] + cost > dp[i][mid])
		{
			dp[i][mid] = dp[i - 1][k] + cost;
			opt = k;
		}
	}
	solve(i, L, mid - 1, optl, opt);
	solve(i, mid + 1, R, opt, optr);

}

int32_t main()
{
	cout << fixed << setprecision(10);	
	ios_base::sync_with_stdio(false);
	if (fopen("cf834d.in", "r"))
	{	
		freopen ("cf834d.in", "r", stdin);
		freopen ("cf834d.out", "w", stdout);
	}
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		arr[i]--;
	}
	for (int i = 0; i <= N; i++)
	{
		late[i] = INF;
	}
	for (int i = N; i >= 1; i--)
	{
		nxt[i] = late[arr[i]];
		late[arr[i]] = i;
	}
	for (int i = 1; i <= K; i++)
	{
		solve(i, 0, N, 0, N);
	}
	cout << dp[K][N] << '\n';
	return 0;
}