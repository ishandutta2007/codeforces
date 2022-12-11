/*
PROG: cf875c
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
#define MAXN 1000010

typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
vector<int> arr[MAXN];
int state[MAXN];
vector<int> edge[MAXN], rev[MAXN]; //if we capitalize a, then we must capitalize b
bool can[MAXN][2];
bool seen[MAXN][2];
vector<int> ans;

void die()
{
	cout << "No\n";
	exit(0);
}
bool check(int idx, bool flag)
{
	if (!can[idx][flag])
	{
		return false;
	}
	if (seen[idx][flag])
	{
		return can[idx][flag];
	}
	seen[idx][flag] = true;
	if (flag)
	{
		for (int i = 0; i < edge[idx].size(); i++)
		{
			int v = edge[idx][i];
			if (check(v, flag) == false)
			{
				can[idx][flag] = false;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < rev[idx].size(); i++)
		{
			int v = rev[idx][i];
			if (check(v, flag) == false)
			{
				can[v][flag] = false;
				break;
			}
		}
	}
	return can[idx][flag];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	//	if (fopen("cf875c.in", "r"))
	//	{
	//		freopen ("cf875c.in", "r", stdin);
	//		freopen ("cf875c.out", "w", stdout);
	//	}
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int sz;
		cin >> sz;
		for (int j = 0; j < sz; j++)
		{
			int let;
			cin >> let;
			let--;
			arr[i].PB(let);
		}
	}
	for (int i = 0; i < M; i++)
	{
		can[i][0] = true;
		can[i][1] = true;
	}
	//0 if dont know, 1 if must, 2 if mustnt, 3 if dontcare
	//1 if u must capitalize, -1 if u mustnt, -2 if u dont care
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < min(arr[i].size(), arr[i - 1].size()); j++)
		{
			if (arr[i - 1][j] > arr[i][j])
			{
				//gotta capitalize arr[i - 1][j]
				can[arr[i - 1][j]][0] = false;
				can[arr[i][j]][1] = false;
				break;
			}
			else if (arr[i - 1][j] < arr[i][j])
			{
				edge[arr[i][j]].PB(arr[i - 1][j]); //if u capitalize the first one, u gotta capitalize the second
				rev[arr[i - 1][j]].PB(arr[i][j]);
				break;
			}
			if (j == (min(arr[i].size(), arr[i - 1].size()) - 1) && arr[i].size() < arr[i - 1].size())
			{
				die();
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		check(i, 0);
		check(i, 1);
	}
	for (int i = 0; i < M; i++)
	{
		if (!can[i][0] && !can[i][1])
		{
			die();
		}
	}
	cout << "Yes\n";
	for (int i = 0; i < M; i++)
	{
		if (can[i][1])
		{
			ans.PB(i);
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] + 1 << ' ';
	}
	cout << '\n';
	return 0;
}