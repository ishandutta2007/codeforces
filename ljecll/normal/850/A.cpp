/*
PROG: cf850a
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
#define MAXN 1010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N;
ll arr[5][MAXN];
bool bad[MAXN];
int ans;

ll scalar(ll a, ll b, ll c)
{
	ll res = 0ll;
	for (ll i = 0; i < 5; i++)
	{
		res += ((arr[i][b] - arr[i][a]) * (arr[i][c] - arr[i][a]));
	}
	return res;
}

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf850a.in", "r"))
	{	
		freopen ("cf850a.in", "r", stdin);
		//freopen ("cf850a.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[j][i];
		}
	}
	if (N >= 100)
	{
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j == i)
			{
				continue;
			}
			for (int k = j + 1; k < N; k++)
			{
				if (k == i)
				{
					continue;
				}
				if (scalar(i, j , k) > 0)
				{
					bad[i] = true;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (!bad[i])
		{
			ans++;
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < N; i++)
	{
		if (!bad[i])
		{
			cout << i + 1 << '\n';
		}
	}
	return 0;
}