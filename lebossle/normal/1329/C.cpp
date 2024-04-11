#include <bits/stdc++.h>
using namespace std;

// This code uses the bossle/cp library
// Available at https://github.com/bossle/cp

// #pragma STDC FENV_ACCESS OFF
// #pragma STDC FP_CONTRACT ON
// #pragma STDC CX_LIMITED_RANGE ON
// #pragma GCC optimize "O3"

namespace cp_base {

auto init = (
  ios::sync_with_stdio(false),
  cin.tie(nullptr)
);

}  // namespace cp_base

       

#define LOG(x) 

typedef long long int lli;

int get(const vector<lli>& a, int i) {
  if (a[i] == 0)
    return i/2;
  if (a[2*i] > a[2*i+1])
    return get(a, 2*i);
  else
    return get(a, 2*i+1);
}

lli pop(vector<lli>& a, int i) {
  lli ans = a[i];
  if (a[i] == 0)
    return 0;
  if (a[2*i] > a[2*i+1])
    a[i] = pop(a, 2*i);
  else
    a[i] = pop(a, 2*i+1);
  return ans;
}

void solve() {
  int h, g;
  cin >> h >> g;
  vector<lli> a((2<<h)+2, 0);
  for (int i=1; i<(1<<h); ++i)
    cin >> a[i];
  vector<int> ans((1<<h) - (1<<g));
  int i=1;
  for (int& out : ans) {
    while (get(a, i) < (1<<g)) {
      LOG(get(a, i));
      LOG(i);
      i++;
    }
    pop(a, i);
    out = i;
    LOG(a);
  }
  lli acum=0;
  for (lli i : a)
    acum += i;
  cout << acum << '\n';
  for (int i : ans)
    cout << i << ' ';
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta) {
    solve();
  }
}