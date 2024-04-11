/*
PROG: cf966c
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

int N, H;
vector<ll> arr;
vector<ll> ans;
vector<ll> nums[69];
int toggle[69];

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf966c.in", "r"))
	{	
		freopen ("cf966c.in", "r", stdin);
		freopen ("cf966c.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		ll x;
		cin >> x;
		arr.PB(x);
	}
	if (N == 1)
	{
		cout << "Yes\n" << arr[0] << '\n';
		return 0;
	}
	sort(arr.begin(), arr.end());
	for (int i = 60; i >= 0; i--)
	{
		if (arr[N - 1] & (1ll << i))
		{
			if (arr[N - 2] & (1ll << i))
			{
				cout << "No\n";
				return 0;
			}
			H = i;
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = H; j >= 0; j--)
		{
			if (arr[i] & (1ll << j))
			{
				toggle[j]++;
				for (int k = 0; k < j; k++)
				{
					if (arr[i] & (1ll << k))
					{
						toggle[k]--;
					}
				}
				break;
			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		if (toggle[i] > 1)
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	ll val = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = H; j >= 0; j--)
		{
			if (arr[i] & (1ll << j))
			{
				nums[j].PB(arr[i]);
				break;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 69; j++)
		{
			if (val & (1ll << j) || nums[j].empty())
			{
				continue;
			}
			cout << nums[j].back() << ' ';
			val ^= nums[j].back();
			nums[j].pop_back();
			break;
		}
	}
	cout << '\n';
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}