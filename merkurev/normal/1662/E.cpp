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

const int maxn = 200005;

int f[maxn];
int p[maxn], wh[maxn];
int n;

int getf(int x)
{
	int ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
	{
		ans += f[x];
	}
	return ans;
}

void add(int x, int t)
{
	for (; x <= n; x |= (x + 1))
	{
		f[x] += t;
	}
}

int getf(int l, int r)
{
	return getf(r) - getf(l - 1);
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &p[i]), p[i]--;
	for (int i = 0; i < n; i++) wh[p[i]] = i;
	int wh0 = wh[0];
	for (int i = 0; i < n; i++) wh[i] = (wh[i] - wh0 + n) % n;
	for (int i = 0; i <= n; i++) f[i] = 0;
	ll answer = 0;
	add(0, 1);
	for (int i = 1; i < n; i++)
	{
		if (wh[i] > wh[i - 1])
		{
			answer += (ll)getf(wh[i - 1] + 1, wh[i]) * (n - i);
		} else
		{
			answer += (ll)getf(wh[i - 1] + 1, n - 1) *  (n - i);
			answer += (ll)getf(0, wh[i]) * (n - i);
		}
		add(wh[i], 1);
	}
	printf("%lld\n", answer);
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++) solve();
    return 0;
}