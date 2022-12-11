/*
PROG: cf875b
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

#define MP make_pair
#define PB push_back
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound

#define SINF 10007
#define MOD 1000000007
#define INF 1000000861
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 300010

typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int ptr;
bool in[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	//	if (fopen("cf875b.in", "r"))
	//	{
	//		freopen ("cf875b.in", "r", stdin);
	//		freopen ("cf875b.out", "w", stdout);
	//	}
	cin >> N;
	ptr = N;
	cout << '1';
	for (int i = 0; i < N; i++)
	{
		//answer is (i + 1 - continguousblock)
		int x;
		cin >> x;
		x--;
		in[x] = true;
//		cerr << ptr - 1 << endl;
//		cerr << in[N - 1] << endl;
		while (ptr > 0 && in[ptr - 1])
		{
			ptr--;
		}
//		cerr << ptr << endl;
		cout << ' ' << i - (N - ptr) + 2;
	}
	cout << '\n';
	return 0;
}