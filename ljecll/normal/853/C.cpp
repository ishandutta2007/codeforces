/*
PROG: cf853c
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
#define LLINF 1000000000000000861ll
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
typedef pair<pll, pll> ppp;

int N, Q;
int arr[MAXN], rev[MAXN];
ll tree[MAXN];
ll ans[MAXN];
int L[MAXN], R[MAXN], D[MAXN], U[MAXN];
vector<ppp> v[MAXN]; //L, R, idx, +-

ll choose2(ll x)
{
	return (x * (x - 1))/2;
}
ll get(int idx)
{
	ll sum = 0ll;
	for (int e = idx + 1; e > 0; e -= (e & (-e)))
	{
		sum += tree[e];
	}
	return sum;
}
void update(int idx, ll val)
{
	for (int e = idx + 1; e <= N; e += (e & (-e)))
	{
		tree[e] += val;
	}
	return;
}
ll range(int lt, int rt)
{
	if (lt > rt)
	{
		return 0ll;
	}
	if (lt < 0 || lt >= N || rt < 0 || rt >= N)
	{
		return 0ll;
	}
	if (lt == 0)
	{
		return get(rt);
	}
	return get(rt) - get(lt - 1);
}

int32_t main()
{
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	if (fopen("cf853c.in", "r"))
	{	
		freopen ("cf853c.in", "r", stdin);
		//freopen ("cf853c.out", "w", stdout);
	}
	N = readi();
	Q = readi();
	for (int i = 0; i < N; i++)
	{
		arr[i] = readi();
		arr[i]--;
		rev[arr[i]] = i;
	}
	for (int i = 0; i < Q; i++)
	{
		L[i] = readi();
		D[i] = readi();
		R[i] = readi();
		U[i] = readi();
		L[i]--; D[i]--; R[i]--; U[i]--;
		ans[i] = choose2(N);
	}
	for (int i = 0; i <= N; i++)
	{
		tree[i] = 0ll;
	}
	for (int i = 0; i < Q; i++)
	{
		v[L[i] - 1].PB(MP(MP(0, N - 1), MP(i, -1)));
		v[N - 1].PB(MP(MP(0, D[i] - 1), MP(i, -1)));
		v[N - 1].PB(MP(MP(U[i] + 1, N - 1), MP(i, -1)));
		v[L[i] - 1].PB(MP(MP(0, D[i] - 1), MP(i, 1)));
		v[L[i] - 1].PB(MP(MP(U[i] + 1, N - 1), MP(i, 1)));
		//	ans -= choose2(rect(0, 0, L - 1, N - 1));
		//	ans -= choose2(rect(0, 0, N - 1, D - 1));
		//	ans -= choose2(rect(0, U + 1, N - 1, N - 1));
		//	ans += choose2(rect(0, 0, L - 1, D - 1));
		//	ans += choose2(rect(0, U + 1, L - 1, N - 1));
	}
	for (int i = 0; i < N; i++)
	{
		update(arr[i], 1ll);
//		cerr << "processing " << i << endl;
		for (int j = 0; j < v[i].size(); j++)
		{
			ans[v[i][j].second.first] += ((choose2(range(v[i][j].first.first, v[i][j].first.second))) * v[i][j].second.second);
//			cerr << v[i][j].first.first << ' ' << v[i][j].first.second << ' ' << range(v[i][j].first.first, v[i][j].first.second) << endl;
//			cerr << range(v[i][j].first.first, v[i][j].first.second) << ' ' << v[i][j].second.second << endl;
		}
		v[i].clear();
	}
	for (int i = 0; i <= N; i++)
	{
		tree[i] = 0ll;
	}
	for (int i = 0; i < Q; i++)
	{
		v[R[i] + 1].PB(MP(MP(0, N - 1), MP(i, -1)));
		v[R[i] + 1].PB(MP(MP(0, D[i] - 1), MP(i, 1)));
		v[R[i] + 1].PB(MP(MP(U[i] + 1, N - 1), MP(i, 1)));
		//	ans -= choose2(rect(R + 1, 0, N - 1, N - 1));
		//	ans += choose2(rect(R + 1, 0, N - 1, D - 1));
		//	ans += choose2(rect(R + 1, U + 1, N - 1, N - 1));
	}
	for (int i = N - 1; i >= 0; i--)
	{
		update(arr[i], 1ll);
//		cerr << "processing " << i << endl;
		for (int j = 0; j < v[i].size(); j++)
		{
			ans[v[i][j].second.first] += ((choose2(range(v[i][j].first.first, v[i][j].first.second))) * v[i][j].second.second);
//			cerr << v[i][j].first.first << ' ' << v[i][j].first.second << ' ' << range(v[i][j].first.first, v[i][j].first.second) << endl;
//			cerr << range(v[i][j].first.first, v[i][j].first.second) << ' ' << v[i][j].second.second << endl;
		}
	}
	for (int i = 0; i < Q; i++)
	{
		printi(ans[i]);
		putchar('\n');
	}
	return 0;
}