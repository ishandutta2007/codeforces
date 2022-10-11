#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fast_allocator_memory 500'000'000

#ifdef fast_allocator_memory
int allocator_pos = 0;
char allocator_memory[(int)fast_allocator_memory];
inline void* operator new (size_t n) {
  char* res = allocator_memory + allocator_pos;
  allocator_pos += n;
  return (void*)res;
}
inline void operator delete (void*) noexcept { }
#endif

struct DSU {
  int n;
  vector<unordered_map<int, int>> fir, sec;
  vector<set<int>> elements;

  void resize(int n_) {
    n = n_;
    elements.assign(n, set<int>());
    for (int i = 0; i < n; i++) {
      elements[i].insert(i);
    }
    fir.assign(n, unordered_map<int, int>());
    sec.assign(n, unordered_map<int, int>());
  }

  int unite(int a, int b) {
    int res = 0;
    if (elements[a].size() >= elements[b].size()) {
      for (auto &el : elements[b]) {
        elements[a].insert(el);
        res += fir[a][el];
        res += sec[a][el];
      }
    } else {
      for (auto &el : elements[a]) {
        elements[b].insert(el);
        res += fir[b][el];
        res += sec[b][el];
      }
      elements[a].clear();
      elements[a].swap(elements[b]);
    }
    if (fir[a].size() >= fir[b].size()) {
      for (auto &[num, cnt] : fir[b]) {
        fir[a][num] += cnt;
      }
    } else {
      for (auto &[num, cnt] : fir[a]) {
        fir[b][num] += cnt;
      }
      fir[a].clear();
      fir[a].swap(fir[b]);
    }
    if (sec[a].size() >= sec[b].size()) {
      for (auto &[num, cnt] : sec[b]) {
        sec[a][num] += cnt;
      }
    } else {
      for (auto &[num, cnt] : sec[a]) {
        sec[b][num] += cnt;
      }
      sec[a].clear();
      sec[a].swap(sec[b]);
    }
    return res;
  }
};

int n, m, ans = 0;
vector<int> where;
DSU dsu;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  where.assign(n, 0);
  for (auto &el : where) {
    cin >> el;
    el--;
  }
  dsu.resize(m);
  for (int i = 1; i < n; i++) {
    if (where[i] != where[i - 1]) {
      ans++;
      dsu.fir[where[i]][where[i - 1]]++;
      dsu.sec[where[i - 1]][where[i]]++;
    }
  }
  cout << ans << '\n';
  while (--m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    ans -= dsu.unite(a, b);
    cout << ans << '\n';
  }
}