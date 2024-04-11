/*
PROG: cf856a
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
#define MAXN 1000010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int T;
int N;
int arr[MAXN];
vector<int> banned;
bool in[MAXN];
vector<int> ans;

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf856a.in", "r"))
	{	
		freopen ("cf856a.in", "r", stdin);
		//freopen ("cf856a.out", "w", stdout);
	}
	cin >> T;
	while (T--)
	{
		banned.clear();
		ans.clear();
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				banned.PB(arr[i] - arr[j]);
			}
		}
		sort(banned.begin(), banned.end());
		banned.erase(unique(banned.begin(), banned.end()), banned.end());
		for (int i = 1; i <= 1000000; i++)
		{
			in[i] = true;
		}
		int iter = 1;
		for (int i = 0; i < N; i++)
		{
			while(iter <= 1000000 && !in[iter])
			{
				iter++;
			}
			if (iter > 1000000)
			{
				break;
			}
			ans.PB(iter);
			in[iter] = false;
			for (int j = 0; j < banned.size(); j++)
			{
				if (iter + banned[j] <= 1000000)
				{
					in[iter + banned[j]] = false;
				}
			}
		}
		if (ans.size() == N)
		{
			cout << "YES\n";
			for (int j = 0; j < N; j++)
			{
				cout << ans[j] << ' ';
			}
			cout << '\n';
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}