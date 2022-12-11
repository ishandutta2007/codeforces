/*
PROG: cf868c
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
#define MAXK 5

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, K;
int mask[MAXN];
int cnt[(1 << MAXK)];

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf868c.in", "r"))
	{	
		freopen ("cf868c.in", "r", stdin);
		//freopen ("cf868c.out", "w", stdout);
	}
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int x;
			cin >> x;
			mask[i] += x * (1 << j);
		}
		cnt[mask[i]]++;
	}
	if (cnt[0])
	{
		cout << "YES\n";
		return 0;
	}
	for (int i = 1; i < (1 << K); i++)
	{
		for (int j = 1; j < (1 << K); j++)
		{
			bool flag = true;
			for (int k = 0; k < K; k++)
			{
				if ((i & (1 << k)) && (j & (1 << k)))
				{
					flag = false;
				}
			}
			if (!flag)
			{
				continue;
			}
			if (cnt[i] && cnt[j])
			{
//				cerr << i << ' ' << j << endl;
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}