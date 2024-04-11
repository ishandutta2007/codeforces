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

template<int element_size>
struct array_set {
  int state[element_size];  // -1 if not in set else index in elems
  int elems[element_size];
  int size = 0;
  array_set() { memset(state, -1, sizeof(int) * element_size); }
  void insert(int x) {
    if (state[x] == -1) {
      state[x] = size;
      elems[size] = x;
      size++;
    }
  }
  bool contains(int x) { return state[x] != -1; }
  int* begin() { return elems; }
  int* end() { return elems + size; }
  void clear() { while(size) state[elems[--size]] = -1; }
  void erase(int x) {  // not tested
    int idx = state[x];
    if (idx != -1) {
      state[x] = -1;
      size--;
      if (idx != size) {
        int y = elems[size];
        state[y] = idx;
        elems[idx] = y;
      }
    }
  }
};


array_set<10010> st;

void query(int l, int r) {
  cout << "? " << l + 1 << ' ' << r << endl;
  st.clear();
  int cnt = r - l;
  while(cnt--) {
    int x;
    cin >> x;
    x--;
    st.insert(x);
  }
}

void answer(int x) {
  cout << "! " << x + 1 << endl;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<char> used(n);
    int l = 0, r = n;
    while(r - l > 1) {
      int c = (l + r) / 2;
      query(l, c);
      for(int x: st) if (x >= c) {
        used[x] = true;
      }
      for(int i = l; i < c; i++) if (!st.contains(i)) {
        used[i] = true;
      }
      int cnt = 0;
      for(int i = l; i < c; i++) cnt += !used[i];
      if (cnt % 2) {
        r = c;
      } else {
        l = c;
      }
    }
    answer(l);
  }
}