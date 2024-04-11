#// #line 1 "Contests/Codeforces_1515/E/main.cpp"
using namespace std;
#// #line 2 "library/bits/stdc++.h"

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
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
#// #line 3 "Contests/Codeforces_1515/E/main.cpp"

// add your library with double quotation #include"" here.
#// #line 1 "library/atcoder/dsu.hpp"



#// #line 5 "library/atcoder/dsu.hpp"
#include <cassert>
#// #line 7 "library/atcoder/dsu.hpp"

namespace atcoder {

    // Implement (union by size) + (path compression)
    // Reference:
    // Zvi Galil and Giuseppe F. Italiano,
    // Data structures and algorithms for disjoint set union problems
    struct dsu {
    public:
        dsu() : _n(0) {}
        explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

        int merge(int a, int b) {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            int x = leader(a), y = leader(b);
            if (x == y) return x;
            if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
            parent_or_size[x] += parent_or_size[y];
            parent_or_size[y] = x;
            return x;
        }

        bool same(int a, int b) {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            return leader(a) == leader(b);
        }

        int leader(int a) {
            assert(0 <= a && a < _n);
            if (parent_or_size[a] < 0) return a;
            return parent_or_size[a] = leader(parent_or_size[a]);
        }

        int size(int a) {
            assert(0 <= a && a < _n);
            return -parent_or_size[leader(a)];
        }

        std::vector<std::vector<int>> groups() {
            std::vector<int> leader_buf(_n), group_size(_n);
            for (int i = 0; i < _n; i++) {
                leader_buf[i] = leader(i);
                group_size[leader_buf[i]]++;
            }
            std::vector<std::vector<int>> result(_n);
            for (int i = 0; i < _n; i++) {
                result[i].reserve(group_size[i]);
            }
            for (int i = 0; i < _n; i++) {
                result[leader_buf[i]].push_back(i);
            }
            result.erase(
                std::remove_if(result.begin(), result.end(),
                    [&](const std::vector<int>& v) { return v.empty(); }),
                result.end());
            return result;
        }

    private:
        int _n;
        // root node: -1 * component size
        // otherwise: parent
        std::vector<int> parent_or_size;
    };

}  // namespace atcoder


#// #line 6 "Contests/Codeforces_1515/E/main.cpp"
// define your macros here.
// #define REP(a,b) for(long long a = 0;a < b;++a)

using namespace std;
typedef string::const_iterator State;
#define eps 1e-8L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
using namespace atcoder;
#define int long long
pair<int, int> ut[500000];
priority_queue<tuple<int, int,int>> nexts[500000];
pair<int, int> uf(int now) {
    if (ut[now].first == now) return ut[now];
    pair<int, int> hoge = uf(ut[now].first);
    ut[now].first = hoge.first;
    return hoge;
}
void um(int a, int b) {
    a = uf(a).first;
    b = uf(b).first;
    if (a == b) return;
    if (nexts[a].size() > nexts[b].size()) swap(a, b);
    while (nexts[a].empty() == false) {
        nexts[b].push(nexts[a].top());
        nexts[a].pop();
    }
    ut[a].first = b;
    ut[b].second += ut[a].second;
    ut[a].second = 0;
    return;
}
void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    int sums = 0;
    REP(i, n) {
        int a;
        cin >> a;
        sums += a;
        ut[i] = mp(i, a);
    }
    if (sums < (n - 1) * x) {
        cout << "NO" << endl;
        return;
    }
    dsu hoge(n);
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (hoge.same(a, b) == 0) {
            hoge.merge(a, b);
            nexts[a].push(make_tuple(ut[b].second, b, i + 1));
            nexts[b].push(make_tuple(ut[a].second, a, i + 1));
        }
    }
    cout << "YES" << endl;
    queue<int> next_go;
    REP(i, n) {
        next_go.push(i);
    }
    while (next_go.empty() == false) {
        int now = next_go.front();
        next_go.pop();
        int moved = 0;
        while (nexts[now].empty() == false) {
            tuple<int, int, int> Going = nexts[now].top();
            nexts[now].pop();
            if (uf(get<1>(Going)).first == uf(now).first) continue;
            if (uf(get<1>(Going)).second != get<0>(Going)) {
                get<0>(Going) = uf(get<1>(Going)).second;
                nexts[now].push(Going);
                continue;
            }
            if (get<0>(Going) + uf(now).second < x) {
                nexts[now].push(Going);
                break;
            }
            cout << get<2>(Going) << endl;
            um(get<1>(Going), now);
            now = uf(now).first;
            ut[now].second -= x;
            moved = 1;
        }
        if (moved == 1) next_go.push(now);
    }
}
#undef int

// generated by oj-template v4.7.2 (https://github.com/on// #line-judge-tools/template-generator)
int main() {
    // Fasterize input/output script
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(100);
    // scanf/printf user should delete this fasterize input/output script

    int t = 1;
    //cin >> t; // comment out if solving multi testcase
    for (int testCase = 1; testCase <= t; ++testCase) {
        solve();
    }
    return 0;
}