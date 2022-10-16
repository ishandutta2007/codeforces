//#pragma GCC optimize "tree-vectorize"
//#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <array>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() const { T t; cin >> t; return t; } operator X() const { return operator()(); } template <typename T> operator T() const { return operator()<T>(); } string operator~() const { return *this; } char operator!() const { return *this; } } $;

constexpr int N = 100;
char a[N][N];

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  map<char, array<int, 2>> junc;
  int r = $, c = $, k = $;
  for (int i = 0; i < r; ++i)
  for (int j = 0; j < c; ++j) if ((a[i][j] = $) >= 'a') {
    junc[a[i][j]] = {i, j};
  }
  int i = $ - 1, j = $ - 1;
  vector<array<int, 2>> targ;
  for (auto c: ~$) {
    targ.push_back(junc[c]);
  }
  targ.push_back({$ - 1, $ - 1});
  for (const auto& n: targ) { auto sgn = [](int x) { return (x > 0) - (x < 0); }; int di = sgn(n[0] - i), dj = sgn(n[1] - j);
  while (i ^ j ^ n[0] ^ n[1]) {
    k -= a[i][j] >= 'a'?: a[i][j] - '0';
    if (k < 0) break;
    i += di, j += dj;
  }}
  cout << i + 1 << ' ' << j + 1;
}