#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 50100;
const int maxa = 100100;

int n;
int a[maxn + 5];

vector<int> all[maxa + 5];
vector<int> fac[maxa + 5];

inline LL calc(LL from, LL step, LL num, LL Mod)
{
	if (from + step * num < Mod)
	{
		return 0;
	}
	if ((step << 1) > Mod)
	{
		return (num * (num + 1) >> 1) - calc(Mod - from - 1, Mod - step, num, Mod);
	}
	LL tmp = (Mod - from + step - 1) / step;
	num -= tmp;
	from = (from + tmp * step) % Mod;
	LL each = (Mod + step - 1) / step;
	LL ret = num + 1 + each * (num / each * (num / each - 1) >> 1);
	ret += (num / each) * (num % each + 1);
	ret += calc(from, each * step - Mod, num * step / Mod, step);
	tmp = num * step / Mod - num / each;
	ret -= each * (tmp * (tmp + 1) >> 1) - tmp * (num % each + 1);
	return ret;
}

inline LL work(LL a0, LL n0, LL a1, LL n1, LL res)
{
	LL ret = 0;
	if (a1 * n1 <= res)
	{
		LL tmp = min(n0, (res - a1 * n1) / a0);
		ret += (tmp + 1) * (n1 + 1);
		if (tmp == n0) return ret;
		n0 -= tmp + 1;
		res -= (tmp + 1) * a0;
	}
	if (res >= 0)
	{
		n0 = min(n0, res / a0);
		res -= n0 * a0;
		ret += (res / a1) * (n0 + 1);
		ret += n0 + 1 + calc(res % a1, a0, n0, a1);
	}
	return ret;
}

LL num[maxa + 5];
LL grand_total;

inline LL check(const LL &x)
{
	LL ret = 0;
	LL sum = 0;
	LL cnt = 0;
	int j = 1;
	REP(i, 1, maxa + 1)
	{
		cnt -= num[i];
		sum -= num[i] * i;

		if (num[i] > 0 && cnt > 0)
		{
			ret += num[i] * cnt; 
		}

		LL tmp = min(num[i], x / i);
		ret += (num[i] - tmp) * tmp + (tmp * (tmp + 1) >> 1);
		if (i < j)
		{
			if (num[i] && num[j]) ret += work(i, num[i] - 1, j, num[j] - 1, x - sum - i - j);
		}
		while (j <= maxa && sum + num[j] * j <= x)
		{
			cnt += num[j];
			sum += num[j] * j;
			++j;
			if (num[i] && num[j]) ret += work(i, num[i] - 1, j, num[j] - 1, x - sum - i - j);
		}
	}
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 1; i <= maxa; ++i)
		for (int j = i; j <= maxa; j += i)
			fac[j].pb(i);
	scanf("%d", &n);
	REP(i, 0, n)
	{
		scanf("%d", a + i);
		for (auto u : fac[a[i]]) 
			all[u].pb(i);
	}
	for (int i = maxa; i >= 1; --i)
	{
		LL cnt = 0;
		all[i].pb(n + 1);
		int lst = -2;
		int tmp = 0;
		for (auto u : all[i])
		{
			if (u != lst + 1) cnt += LL(tmp) * (tmp + 1) >> 1, tmp = 1;
			else ++tmp;
			lst = u;
		}
		num[i] = cnt;
		for (int j = i << 1; j <= maxa; j += i)
			num[i] -= num[j];
	}
	LL l = 0, r = 1e18;
	grand_total = ((LL)n * (n + 1) >> 1) * (((LL)n * (n + 1) >> 1) + 1) >> 1;
	LL goal = (grand_total + 1) >> 1;
	while (l < r)
	{
		LL mid = (l + r + 1) >> 1;
		if (check(mid) >= goal) r = mid - 1;
		else l = mid;
	}
	cout << l + 1 << endl;
	return 0;
}