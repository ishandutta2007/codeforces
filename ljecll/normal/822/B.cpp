/*
PROG: cf822b
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
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MP make_pair
#define PB push_back

#define SINF 10001
#define INF 1000000007
#define MOD INF
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 1010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, M;
string s, t;
int ans = INF;
int bestidx;

int test(int idx)
{
	int res = 0;
	for (int i = idx; i < idx + s.length(); i++)
	{
		if (t[i] != s[i - idx])
		{
			res++;
		}
	}
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf822b.in", "r"))
	{	
		freopen ("cf822b.in", "r", stdin);
		freopen ("cf822b.out", "w", stdout);
	}
	cin >> N >> M >> s >> t;
	for (int i = 0; i <= t.length() - s.length(); i++)
	{
		if (test(i) < ans)
		{
			ans = test(i);
			bestidx = i;
		}
	}
	cout << ans << '\n';
	for (int i = bestidx; i < bestidx + s.length(); i++)
	{
		if (t[i] != s[i - bestidx])
		{
			cout << i - bestidx + 1 << ' ';
		}
	}
	cout << '\n';
	return 0;
}