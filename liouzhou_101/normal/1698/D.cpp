//#include "IO.h"

#include <bits/stdc++.h>

namespace io { }
namespace algorithm { }
namespace data_structure { }

using namespace std;
using namespace io;
using namespace algorithm;
using namespace data_structure;

#ifdef ONLINE_JUDGE
#define debug 0
#else
#define debug 1
#endif

template<class T, class U>
bool freshmax(T& a, const U& b)
{
	return a < T(b) ? a = b, 1 : 0;
}

template<class T, class U>
bool freshmin(T& a, const U& b)
{
	return a > T(b) ? a = b, 1 : 0;
}

//using modular = algorithm::Modular<uint32_t, 998244353, true, 3>;
//using modular = algorithm::SafeModularInt32<1000000007>;
//using modular = algorithm::SafeUserModularInt32;

//using modint = algorithm::ModInt<modular>;
//using poly = algorithm::Polynomial<modular>;
//using linear = algorithm::LinearRecurrence<modular>;

using ll = long long;
using ull = unsigned long long;
using ld = double;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

mt19937 rd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
	int n;
	cin >> n;

	auto check = [&](int m)
	{
		cout << "? " << 1 << " " << m << endl;
		int g = 0;
		for (int i = 1; i <= m; ++i)
		{
			int x;
			cin >> x;
			if (x > m) g += 1;
		}
		return (g % 2 != m % 2);
	};

	int L = 1, R = n, res = n + 1;
	while (L <= R)
	{
		int m = (L + R) / 2;
		if (check(m))
		{
			res = m;
			R = m - 1;
		}
		else
			L = m + 1;
	}
	cout << "! " << res << endl;
}

int main()
{
#if debug
	//freopen("try.in", "r", stdin);
	//freopen("try.out", "w", stdout);
#endif
	int tests = 1;
	//tests = next<int>();
	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}
	return 0;
}