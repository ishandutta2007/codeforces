#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

constexpr int SQ = 320;

template<class T, int element_size>
struct array_map {
  int state[element_size];  // -1 if not in set else index in elems
  pair<int, T> elems[element_size];
  int size = 0;
  array_map() { memset(state, -1, sizeof(int) * element_size); }
  bool contains(int x) { return state[x] != -1; }
  pair<int, T>* begin() { return elems; }
  pair<int, T>* end() { return elems + size; }
  void clear() { while(size) state[elems[--size].first] = -1; }
  void erase(int x) {  // not tested
    int idx = state[x];
    if (idx != -1) {
      state[x] = -1;
      size--;
      if (idx != size) {
        int y = elems[size].first;
        state[y] = idx;
        elems[idx] = move(elems[size]);
      }
    }
  }
  T& operator[](int x) {
    if (state[x] == -1) {
      state[x] = size;
      elems[size].first = x;
      elems[size].second = T();
      size++;
    }
    return elems[state[x]].second;
  }
};

array_map<int, 324 * 100010> mp;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VI a(n);
  rep(i, n) cin >> a[i];
  int ans = 0;
  for(int l = -SQ; l <= SQ; l++) {
    const int b = max(0, l * (n - 1));
    mp.clear();
    rep(i, n) mp[b + a[i] - l * i]++;
    for(auto& [k, v]: mp) chmax(ans, v);
  }
  rep(i, n) {
    int r = min(n, i + SQ);
    mp.clear();
    constexpr int b = 300010;
    for(int j = i + 1; j < r; j++) {
      int d = a[j] - a[i];
      int l = j - i;
      if (d % l == 0) {
        mp[b + d / l]++;
      }
    }
    for(auto& [k, v]: mp) chmax(ans, v + 1);
  }

  cout << n - ans << '\n';
}