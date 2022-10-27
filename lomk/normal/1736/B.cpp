/*input
4
1
343
2
4 2
3
4 2 4
4
1 1 1 1
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() { cout << endl; }
template <typename T, typename... Ts>
void print(const T &value, const Ts &...values) {
  cout << value << ' ', print(values...);
}
#endif
// const int N =;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  a %= b;
  return gcd(b, a);
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

class TestX {
public:
  void operator()() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
      cin >> it;
    if (n == 1) {
      cout << "YES" << endl;
      return;
    }

    vector<int> b = {a[0],a[0]};
    loop(i,1,n-1){
      int t = lcm(b.back(),a[i]);
      b[b.size()-1] = t;
      b.push_back(a[i]);
    }
    loop(i,0,n-1){
      if (gcd(b[i],b[i+1])!=a[i]){
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    TestX test;
    test();
  }
}