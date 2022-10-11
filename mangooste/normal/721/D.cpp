#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k, x;
vector<ll> a;

void ans() {
  for (auto &el : a) {
    cout << el << ' ';
  }
  cout << '\n';
  exit(0);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> k >> x;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  vector<int> zero, less, more;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      zero.push_back(i);
    } else if (a[i] < 0) {
      less.push_back(i);
    } else {
      more.push_back(i);
    }
  }
  while (k != 0 && !zero.empty()) {
    if ((int)zero.size() == 1 && (int) less.size() % 2 == 0) {
      a[zero.back()] -= x;
      less.push_back(zero.back());
    } else {
      a[zero.back()] += x;
      more.push_back(zero.back());
    }
    zero.pop_back();
    k--;
  }
  if (k == 0) {
    ans();
  }
  set<pair<ll, int>> st;
  for (int i = 0; i < n; i++) {
    st.insert(make_pair(abs(a[i]), i));
  }
  if ((int)less.size() % 2 == 0) {
    int where_min = st.begin()->second;
    st.erase(st.begin());
    if (a[where_min] > 0) {
      while (k > 0 && a[where_min] >= 0) {
        a[where_min] -= x;
        k--;
      }
    } else {
      while (k > 0 && a[where_min] <= 0) {
        a[where_min] += x;
        k--;
      }
    }
    st.insert(make_pair(abs(a[where_min]), where_min));
  }
  while (k != 0) {
    int pos = st.begin()->second;
    st.erase(st.begin());
    a[pos] += (a[pos] > 0 ? x : -x);
    st.insert(make_pair(abs(a[pos]), pos));
    k--;
  }
  ans();
}