/*
PROG: cf853b
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

#define SINF 10001
#define INF 1000000861
#define LLINF 4000000000861ll
#define MOD 1000000007
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

int N, M, K;
vector<pll> in[MAXN], out[MAXN];
ll ans = LLINF, cur;
ll BIG;
ll was[MAXN];
ll gin[MAXN], gout[MAXN];
//pair day, cost

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf853b.in", "r"))
	{	
		freopen ("cf853b.in", "r", stdin);
		//freopen ("cf853b.out", "w", stdout);
	}
	cin >> N >> M >> K;
	BIG = 2 * LLINF * N;
	for (int i = 0; i < M; i++)
	{
		int day, from, to;
		ll cost;
		cin >> day >> from >> to >> cost;
		if (from == 0)
		{
			out[to].PB(MP(day, cost));
		}
		else
		{
			in[from].PB(MP(day, cost));
		}
	}
	for (int i = 1; i <= N; i++)
	{
		sort(out[i].begin(), out[i].end());
		reverse(out[i].begin(), out[i].end());
		sort(in[i].begin(), in[i].end());
	}
	for (int i = 1; i <= N; i++)
	{
		was[i] = LLINF;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < in[i].size(); j++)
		{
			int t = in[i][j].first;
			ll c = in[i][j].second;
			if (was[i] > c)
			{
				gin[t] += (was[i] - c);
				was[i] = c;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		was[i] = LLINF;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < out[i].size(); j++)
		{
			int t = out[i][j].first;
			ll c = out[i][j].second;
			if (was[i] > c)
			{
				gout[t] += (was[i] - c);
				was[i] = c;
			}
		}
	}
	for (int t = 1; t <= 1000000; t++)
	{
		gin[t] += gin[t - 1];
	}
	for (int t = 1000000; t >= 0; t--)
	{
		gout[t] += gout[t + 1];
	}
	for (int i = 0; i + K + 1 <= 1000000; i++)
	{
		ans = min(ans, BIG - gin[i] - gout[i + K + 1]);
	}
	if (ans >= LLINF)
	{
		cout << "-1\n";
		return 0;
	}
	cout << ans << '\n';
	return 0;
		//store the min of all costs on or after a given point
}