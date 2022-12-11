/*
PROG: cf820a
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

int N, V0, V1, A, L;
int loc;
int speed;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf820a.in", "r"))
	{	
		freopen ("cf820a.in", "r", stdin);
		freopen ("cf820a.out", "w", stdout);
	}
	cin >> N >> V0 >> V1 >> A >> L;
	speed = V0;
	for (int i = 0; ; i++)
	{
		if (loc >= N)
		{
			cout << i << '\n';
			return 0;
		}
		if (i != 0)
		{
			loc -= L;
		}
		loc += speed;
		speed += A;
		speed = min(speed, V1);
	}
	return 0;
}