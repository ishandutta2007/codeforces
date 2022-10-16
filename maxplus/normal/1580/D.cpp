#include <bits/stdc++.h>
#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"

using namespace std;

constexpr int N = 4e3 + 1;
int a[N], m;
int64_t buf[N];
using DP = vector<int64_t>;

auto& maxi(auto& a, auto b) { return a = a < b? b: a; }

DP solve(int l, int r) {
  if (l == r) {
    return {0ll};
  }
  int mid = min_element(a + l, a + r) - a;
  auto L = solve(l, mid), R = solve(mid + 1, r);
  if (L.size() > R.size()) {
    swap(L, R);
  }
  int sz = min(int(L.size() + R.size()), m + 1);
  fill_n(buf, sz, 0);
  int64_t t = a[mid];
  for (int i = 0; i < L.size(); ++i)
  for (int j = 0; j < min((int)R.size(), m - i + 1); ++j) {
    maxi(buf[i + j], L[i] + R[j] - t * i * j * 2);
  }
  for (int i = 0; i < L.size(); ++i)
  for (int j = 0; j < min((int)R.size(), m - i); ++j) {
    maxi(buf[i + j + 1], L[i] + R[j] - t * ((i + 1) * (j + 1) * 2 - m - 1));
  }
  R.resize(sz);
  copy_n(buf, sz, R.begin());
  return R;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(0, n)[m];
}