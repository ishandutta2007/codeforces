/*
PROG: cf839b
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
	vector<char> vout;
	while(output)
	{
		vout.push_back((output % 10) + '0');
		output /= 10;
	}
	for (int i = vout.size() - 1; i >= 0; i--)
	{
		putchar(vout[i]);
	}
	return;
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
#define MOD 1000000007
#define LLINF 1000000000000000861ll
#define SQR 400
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXK 110

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, K;
int arr[MAXK];
int one, two, four;

int32_t main()
{
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf839b.in", "r"))
	{	
		freopen ("cf839b.in", "r", stdin);
		freopen ("cf839b.out", "w", stdout);
	}
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
	}
	one = 0;
	two = 2 * N;
	four = N;
	for (int i = 0; i < K; i++)
	{
		int take = min(arr[i]/4, four);
		arr[i] -= 4 * take;
		four -= take;
	}
	two += four;
	one += four;
	four = 0;
	for (int i = 0; i < K; i++)
	{
		int take = min(arr[i]/2, two);
		arr[i] -= 2 * take;
		two -= take;
	}
	one += two;
	two = 0;
	for (int i = 0; i < K; i++)
	{
		int take = min(arr[i], one);
		arr[i] -= take;
		one -= take;
	}
	for (int i = 0; i < K; i++)
	{
		if (arr[i])
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}