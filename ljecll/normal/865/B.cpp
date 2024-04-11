/*
PROG: cf865b
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
void prints(string output)
{
	for (int i = 0; i < output.length(); i++)
	{
		putchar(output[i]);
	}
	return;
}
long long getrand()
{
	long long rand1 = (rand() % 536870912);
	long long rand2 = (rand() % 536870912);
	return (rand1 * 536870912ll + rand2);
}

//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

#define MP make_pair
#define PB push_back

#define MAGIC 400
#define SINF 10001
#define INF 1000000861
#define LLINF 1000000000000000861ll
#define MOD 1000000007
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 100010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, S;
pll arr[MAXN];
ll ans;
ll B;
ll tot;

bool cmp(pll a, pll b)
{
	return a.second < b.second;
}
ll overlap(ll a, ll b, ll c, ll d)
{
	if (b < a || d < c)
	{
		return 0;
	}
	return max(0ll, (min(d, b) - max(c, a)) + 1);
}
ll check(ll x)
{
	ll res = 0ll;
	ll one = x * S;
//	cerr << one << ' ' << two << endl;
	ll E = B * S - tot;
	ll cnt = 0;
	for (int i = 0; i < N; i++)
	{
		ll lo = cnt, hi = cnt + arr[i].first - 1;
		ll n2, ne;
		n2 = overlap(lo, hi, one, B * S - 1);
//		cerr << lo << ' ' << hi << ' ' << B*S-two+E << ' ' << B*S - 1 << ' ' << n2 << endl;
		ne = overlap(lo, hi, one - E, one - 1);
		res += arr[i].second * n2;
		res += max(0ll, arr[i].second) * ne;
		cnt = hi + 1;
	}
	return res;
}

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf865b.in", "r"))
	{	
		freopen ("cf865b.in", "r", stdin);
		//freopen ("cf865b.out", "w", stdout);
	}
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		ll x, y;
		cin >> arr[i].first >> x >> y;
		arr[i].second = y - x;
		ans += (x * arr[i].first);
		B += arr[i].first;
		tot += arr[i].first;
	}
//	cerr << ans << endl;
	B += (S - 1);
	B /= S;
	sort(arr, arr + N, cmp);
	ll lo = 0, hi = B;
//	cerr << B << endl;
//	cerr << check(hi) << ' ' << check(lo) << endl;
//	return 0;
	while(hi > lo)
	{
		ll mid = (hi + lo)/2;
		if (check(mid) > check(mid + 1))
		{
			hi = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}
	ans += check(lo);
	cout << ans << '\n';
	return 0;
}