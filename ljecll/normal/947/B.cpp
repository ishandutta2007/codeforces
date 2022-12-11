/*
PROG: cf947b
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
#define MAXN 100013

template<class T>
T normalize(T x, T mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
ll arr[MAXN], cap[MAXN];
ll pref[MAXN];
ll pcnt[MAXN];
ll ans[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf947b.in", "r"))
	{	
		freopen ("cf947b.in", "r", stdin);
		freopen ("cf947b.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> cap[i];
		pref[i + 1] = pref[i] + cap[i];
	}
	cap[N] = INF;
	pref[N + 1] = pref[N] + INF;
	for (int i = 0; i < N; i++)
	{
		//find the day in which it dies
		int lo = i, hi = N;
		while(hi > lo)
		{
			int mid = (hi + lo)/2;
			if (pref[mid + 1] - pref[i] >= arr[i])
			{
				hi = mid;
			}
			else
			{
				lo = mid + 1;
			}
		}
		ans[lo] += (arr[i] - (pref[lo] - pref[i]));
		pcnt[i]++;
		pcnt[lo]--;
	}
	for (int i = 1; i < N; i++)
	{
		pcnt[i] += pcnt[i - 1];
	}
	for (int i = 0; i < N; i++)
	{
		ans[i] += pcnt[i] * cap[i];
	}
	cout << ans[0];
	for (int i = 1; i < N; i++)
	{
		cout << ' ' << ans[i];
	}
	cout << '\n';
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}