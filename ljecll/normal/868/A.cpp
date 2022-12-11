/*
PROG: cf868a
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
#define MAXN 110

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N;
string s;
string arr[MAXN];

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf868a.in", "r"))
	{	
		freopen ("cf868a.in", "r", stdin);
		//freopen ("cf868a.out", "w", stdout);
	}
	cin >> s >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] == s)
		{
			cout << "YES\n";
			return 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][1] == s[0] && arr[j][0] == s[1])
			{
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}