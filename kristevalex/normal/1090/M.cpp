#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <string>
#include <string.h>
#include <numeric>
#include <set>
#include <functional>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <cmath>

using namespace std;

#pragma region DEFINES

#define FAST std::ios_base::sync_with_stdio(false); \
			 std::cin.tie(nullptr);                 \
	         std::cout.tie(nullptr)

#define CINV for(auto &x : v) \
				std::cin >> x

#define COUTV(v) for(auto &x : v) \
				std::cout << x << ' '

#define CINM(m) for(auto &x : m) \
				for(auto &i : x) \
					std::cin >> i

#define COUTM(m) for(auto &x : m)         \
				{                         \
					for(auto &i : x)      \
						std::cout << i; \
					std::cout << endl;         \
				}

#pragma endregion

#pragma region TYPEDEFS

using s_t = short;

using u_t = unsigned;
using uc_t = unsigned char;
using ul_t = unsigned long;
using us_t = unsigned short;
using ull_t = unsigned long long;

using l_t = long;
using ll_t = long long;
using ld_t = long double;

template<typename T>
using ve = std::vector<T>;

template<typename T>
using mat = std::vector<std::vector<T>>;

using mi_t = std::vector<std::vector<int>>;
using ms_t = std::vector<std::vector<s_t>>;
using mb_t = std::vector<std::vector<bool>>;
using mc_t = std::vector<std::vector<char>>;
using mus_t = std::vector<std::vector<us_t>>;

#pragma endregion

signed main()
{
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
	FAST;

	ll_t n, k;
	cin >> n >> k;

	ll_t cnt{};
	ll_t last{};
	ll_t mx{};
	for (ll_t i{}; i < n; ++i)
	{
		if (i == 0)
		{
			cnt = 1;
			cin >> last;
			continue;
		}

		ll_t cur;
		cin >> cur;
		if (cur == last)
		{
			mx = max(cnt, mx);
			cnt = 1;
		}
		else
		{
			cnt++;
			last = cur;
		}
	}

	mx = max(cnt, mx);

	cout << mx;
close:
	///system("pause");
	return 0;
}