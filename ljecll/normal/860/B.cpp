/*
PROG: cf860b
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

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
//#pragma GCC target("avx,tune=native")

#define MP make_pair
#define PB push_back

#define MAGIC 400
#define SINF 10001
#define INF 1000000861
#define LLINF 1000000000000000861ll
#define MOD 1000000007
#define MOD2 INF
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 100010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N;
string arr[MAXN];
set<pll> s;
map<pll, int> mp;
int ans[MAXN], lt[MAXN], rt[MAXN];
pll hashval;

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf860b.in", "r"))
	{	
		freopen ("cf860b.in", "r", stdin);
		//freopen ("cf860b.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < arr[i].length(); j++)
		{
			hashval = MP(0, 0);
			for (int k = j; k < arr[i].length(); k++)
			{
				//find the hash of this range
				hashval.first *= CO;
				hashval.first += arr[i][k];
				hashval.first %= MOD;
				hashval.second *= CO;
				hashval.second += arr[i][k];
				hashval.second %= MOD2;
				s.insert(hashval);
			}
		}
		for (auto it = s.begin(); it != s.end(); it++)
		{
			mp[*it]++;
		}
		s.clear();
	}
	for (int i = 0; i < N; i++)
	{
		ans[i] = INF;
		for (int j = 0; j < arr[i].length(); j++)
		{
			hashval = MP(0, 0);
			for (int k = j; k < arr[i].length(); k++)
			{
				hashval.first *= CO;
				hashval.first += arr[i][k];
				hashval.first %= MOD;
				hashval.second *= CO;
				hashval.second += arr[i][k];
				hashval.second %= MOD2;
				if (mp[hashval] == 1 && (k - j + 1) < ans[i])
				{
					ans[i] = k - j + 1;
					lt[i] = j;
					rt[i] = k;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = lt[i]; j <= rt[i]; j++)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}