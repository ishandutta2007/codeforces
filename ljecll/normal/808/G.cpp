/*
PROG: cf808g
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

template<class T>
void readi(T &x)
{
	T input = 0;
	bool negative = false;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = input * 10 + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	x = input;
}
template<class T>
void printi(T output)
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
template<class T>
void ckmin(T &a, T b)
{
	a = min(a, b);
}
template<class T>
void ckmax(T &a, T b)
{
	a = max(a, b);
}
long long randomize(long long mod)
{
	return ((1ll << 30) * rand() + (1ll << 15) * rand() + rand()) % mod;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-20;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll

long long normalize(long long x, long long mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string temps;
int N, M;
vector<int> s, t, lps;
vector<int> go[30];
vector<vector<int> > dp;
int ans;

void kmp()
{
	lps.resize(M + 1);
	for (int i = 0; i < 30; i++)
	{
		go[i].resize(M + 1);
	}
	lps[0] = 0;
	for (int i = 1; i < M; i++)
	{
		int j = lps[i - 1];
		while(j && t[i] != t[j])
		{
			j = lps[j - 1];
		}
		lps[i] = j + (bool) (t[i] == t[j]);
	}
	for (int i = 0; i <= M; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (i != M && t[i] == j)
			{
				go[j][i] = i + 1;
			}
			else
			{
				if (i == 0)
				{
					go[j][i] = 0;
				}
				else
				{
					go[j][i] = go[j][lps[i - 1]];
				}
			}
		}
	}
	return;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	srand(time(0));
	//	cout << fixed << setprecision(12);
	//	cerr << fixed << setprecision(12);
	if (fopen("cf808g.in", "r"))
	{
		freopen ("cf808g.in", "r", stdin);
		freopen ("cf808g.out", "w", stdout);
	}
	cin >> temps;
	for (int i = 0; i < temps.size(); i++)
	{
		s.PB(temps[i] - 'a' + 1);
		if (temps[i] == '?')
		{
			s[i] = 27;
		}
	}
	cin >> temps;
	for (int i = 0; i < temps.size(); i++)
	{
		t.PB(temps[i] - 'a' + 1);
	}
	N = s.size();
	M = t.size();
	//	cerr << "go\n";
	kmp();
	dp.resize(N + 1);
	for (int i = 0; i <= N; i++)
	{
		dp[i].resize(M + 1);
	}
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (s[i] == 27)
			{
				for (int k = 1; k <= 26; k++)
				{
					ckmax(dp[i + 1][go[k][j]], dp[i][j] + (bool) (go[k][j] == M));
				}
			}
			else
			{
				ckmax(dp[i + 1][go[s[i]][j]], dp[i][j] + (bool) (go[s[i]][j] == M));
			}
		}
	}
	for (int j = 0; j <= M; j++)
	{
		ckmax(ans, dp[N][j]);
	}
	cout << ans << '\n';
	//make copies of t from s
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}