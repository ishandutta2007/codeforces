/*
PROG: cf901a
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
const long double EPS = 1e-30;

#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 200010

long long normalize(long long x, long long mod)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int arr[MAXN];
bool res;
int L[MAXN], R[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf901a.in", "r"))
	{	
		freopen ("cf901a.in", "r", stdin);
		freopen ("cf901a.out", "w", stdout);
	}
	cin >> N;
	N++;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++)
	{
		if (arr[i] != 1 && arr[i - 1] != 1)
		{
			res = true;
		}
	}
	if (!res)
	{
		cout << "perfect\n";
		return 0;
	}
	cout << "ambiguous\n";
	L[0] = 1;
	R[0] = 1;
	for (int i = 1; i < N; i++)
	{
		L[i] = R[i - 1] + 1;
		R[i] = L[i] + arr[i] - 1;
	}
	cout << "0";
	for (int i = 1; i < N; i++)
	{
		if (arr[i] != 1 && arr[i - 1] != 1)
		{
			for (int j = L[i]; j <= R[i]; j++)
			{
				if (j % 2)
				{
					cout << ' ' << L[i - 1];
				}
				else
				{
					cout << ' ' << L[i - 1] + 1;
				}
			}
		}
		else
		{
			for (int j = L[i]; j <= R[i]; j++)
			{
				cout << ' ' << L[i - 1];
			}
		}
	}
	cout << '\n';
	cout << "0";
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			cout << ' ' << L[i - 1];
		}
	}
	cout << '\n';
	return 0;
}