#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

template <class Iter>
auto run_length_encoding(Iter first, Iter last) {
  vector<pair<typename iterator_traits<Iter>::value_type, int>> res;
  if (first != last) {
    auto v = *first++;
    int cnt = 1;
    for (; first != last; first++) {
      if (*first == v) cnt++;
      else {
        res.emplace_back(v, cnt);
        v = *first;
        cnt = 1;
      }
    }
    res.emplace_back(v, cnt);
  }
  return res;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    ll x;
    cin >> n >> k >> x;
    x--;
    string s;
    cin >> s;
    auto rle = run_length_encoding(all(s));
    for(auto& [c, cnt] : rle) if (c == '*') {
      cnt *= k;
    }
    string ans;
    int sz = rle.size();
    rep(i, sz) {
      if (rle[i].first == 'a') {
        ans.insert(ans.end(), rle[i].second, 'a');
        continue;
      }
      ll tmp = 1;
      bool ok = true;
      for(int j = i + 2; j < sz; j += 2) {
        if (__builtin_mul_overflow(tmp, rle[j].second + 1, &tmp)) {
          ok = false;
          break;
        }
      }
      if (!ok) continue;
      ans.insert(ans.end(), x / tmp, 'b');
      x %= tmp;
    }
    cout << ans << '\n';
  }
}