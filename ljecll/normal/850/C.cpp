/*
PROG: cf850c
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

#define MP make_pair
#define PB push_back

#define SINF 10001
#define INF 1000000861
#define LLINF 1000000000000000861ll
#define MOD 1000000007
#define SQR 400
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 1000010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N;
ll arr[MAXN];
ll grundy;
bool prime[MAXN];
ll val;
map<ll, int> masks;
map<ll, int> mp;
map<ll, int> factors[MAXN];

void factorize(ll x)
{
	ll temp = x;
	for (ll i = 2; i * i <= x; i++)
	{
		ll cnt = 0;
		if (temp % i)
		{
			continue;
		}
		while (temp % i == 0)
		{
			cnt++;
			temp /= i;
		}
		masks[i] = masks[i] bitor (1ll << cnt);
	}
	if (temp != 1)
	{
		masks[temp] = masks[temp] bitor (2);
	}
}
ll sg(ll mask)
{
	if (mask == 0)
	{
		return 0;
	}
	if (mp.find(mask) != mp.end())
	{
		return mp[mask];
	}
	set<int> s;
	for (int i = 1; (1ll << i) <= mask; i++)
	{
		ll val = 0;
		for (int j = 1; j < 40; j++)
		{
			if (!(mask & (1ll << j)))
			{
				continue;
			}
			if (j < i)
			{
				val = val bitor (1ll << j);
			}
			if (j > i)
			{
				val = val bitor (1ll << (j - i));
			}
		}
		s.insert(sg(val));
	}
	for (int i = 0; ; i++)
	{
		if (s.find(i) == s.end())
		{
			mp[mask] = i;
			return i;
		}
	}
}


int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf850c.in", "r"))
	{	
		freopen ("cf850c.in", "r", stdin);
		//freopen ("cf850c.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		ll x;
		cin >> x;
		factorize(x);
	}
	for (auto it = masks.begin(); it != masks.end(); it++)
	{
		grundy = grundy xor sg(it -> second);
	}
	if (grundy)
	{
		cout << "Mojtaba\n";
	}
	else
	{
		cout << "Arpa\n";
	}
	return 0;
}