/*
PROG: cf825b
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
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int grid[10][10];

int32_t main()
{
	cout << fixed << setprecision(10);	
	ios_base::sync_with_stdio(false);
	if (fopen("cf825b.in", "r"))
	{	
		freopen ("cf825b.in", "r", stdin);
		freopen ("cf825b.out", "w", stdout);
	}
	for (int i = 0; i < 10; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 10; j++)
		{
			if (s[j] == 'X')
			{
				grid[i][j] = 1;
			}
			if (s[j] == 'O')
			{
				grid[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i + 4 < 10 && grid[i][j] + grid[i + 1][j] + grid[i + 2][j] + grid[i + 3][j] + grid[i + 4][j] == 4)
			{
				cout << "YES\n";
				return 0;
			}
			if (j + 4 < 10 && grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i][j + 3] + grid[i][j + 4] == 4)
			{
				cout << "YES\n";
				return 0;
			}
			if (i + 4 < 10 && j + 4 < 10 && grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] + grid[i + 3][j + 3] + grid[i + 4][j + 4] == 4)
			{
				cout << "YES\n";
				return 0;
			}
			if (i + 4 < 10 && j - 4 >= 0 && grid[i][j] + grid[i + 1][j - 1] + grid[i + 2][j - 2] + grid[i + 3][j - 3] + grid[i + 4][j - 4] == 4)
			{
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}