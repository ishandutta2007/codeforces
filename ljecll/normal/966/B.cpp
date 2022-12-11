/*
PROG: cf966b
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
#define MAXN 300013

long long normalize(long long x, long long mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
ll A, B;
pll arr[MAXN];
int bs[MAXN];
bool swapped = false;
vector<int> aans, bans;

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf966b.in", "r"))
	{	
		freopen ("cf966b.in", "r", stdin);
		freopen ("cf966b.out", "w", stdout);
	}
	cin >> N >> A >> B;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].fi;
		arr[i].se = i;
	}
	sort(arr, arr + N);
	//min value in the array must be > B/#
	//divide these A, B so that
	for (int i = 0; i < N; i++)
	{
		bs[i] = -1;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (1ll * (N - i) * arr[i].fi >= B)
		{
			for (int j = 0; j < i; j++)
			{
				bs[j] = i;
			}
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		ll cnt = (A + arr[i].fi - 1)/arr[i].fi;
		if (i + cnt - 1 >= N || bs[i + cnt - 1] == -1)
		{
			continue;
		}
		cout << "Yes\n";
		for (int j = i; j <= i + cnt - 1; j++)
		{
			aans.PB(arr[j].se);
		}
		for (int j = bs[i + cnt - 1]; j < N; j++)
		{
			bans.PB(arr[j].se);
		}
		if (swapped)
		{
			swap(aans, bans);
		}
		cout << aans.size() << ' ' << bans.size() << '\n';
		for (int x : aans)
		{
			cout << x + 1 << ' ';
		}
		cout << '\n';
		for (int x : bans)
		{
			cout << x + 1 << ' ';
		}
		cout << '\n';
		return 0;
	}
	swap(A, B);
	swapped = true;
	for (int i = 0; i < N; i++)
	{
		bs[i] = -1;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (1ll * (N - i) * arr[i].fi >= B)
		{
			for (int j = 0; j < i; j++)
			{
				bs[j] = i;
			}
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		ll cnt = (A + arr[i].fi - 1)/arr[i].fi;
		if (i + cnt - 1 >= N || bs[i + cnt - 1] == -1)
		{
			continue;
		}
		cout << "Yes\n";
		for (int j = i; j <= i + cnt - 1; j++)
		{
			aans.PB(arr[j].se);
		}
		for (int j = bs[i + cnt - 1]; j < N; j++)
		{
			bans.PB(arr[j].se);
		}
		if (swapped)
		{
			swap(aans, bans);
		}
		cout << aans.size() << ' ' << bans.size() << '\n';
		for (int x : aans)
		{
			cout << x + 1 << ' ';
		}
		cout << '\n';
		for (int x : bans)
		{
			cout << x + 1 << ' ';
		}
		cout << '\n';
		return 0;
	}
	cout << "No\n";
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}