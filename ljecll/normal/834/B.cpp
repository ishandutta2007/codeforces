/*
PROG: cf834b
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
#define MAXN 1000010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, K;
string s;
int arr[MAXN];
int late[MAXN];
int early[MAXN];
int cnt[MAXN];

int32_t main()
{
	cout << fixed << setprecision(10);	
	ios_base::sync_with_stdio(false);
	if (fopen("cf834b.in", "r"))
	{	
		freopen ("cf834b.in", "r", stdin);
		freopen ("cf834b.out", "w", stdout);
	}
	cin >> N >> K;
	cin >> s;
	for (int i = 0; i < N; i++)
	{
		arr[i] = (s[i] - 'A');
	}
	for (int i = 0; i < 26; i++)
	{
		late[i] = -INF;
		early[i] = INF;
	}
	for (int i = 0; i < N; i++)
	{
		late[arr[i]] = max(late[arr[i]], i);
		early[arr[i]] = min(early[arr[i]], i);
	}
	for (int i = 0; i < 26; i++)
	{
		if (early[i] == INF)
		{
			continue;
		}
		cnt[early[i]]++;
		cnt[late[i] + 1]--;
	}
	for (int i = 0; i < N; i++)
	{
		cnt[i] += cnt[i - 1];
		if (cnt[i] > K)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}