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
	string t = "ababcdcdababccd";

	int n;
#if debug
	n = t.size();
#else
	cin >> n;
#endif

	auto q1 = [&](int i)
	{
#if debug
		return t[i - 1] - 'a';
#else
		cout << "? 1 " << i << endl;
		string res;
		cin >> res;
		return res[0] - 'a';
#endif
	};

	auto q2 = [&](int l, int r)
	{
#if debug
		set<char> H;
		for (int i = l; i <= r; ++i)
			H.insert(t[i - 1]);
		return H.size();
#else
		cout << "? 2 " << l << " " << r << endl;
		int res;
		cin >> res;
		return res;
#endif
	};

	vector<int> pre_diff(n + 1);
	for (int i = 1; i <= n; ++i)
		pre_diff[i] = q2(1, i);
	vector<int> res(n + 1, -1);
	for (int i = 1; i <= n; ++i)
		if (pre_diff[i] != pre_diff[i - 1])
			res[i] = q1(i);
	
	for (int i = 1; i <= n; ++i)
	{
		if (res[i] != -1) continue;
		vector<int> u(26);
		vector<int> p;
		for (int j = i - 1; j >= 1; --j)
		{
			if (u[res[j]]) continue;
			u[res[j]] = 1;
			p.push_back(j);
		}
		int L = 0, R = p.size() - 1;
		while (L <= R)
		{
			int m = (L + R) / 2;
			if (q2(p[m], i) == m + 1)
			{
				res[i] = res[p[m]];
				R = m - 1;
			}
			else
				L = m + 1;
		}
	}

	cout << "! ";
	for (int i = 1; i <= n; ++i)
		cout << char(res[i] + 'a');
	cout << endl;
}

int main()
{
#if debug
	freopen("try.in", "r", stdin);
	//freopen("try.out", "w", stdout);
#endif
	int tests = 1;
	//tests = next<int>();
	for (int test = 1; test <= tests; ++test)
	{
		//write("Case #", test, ": ");
		solve();
	}
	return 0;
}