#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200100, maxabs = 200100;

int n;

vector<int> fac[maxabs + 5];

vector<int> p[maxabs + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 1; i <= maxabs; ++i) for (int j = i; j <= maxabs; j += i) fac[j].pb(i);
	scanf("%d", &n);
	REP(i, 0, n) 
	{
		int x;
		scanf("%d", &x);
		for (auto u : fac[x]) p[u].pb(i);
	}

	LL ans = 0;
	static int far[maxn + 5];
	set<int> pos;
	REP(i, 0, n) far[i] = i, pos.insert(i);

	//This is a lambda function. See http://en.cppreference.com/w/cpp/language/lambda for details.
	auto add = [&](int x)
	{
		auto tmp = pos.lower_bound(x);
		if (*tmp == x) return;
		far[x] = far[*tmp];
		pos.insert(x);
	};

	auto upd = [&](int a, int b, int val) 
	{ 
		if (a) add(a - 1);
		auto from = pos.lower_bound(a), to = from;
		int lst = a - 1;
		for (auto it = from; it != pos.end() && far[*it] < b; ++it) 
		{
			to = it;
			ans += (LL)val * (b - far[*it]) * (*it - lst);
			far[*it] = b;
			lst = *it;
		}
		pos.erase(from, to);
	};

	for (int i = maxabs; i >= 1; --i)
	{
		if (SZ(p[i]) >= 2)
		{
			int sz = SZ(p[i]);
			upd(0, p[i][sz - 2], i);
			upd(p[i][1] + 1, n, i);
			upd(p[i][0] + 1, p[i][sz - 1], i);
		}
	}

	printf("%I64d\n", ans);
	return 0;
}