#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int ma = 0;
	int mb = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		ma = max(ma, a);
		mb = max(mb, b);
	}
	if (ma + mb > n) printf("IMPOSSIBLE\n");
	else
	{
		mb = n - ma;
		printf("%s\n", (string(ma, 'R') + string(mb, 'W')).c_str());
	}
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T =0 ; T < NT; T++) solve();
    return 0;
}