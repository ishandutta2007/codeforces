/*
PROG: cf838a
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
#define MAXN 5010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, M;
bool grid[MAXN][MAXN];
int pref[MAXN][MAXN];
int ans = INF;
int cur = 0;

int32_t main()
{
	cout << fixed << setprecision(10);	
	ios_base::sync_with_stdio(false);
	if (fopen("cf838a.in", "r"))
	{	
		freopen ("cf838a.in", "r", stdin);
		freopen ("cf838a.out", "w", stdout);
	}
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		s = " " + s;
		for (int j = 1; j <= M; j++)
		{
			grid[i][j] = (s[j] - '0');
		}
	}
	for (int i = 1; i <= max(2 * N, 2 * M) + 5; i++)
	{
		for (int j = 1; j <= max(2 * N, 2 * M) + 5; j++)
		{
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i][j];
		}
	}
	for (int i = 2; i <= max(N, M); i++)
	{
		cur = 0;
		for (int j = i; j - i + 1 <= N; j += i)
		{
			for (int k = i; k - i + 1 <= M; k += i)
			{
				int cnt = pref[j][k] - pref[j - i][k] - pref[j][k - i] + pref[j - i][k - i];
				cur += min(cnt, (i * i) - cnt);
			}
		}
		ans = min(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}