/*
PROG: cf840a
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

#define SINF 10001
#define INF 1000000861
#define LLINF 1000000000000000861ll
#define MOD 1000000007
#define SQR 400
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 200010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N;
int arr[MAXN];
int temp[MAXN];
int ans[MAXN];
int res[MAXN];

bool cmp(int x, int y)
{
	return arr[x] > arr[y];
}

int32_t main()
{
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf840a.in", "r"))
	{	
		freopen ("cf840a.in", "r", stdin);
		//freopen ("cf840a.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> res[i];
	}
	sort(res, res + N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		temp[i] = i;
	}
	sort(temp, temp + N, cmp);
	for (int i = 0; i < N; i++)
	{
		ans[temp[i]] = res[i];
	}
	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}