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

	ll_t t, n,a,b,k;
	cin >> t>>n>>a>>b>>k;

	if (k > n)
	{
		cout << 0;
		//system("pause");
		return 0;
	}
	if (k == n)
	{
		cout << min({ a, b, t });
		//system("pause");
		return 0;
	}

	ll_t tmp1 = (n / 2 + n % 2);
	ll_t tmp2 = (n / 2);

	ll_t w1 = max((k - tmp2), 0ll);
    ll_t ans1 = 9223372036854775807ll;
    if (w1 > 0) ans1 = tmp1*a/w1;

	ll_t w2 = max((k - tmp1), 0ll);
    ll_t ans2 = 9223372036854775807ll;
    if (w2 > 0) ans2 = tmp2*b/w2;

    //cout << ans2 << " " << tmp2 << " " << b << " " << w2 << endl;

	//cout << ans1 << " " << ans2 << " "<<(tmp1*a + tmp2*b) / k;
	cout << min(t, min({ ans1, ans2, (tmp1*a + tmp2*b) / k }));

//close:
	//system("pause");
	return 0;
}
/*
100 9 6 3 6
*/