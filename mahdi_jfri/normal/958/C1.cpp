#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define int long long
//#define long long int
using namespace std;
const int maxn = 100100, mod = 1e9 + 7, maxa = 100100, maxb = 20, base = 737, base2 = 3079, mod2 = 1e7 + 19;
const long long inf = 2e18 + 13;
long long max(long long x, long long y){return (x > y ? x : y);}
long long min(long long x, long long y){return (x < y ? x : y);}

long long a[maxn];
long long ps[maxn];
long long cs[maxn];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){cin >> a[i];}
    long long tmp = 0;
    for(int i = 0; i < n; i++)
    {
        ps[i] = tmp;
        tmp += a[i];
    }
    for(int i = n - 1; i >= 0; i--)
    {
        cs[i] = cs[i + 1] + a[i];
    }
    long long ans = 0;
    for(int i = n - 1; i > 0; i--)
    {
        ans = max(ans, (ps[i] % k) + (cs[i] % k));
    }
    cout << ans << endl;
    return 0;
}