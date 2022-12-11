/*
PROG: cf894b
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
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

#define SINF 10007
#define INF 1000000007
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793

long long normalize(long long x)
{
	return (((x % INF) + INF) % INF);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, M, K;
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

int32_t main()
{
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	//	cout << fixed << setprecision(10);	
	//	cerr << fixed << setprecision(10);
	//	if (fopen("cf894b.in", "r"))
	//	{	
	//		freopen ("cf894b.in", "r", stdin);
	//		freopen ("cf894b.out", "w", stdout);
	//	}
	cin >> N >> M >> K;
	N %= (INF - 1);
	M %= (INF - 1);
	if (((N + M) % 2) && (K == -1))
	{
		cout << "0\n";
		return 0;
	}
	N += (INF - 1);
	M += (INF - 1);
	cout << normalize(getpow(2ll, (N - 1) * (M - 1))) << '\n';
	return 0;
}