/*
PROG: cf439a
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back

#define SINF 10001
#define INF 1000000007
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI ((4.0) * atan(1.0))
#define MAXN 128

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int N, D;
int arr[MAXN];
int need;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf439a.in", "r"))
	{	
		freopen ("cf439a.in", "r", stdin);
		freopen ("cf439a.out", "w", stdout);
	}
	cin >> N >> D;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		need += arr[i];
	}
	need += (N - 1) * 10;
	if (need > D)
	{
		cout << "-1\n";
		return 0;
	}
	need -= (N - 1) * 10;
	int rem = D - need;
	cout << rem/5 << '\n';
	return 0;
}