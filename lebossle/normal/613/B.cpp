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

lli n, A, cf, cm, m;

lli findBest(vector<lli> a) {
  sort(a.begin(), a.end());
  vector<lli> orig(a);
  a.push_back(A);
  lli r=n;
  lli cost=0;
  while (r > 0 && cost+A-a[r-1] <= m) {
    r--;
    cost += A-a[r];
    a[r] = A;
  }
  lli imin=0;
  lli best = a[imin]*cm + (n-r)*cf;
  if (r == 0)
    return best;
  while (true) {
    if (a[imin+1] > a[imin]) {
      lli diff = min((m-cost)/(imin+1), a[imin+1]-a[imin]);
      if (diff > 0) {
        cost += diff*(imin+1);
        a[imin] += diff;
        best = max(best, a[imin]*cm + (n-r)*cf);
      } else if (r < n) {
        a[r] = max(a[r-1], orig[r]);
        cost -= A-a[r];
        r++;
      } else {
        break;
      }
    } else {
      imin++;
    }
  }
  return best;
}

vector<pair<lli, lli>> execBest(vector<lli> base, lli goal) {
  vector<pair<lli, lli>> a(n);
  for (lli i=0; i<n; ++i)
    a[i] = {base[i], i};
  sort(a.begin(), a.end());
  vector<lli> orig(n);
  for (lli i=0; i<n; ++i)
    orig[i] = a[i].first;
  a.push_back({A, n});
  lli r=n;
  lli cost=0;
  while (r > 0 && cost+A-a[r-1].first <= m) {
    r--;
    cost += A-a[r].first;
    a[r].first = A;
  }
  lli imin=0;
  if (a[imin].first*cm + (n-r)*cf == goal)
    return a;
  while (true) {
    if (a[imin+1].first > a[imin].first) {
      lli diff = min((m-cost)/(imin+1), a[imin+1].first-a[imin].first);
      if (diff > 0) {
        cost += diff*(imin+1);
        a[imin].first += diff;
        if (a[imin].first*cm + (n-r)*cf == goal) {
          for (lli i=imin-1; i>=0; --i)
            a[i].first = a[imin].first;
          return a;
        }
      } else if (r < n) {
        a[r].first = max(a[r-1].first, orig[r]);
        cost -= A-a[r].first;
        r++;
      }
    } else {
      imin++;
    }
  }
}

int main() {
  cin >> n >> A >> cf >> cm >> m;
  vector<lli> a(n);
  for (lli& i : a)
    cin >> i;
  lli best = findBest(a);
  auto v = execBest(a, best);
  sort(v.begin(), v.end(), [](pair<lli, lli> a, pair<lli, lli> b) {
    return a.second < b.second;
  });
  LOG(v);
  cout << best << endl;
  for (auto p : v)
    if (p.second != n)
      cout << p.first << ' ';
  cout << endl;
}