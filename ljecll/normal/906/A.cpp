/*
PROG: cf906a
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
#define MAXN 100010

long long normalize(long long x, long long mod)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int qid[MAXN];
int mask[MAXN];
int curmask;
int res;
int globe = (1 << 26) - 1;

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf906a.in", "r"))
	{	
		freopen ("cf906a.in", "r", stdin);
		freopen ("cf906a.out", "w", stdout);
	}
	cin >> N;
	curmask = globe;
	for (int i = 0; i < N; i++)
	{
		char ch;
		cin >> ch;
		if (ch == '!')
		{
			qid[i] = 2;
		}
		if (ch == '.')
		{
			qid[i] = 1;
		}
		if (ch == '?')
		{
			qid[i] = 3;
		}
		string s;
		cin >> s;
		for (char c : s)
		{
			mask[i] = mask[i] | (1 << (c - 'a'));
		}
	}
	res = mask[N - 1];
	for (int i = 0; i < N; i++)
	{
		if (qid[i] == 1)
		{
			//no shock, doesnt contain letter
			mask[i] = globe xor mask[i];
		}
		if (qid[i] == 3)
		{
			if (mask[i] != res)
			{
				mask[i] = globe xor mask[i];
			}
		}
//		cerr << mask[i] << endl;
		curmask = curmask & mask[i];
//		cerr << curmask << endl;
		if (__builtin_popcount(curmask) == 1)
		{
			//save everything from i + 1 to N - 2
			int ans = 0;
			for (int j = i + 1; j < N; j++)
			{
				if (qid[j] == 2)
				{
					ans++;
				}
				if (qid[j] == 3 && mask[j] != curmask)
				{
					ans++;
				}
			}
			cout << ans << '\n';
			return 0;
		}
	}
	//	cerr << lo << endl;
	return 0;
}