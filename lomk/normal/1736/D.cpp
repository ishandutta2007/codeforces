/*input
4
2
1010
3
100010
2
1111
2
1110


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
const int N = 2e5+5;

struct Hashx {
  static const int B1 = 157, B2 = 161, M1 = 1500450271, M2 = 1007050321;
  static vector<int> p1, p2;
  vector<int> h1, h2;

  static void prepP() {
    p1[0] = 1; p2[0] = 1;
    for (int i = 1; i < N; i++) {
      p1[i] = 1LL * p1[i - 1] * B1 % M1;
      p2[i] = 1LL * p2[i - 1] * B2 % M2;
    }
  }

  void prepHash(string s) {
    //careful when use with integers, s[i] maybe 0 or negative
    h1 = h2 = vector<int>(s.size() + 1, 0);
    for (int i = 1; i <= s.size(); i++) {
      h1[i] = (1LL * h1[i - 1] * B1 + s[i - 1]) % M1;
      h2[i] = (1LL * h2[i - 1] * B2 + s[i - 1]) % M2;
    }
  }

  pair<int, int> get(int L, int R) {
    L++; R++;
    int len = R - L + 1;
    int ans1 = (h1[R] - 1LL * h1[L - 1] * p1[len]) % M1;
    int ans2 = (h2[R] - 1LL * h2[L - 1] * p2[len]) % M2;
    if (ans1 < 0) ans1 += M1; if (ans2 < 0) ans2 += M2;
    return {ans1, ans2};
  }
} h;
vector<int> Hashx::p1 = vector<int>(N, 0);
vector<int> Hashx::p2 = vector<int>(N, 0);

class TestX {
public:
  int n;
  string s;
  
  void operator()() {
    cin >> n;
    cin >> s;
    
    int cnt0=0,cnt1=0;
    for(auto it:s) if (it=='0') cnt0++; else cnt1++;
      
    if (cnt0%2!=0||cnt1%2!=0){
      cout << -1 << endl;
      return;
    }
    
    bool pushZer = true;
    vector<int> vec;
    for(int i=0; i<2*n; i+=2){
      if (s[i]==s[i+1]) continue;
      loop(j,i,i+1) if (pushZer == (s[j]=='0')) vec.push_back(j);
      pushZer = 1 - pushZer;
    }
    cout << vec.size() << sp;
    for(auto it:vec) cout << it+1 << sp;
      cout << endl;
    for(int i=0; i<2*n; i+=2) cout << i+1 << sp;
      cout << endl;
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Hashx::prepP();
  int T;
  cin >> T;
  while (T--) {
    TestX test;
    test();
  }
}