/*
PROG: cf895b
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
long long randomize(long long x)
{
	return (((1ll << 31) * rand()) + rand()) % x;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

const long double PI = 4.0 * atan(1.0);
const long double EPS = 0.00000000000000000001;

#define SINF 10007
#define INF 1000000007
#define LLINF 2696969696969696969ll
#define CO 1000037
#define MAXN 100010

long long normalize(long long x)
{
	return (((x % INF) + INF) % INF);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
ll X, K;
ll arr[MAXN];
map<ll, ll> cnt;
ll ans;

ll range(ll lo, ll hi)
{
	//biggest index <= lo
	ll small = lower_bound(arr, arr + N, lo) - arr; //first guy
	ll big = upper_bound(arr, arr + N, hi) - arr - 1; //last guy
	//smallest index > hi
	return big - small + 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf895b.in", "r"))
	{	
		freopen ("cf895b.in", "r", stdin);
		freopen ("cf895b.out", "w", stdout);
	}
	cin >> N >> X >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		ll cntlo = (arr[i] - 1)/X; //# of guys strictly less
		if ((arr[i] + 1) % X == 0 && K == 0)
		{
			continue;
		}
		ll small = max(arr[i] + 1, (cntlo + K) * X), big = max(arr[i] + 1, (cntlo + K) * X + X - 1);
		ans += range(small, big);
	}
	for (auto it = cnt.begin(); it != cnt.end(); it++)
	{
		if (K == 0 && (it -> first % X) != 0)
		{
			ans += (it -> second * it -> second);
		}
		if (K == 1 && (it -> first % X) == 0)
		{
			ans += (it -> second * it -> second);
		}
	}
	cout << ans << '\n';
	return 0;
}