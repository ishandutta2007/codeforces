/*
PROG: cf868b
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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int H, M, S, T[2];
int h, m, s, t1, t2;
int x[3];
int batch[2];

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf868b.in", "r"))
	{	
		freopen ("cf868b.in", "r", stdin);
		//freopen ("cf868b.out", "w", stdout);
	}
	cin >> H >> M >> S >> T[0] >> T[1];
	H *= 5;
	T[0] *= 3600;
	T[1] *= 3600;
	s = S * 720;
	m = 720 * M + 12 * S;
	h = 720 * H + 60 * M + S;
	s %= 43200;
	m %= 43200;
	h %= 43200;
	//smh
	x[0] = s;
	x[1] = m;
	x[2] = h;
	sort(x, x + 3);
	for (int i = 0; i < 2; i++)
	{
		if (x[0] <= T[i] && T[i] <= x[1])
		{
			batch[i] = 1;
		}
		else if (x[1] <= T[i] && T[i] <= x[2])
		{
			batch[i] = 2;
		}
		else
		{
			batch[i] = 0;
		}
	}
	if (batch[0] == batch[1])
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}