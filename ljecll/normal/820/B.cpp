/*
PROG: cf820b
LANG: C++
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
typedef pair<long long, long long> pll;

int N;
ld A;
ld sm;
ld bestdist = INF;
int ans;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf820b.in", "r"))
	{	
		freopen ("cf820b.in", "r", stdin);
		freopen ("cf820b.out", "w", stdout);
	}
	cin >> N >> A;
	if (N == 3)
	{
		cout << "1 2 3\n";
		return 0;
	}
	cout << "1 ";
	sm = (180.0)/(ld) N;
	for (int i = 1; i < N - 1; i++)
	{
		ld cur = sm * (ld) i;
//		cerr << i << ' ' << cur << endl;
		if (abs(cur - A) < bestdist)
		{
			bestdist = abs(cur - A);
			ans = i + 1;
		}
	}
	cout << N << ' ' << ans << '\n';
	return 0;
}