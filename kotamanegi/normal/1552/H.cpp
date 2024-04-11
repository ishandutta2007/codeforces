#line 1 "Contests/Codeforces_1552/H/main.cpp"
using namespace std;
#line 2 "library/bits/stdc++.h"

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
#line 3 "Contests/Codeforces_1552/H/main.cpp"

// add your library with double quotation #include"" here.
//#include "atcoder/all"
// using namespace atcoder;

// add your library with double quotation #include"" here.
// define your macros here.
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
#define REP(a, b) for (long long(a) = 0; (a) < (b); ++(a))
#define ALL(x) (x).begin(), (x).end()

#define int long long
int interact(vector<pair<int, int>> inputs) {
  int debug = 0;
  if (debug == 0) {
    cout << "? " << inputs.size() << endl;
    REP(i, inputs.size()) {
      if (i != 0)
        cout << " ";
      cout << inputs[i].first << " " << inputs[i].second;
    }
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
  } else {
    return 0;
  }
}
int calcArea() {
  vector<pair<int, int>> inputs;
  for (int i = 1; i <= 200; ++i) {
    for (int q = 1; q <= 200; ++q) {
      inputs.push_back({i, q});
    }
  }
  return interact(inputs);
}
map<int, vector<pair<int, int>>> kouho_creater(int x_mod, int y_mod,
                                               vector<pair<int, int>> kouhos) {
  map<int, vector<pair<int, int>>> ans;
  for (int i = 0; i < kouhos.size(); ++i) {
    vector<int> cnters;
    REP(t, 2) {
      vector<int> left_can, right_can;
      left_can.push_back(kouhos[i].first / x_mod);
      left_can.push_back((x_mod - 1 + kouhos[i].first) / x_mod);

      right_can.push_back(kouhos[i].second / y_mod);
      right_can.push_back((y_mod - 1 + kouhos[i].second) / y_mod);

      REP(q, left_can.size()) {
        REP(t, right_can.size()) {
          cnters.push_back(left_can[q] * right_can[t]);
        }
      }

      swap(kouhos[i].first, kouhos[i].second);
    }
    for (auto x : cnters) {
      if (ans[x].size() == 0 or ans[x].back() != kouhos[i])
        ans[x].push_back(kouhos[i]);
    }
  }
  return ans;
}
void solve() {
  vector<pair<int, int>> kouhos[50000];
  for (int i = 1; i <= 200; ++i) {
    for (int q = i; q <= 200; ++q) {
      kouhos[(i + 1) * (q + 1)].push_back({i + 1, q + 1});
    }
  }
  int cnter = calcArea();
  vector<pair<int, int>> line_kouho = kouhos[cnter];
  int interactLimit = 3;
  while (line_kouho.size() != 1 and interactLimit > 0) {
    int maximum_separator = 1e9;
    pair<int, int> pointers;
    for (int x_mod = 1; x_mod <= 200; ++x_mod) {
      for (int y_mod = 1; y_mod <= 200; ++y_mod) {
        auto x = kouho_creater(x_mod, y_mod, line_kouho);
        int now_max = 0;
        for (auto y : x) {
          set<int> gogo;
          for (auto p : y.second) {
            gogo.insert(p.first + p.second);
          }
          now_max = max(now_max, (int)gogo.size());
        }
        if (maximum_separator > now_max) {
          maximum_separator = now_max;
          pointers = {x_mod, y_mod};
        }
      }
    }
    auto x = kouho_creater(pointers.first, pointers.second, line_kouho);
    int response = 0;
    {
      vector<pair<int, int>> hoo;
      for (int q = 1; q <= 200; ++q) {
        for (int j = 1; j <= 200; ++j) {
          if (q % pointers.first == 0 and j % pointers.second == 0) {
            hoo.push_back({q, j});
          }
        }
      }
      response = interact(hoo);
    }
    interactLimit--;
    line_kouho = x[response];
  }
  cout << "! " << (line_kouho[0].first + line_kouho[0].second - 2) * 2 << endl;
}
#undef int

// generated by oj-template v4.7.2
// (https://github.com/online-judge-tools/template-generator)
int main() {
  // Fasterize input/output script
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(100);
  // scanf/printf user should delete this fasterize input/output script

  int t = 1;
  // cin >> t; // comment out if solving multi testcase
  for (int testCase = 1; testCase <= t; ++testCase) {
    solve();
  }
  return 0;
}