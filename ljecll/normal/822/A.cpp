/*
PROG: cf822a
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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int a, b;
ll res = 1;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf822a.in", "r"))
	{	
		freopen ("cf822a.in", "r", stdin);
		freopen ("cf822a.out", "w", stdout);
	}
	cin >> a >> b;
	if (a > b)
	{
		swap(a, b);
	}
	for (int i = 1; i <= a; i++)
	{
		res *= i;
	}
	cout << res << '\n';
	return 0;
}