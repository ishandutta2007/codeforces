/*input
3
3
1 2 3
3
1 1 1
4
2 1 4 3
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
    
    loop(i,0,n-1){
      a[i]-=(i+1);
    }
    int R = -1;
    int ans = 0;
    loop(i,0,n-1){
      R = max(R,i-1);
      while(R+1<n&&a[R+1]+i>=0) R++;
      ans+=R-i+1;
    }
    cout << ans << endl;
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