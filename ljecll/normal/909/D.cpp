/*
PROG: cf909d
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
#define MAXN 1000010

long long normalize(long long x, long long mod)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
int N;
int arr[MAXN];
vector<pii> blocks, active;
int SZ;
int ans;

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf909d.in", "r"))
	{	
		freopen ("cf909d.in", "r", stdin);
		freopen ("cf909d.out", "w", stdout);
	}
	cin >> s;
	N = s.length();
	for (int i = 0; i < s.length(); i++)
	{
		arr[i] = s[i] - 'a' + 1;
	}
	for (int i = 0; i < N; i++)
	{
		SZ++;
		if (i == N - 1 || arr[i] != arr[i + 1])
		{
			blocks.PB(MP(arr[i], SZ));
			SZ = 0;
		}
	}
	while(blocks.size() > 1)
	{
		int t = INF;
		for (int i = 0; i < blocks.size(); i++)
		{
			if (i == 0 || i == blocks.size() - 1)
			{
				t = min(t, blocks[i].se);
			}
			else
			{
				t = min(t, (blocks[i].se + 1) / 2);
			}
		}
		for (int i = 0; i < blocks.size(); i++)
		{
			if (i == 0 || i == blocks.size() - 1)
			{
				blocks[i].se -= t;
			}
			else
			{
				blocks[i].se -= 2 * t;
			}
			if (blocks[i].se <= 0)
			{
				continue;
			}
			if (!active.empty() && blocks[i].fi == active.back().fi)
			{
				active.back().se += blocks[i].se;
			}
			else
			{
				active.PB(blocks[i]);
			}
		}
		blocks.clear();
		for (int i = 1; i < active.size(); i++)
		{
			if (active[i].fi == active[i - 1].fi)
			{
				active[i].se += active[i - 1].se;
				active[i - 1].se = 0;
			}
		}
		for (int i = 0; i < active.size(); i++)
		{
			if (active[i].se)
			{
				blocks.PB(active[i]);
			}
		}
		active.clear();
		ans += t;
	}
	cout << ans << '\n';
}