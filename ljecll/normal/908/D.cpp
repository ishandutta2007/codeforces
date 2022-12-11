/*
PROG: cf908d
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

long long normalize(long long x, long long mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll K;
ll pa, pb;
ll ipb;
ll ans;
bool vis[MAXN][MAXN];
ll dp[MAXN][MAXN];

ll getpow(ll a, ll e)
{
	if (e == 0)
	{
		return 1ll;
	}
	ll was = getpow(a, e/2);
	if (e % 2)
	{
		return normalize(a * (normalize(was * was)));
	}
	return normalize(was * was);
}
ll inv(ll x)
{
	return getpow(x, INF - 2);
}
ll solve(ll i, ll k)
{
	//you already have i a's, j b's and k 'ab' subsequences
	if (k >= K)
	{
		return normalize(k);
	}
	if (i >= K)
	{
		return normalize(k + K + pa * ipb);
	}
	if (vis[i][k])
	{
		return dp[i][k];
	}
	vis[i][k] = true;
	ll res = 0ll;
	res += normalize(pa * solve(i + 1, k));
	res += normalize(pb * solve(i, k + i));
	res = normalize(res);
	dp[i][k] = res;
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf908d.in", "r"))
	{	
		freopen ("cf908d.in", "r", stdin);
		freopen ("cf908d.out", "w", stdout);
	}
	cin >> K >> pa >> pb;
	ll denom = inv(pa + pb);
	pa *= denom;
	pb *= denom;
	pa %= INF;
	pb %= INF;
	ipb = inv(pb);
	cout << solve(1, 0) << '\n';
	return 0;
	//you ahve i a's, j b's, and m subsequences of length k
}