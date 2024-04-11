/*
PROG: cf908b
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
#define MAXN 1010

long long normalize(long long x, long long mod)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
bool grid[MAXN][MAXN];
pii start, finish;
string cmds;
int typ[MAXN];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int arr[4];
int ans;
int K;

bool valid(int x, int y)
{
	return (0 <= x && x < N && 0 <= y && y < M && grid[x][y]);
}
bool test()
{
	pii pos = start;
	for (int i = 0; i < K; i++)
	{
		pos.fi += dx[typ[i]];
		pos.se += dy[typ[i]];
		if (!valid(pos.fi, pos.se))
		{
			return false;
		}
		if (pos == finish)
		{
			return true;
		}
	}
	return false;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf908b.in", "r"))
	{	
		freopen ("cf908b.in", "r", stdin);
		freopen ("cf908b.out", "w", stdout);
	}
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			if (s[j] == '#')
			{
				grid[i][j] = false;
			}
			else
			{
				grid[i][j] = true;
			}
			if (s[j] == 'S')
			{
				start = MP(i, j);
			}
			if (s[j] == 'E')
			{
				finish = MP(i, j);
			}
		}
	}
	cin >> cmds;
	K = cmds.length();
	for (int i = 0; i < 4; i++)
	{
		arr[i] = i;
	}
	do
	{
		for (int i = 0; i < K; i++)
		{
			typ[i] = arr[cmds[i] - '0'];
		}
		if (test())
		{
			ans++;
		}
	}
	while (next_permutation(arr, arr + 4));
	cout << ans << '\n';
	return 0;
}