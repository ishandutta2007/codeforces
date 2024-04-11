/*
please less of this kind of problem kthx
PROG: cf1007b
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
const long double EPS = 1e-10;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 100013

long long normalize(long long x, long long mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int Q;
int X[3];
vector<int> factors[MAXN];
int A, B, C;
vector<int> guy[8];
int need[8][8][8];
int sz[8], pref[8];
int p[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

bool works(int a, int b, int c)
{
	if ((a & 1) && (b & 2) && (c & 4))
	{
		return true;
	}
	if ((a & 1) && (b & 4) && (c & 2))
	{
		return true;
	}
	if ((a & 2) && (b & 1) && (c & 4))
	{
		return true;
	}
	if ((a & 2) && (b & 4) && (c & 1))
	{
		return true;
	}
	if ((a & 4) && (b & 1) && (c & 2))
	{
		return true;
	}
	if ((a & 4) && (b & 2) && (c & 1))
	{
		return true;
	}
	return false;
}
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
ll cntleq(int idx, ll x)
{
	return UB(guy[idx].begin(), guy[idx].end(), x) - guy[idx].begin();
}
ll choose2(ll a)
{
	return a * (a - 1) / 2;
}
ll choose3(ll a)
{
	return a * (a - 1) * (a - 2) / 6;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(10);	
	//	cerr << fixed << setprecision(10);
	if (fopen("cf1007b.in", "r"))
	{	
		freopen ("cf1007b.in", "r", stdin);
		//	freopen ("cf1007b.out", "w", stdout);
	}
	for (int i = 1; i < MAXN; i++)
	{
		for (int j = i; j < MAXN; j += i)
		{
			factors[j].PB(i);
		}
	}
	cin >> Q;
	//	Q = 100000;
	for (int q = 0; q < Q; q++)
	{
		cin >> X[0] >> X[1] >> X[2];
		//		X[0] = X[1] = X[2] = 83160;
		sort(X, X + 3);
		ll ans = 0;
		guy[1] = factors[X[0]];
		guy[2] = factors[X[1]];
		guy[3] = factors[gcd(X[0], X[1])];
		guy[4] = factors[X[2]];
		guy[5] = factors[gcd(X[0], X[2])];
		guy[6] = factors[gcd(X[1], X[2])];
		guy[7] = factors[gcd(X[0], gcd(X[1], X[2]))];
		sz[7] = guy[7].size();
		sz[6] = guy[6].size() - guy[7].size();
		sz[5] = guy[5].size() - guy[7].size();
		sz[3] = guy[3].size() - guy[7].size();
		sz[4] = guy[4].size() - guy[6].size() - guy[5].size() + guy[7].size();
		sz[2] = guy[2].size() - guy[6].size() - guy[3].size() + guy[7].size();
		sz[1] = guy[1].size() - guy[3].size() - guy[5].size() + guy[7].size();
		for (int i = 1; i < 8; i++)
		{
			pref[i] = guy[i].size();
		}
		//one
		ll one = 0, two = 0, three = 0;
		one = sz[7];
		//count two
		//aab
		//b is from 7?
		for (int i = 1; i < 8; i++)
		{
			//repeat i
			for (int j = 1; j < 8; j++)
			{
				//sngu
				if (!works(i, i, j))
				{
					continue;
				}
				if (i == j) continue;
				two += sz[i] * sz[j];
			}
		}
		two += choose2(sz[7]) * 2;
		//three distinct homes for three distinct guys
		for (int i = 1; i < 8; i++)
		{
			for (int j = i + 1; j < 8; j++)
			{
				for (int k = j + 1; k < 8; k++)
				{
					if (!works(i, j, k)) continue;
					three += sz[i] * sz[j] * sz[k];
				}
			}
		}
		//two distinct homes
		for (int i = 1; i < 8; i++)
		{
			for (int j = 1; j < 8; j++)
			{
				if (!works(i, i, j)) continue;
				if (i == j) continue;
				three += choose2(sz[i]) * sz[j];
			}
		}
		//one distinct home
		three += choose3(sz[7]);
//		cerr << one << ' ' << two << ' ' << three << endl;
		ans = one + two + three;
		cout << ans << '\n';
	}
	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}