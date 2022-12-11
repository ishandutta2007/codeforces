/*
PROG: cf889b
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

#define MP make_pair
#define PB push_back
#define PF push_front
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
#define MAXN 100010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string arr[MAXN];
int edge[26];
int in[26];
int beg;
bool need[MAXN];
bool seen[MAXN];
string ans;

void kill()
{
	cout << "NO\n";
	exit(0);
}
void dfs(int u)
{
	ans += ('a' + u);
	seen[u] = true;
	if (edge[u] == -1)
	{
		return;
	}
	if (seen[edge[u]])
	{
		kill();
	}
	dfs(edge[u]);
	return;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	//	cout << fixed << setprecision(10);	
	//	cerr << fixed << setprecision(10);
	//	if (fopen("cf889b.in", "r"))
	//	{	
	//		freopen ("cf889b.in", "r", stdin);
	//		freopen ("cf889b.out", "w", stdout);
	//	}
	cin >> N;
	for (int i = 0; i < 26; i++)
	{
		edge[i] = -1;
		in[i] = -1;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
//		cerr << arr[i] << endl;
		for (int j = 0; j < arr[i].length(); j++)
		{
			need[arr[i][j] - 'a'] = true;
		}
		for (int j = 1; j < arr[i].length(); j++)
		{
//			cerr << j << endl;
//			cerr << arr[i][j - 1] - 'a' << endl;
			if (edge[arr[i][j - 1] - 'a'] != -1 && edge[arr[i][j - 1] - 'a'] != arr[i][j] - 'a')
			{
				kill();
			}
			if (in[arr[i][j] - 'a'] != -1 && in[arr[i][j] - 'a'] != arr[i][j - 1] - 'a')
			{
				kill();
			}
			edge[arr[i][j - 1] - 'a'] = arr[i][j] - 'a';
			in[arr[i][j] - 'a'] = arr[i][j - 1] - 'a';
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (need[i] && in[i] == -1 && !seen[i])
		{
			dfs(i);
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (need[i] && !seen[i])
		{
			kill();
		}
	}
	cout << ans << '\n';
	return 0;
	//find earliest one with no incoming edges and with 1 outgoing edge
}