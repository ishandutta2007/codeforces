/*
PROG: cf895d
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
#define MAXN 1000010

long long normalize(long long x)
{
	return (((x % INF) + INF) % INF);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string a, b;
int cnt[MAXN];
ll ca, cb;
bool dp[MAXN][2];
ll fact[MAXN];
ll ifact[MAXN];
ll ans;

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
void math()
{
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
	{
		fact[i] = fact[i - 1] * i;
		fact[i] %= INF;
	}
	ifact[MAXN - 1] = getpow(fact[MAXN - 1], INF - 2);
	for (int i = MAXN - 2; i >= 0; i--)
	{
		ifact[i] = ifact[i + 1] * (i + 1);
		ifact[i] %= INF;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf895d.in", "r"))
	{	
		freopen ("cf895d.in", "r", stdin);
		freopen ("cf895d.out", "w", stdout);
	}
	cin >> a >> b;
	N = a.length();
	for (int i = 0; i < N; i++)
	{
		cnt[a[i]]++;
	}
	math();
	//want a < c < b -> count c with c<b, count c with c<a, then subtract
	for (int i = 0; i < N; i++)
	{
		//either you diverge here...
		ll gain = fact[N - i - 1];
		for (char k = 'a'; k <= 'z'; k++)
		{
			gain *= ifact[cnt[k]];
			gain %= INF;
		}
		for (char j = 'a'; j < b[i]; j++)
		{
			if (cnt[j] == 0)
			{
				continue;
			}
			ll curgain = gain;
			curgain *= ifact[cnt[j] - 1];
			curgain %= INF;
			curgain *= fact[cnt[j]];
			curgain %= INF;
			cb += curgain;
			//			cerr << gain << endl;
		}
		//or you don't
		if (cnt[b[i]] == 0)
		{
			break;
		}
		cnt[b[i]]--;
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		cnt[c] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		cnt[a[i]]++;
	}
	//same thing for a...
	for (int i = 0; i < N; i++)
	{
		ll gain = fact[N - i - 1];
		for (char k = 'a'; k <= 'z'; k++)
		{
			gain *= ifact[cnt[k]];
			gain %= INF;
		}
		for (char j = 'a'; j < a[i]; j++)
		{
			if (cnt[j] == 0)
			{
				continue;
			}
			ll curgain = gain;
			curgain *= ifact[cnt[j] - 1];
			curgain %= INF;
			curgain *= fact[cnt[j]];
			curgain %= INF;
			ca += curgain;
		}
		//or you don't
		if (cnt[a[i]] == 0)
		{
			break;
		}
		cnt[a[i]]--;
	}
	ans = normalize(cb - ca - 1);
	cout << ans << '\n';
	return 0;
}