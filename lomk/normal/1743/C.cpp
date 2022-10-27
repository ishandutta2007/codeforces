/*input
4
5
01110
10 5 8 9 6
6
011011
20 10 9 30 20 19
4
0000
100 100 100 100
4
0111
5 4 5 1

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

const int INF = numeric_limits<int>::max()/2; 

class TestX {
public:
  int n;
  string s;
  vector<int> a;
  
  void operator()() {
    cin >> n;
    cin >> s;
    a = vector<int>(n,0);
    for(auto &it:a) cin >> it;
    
    vector<int> buf;
  
    auto clearBuf = [&](){
      if (buf.empty()) return;
      
      pair<int,int> mn = {INF,-1};
      for(auto it:buf) mn = min(mn,{a[it],it});
      
      int pre = buf[0]-1;
      if (pre>=0){
        if (a[pre]>a[mn.se]){
          swap(s[pre],s[mn.se]);
        }
      }  
      
      buf.clear();
    };
    
    loop(i,0,n-1){
      if (s[i]=='1'){
        buf.push_back(i);
      }
      else{
        clearBuf();
      }
    }
    
    clearBuf();
    
    int ans = 0;
    loop(i,0,n-1) if (s[i]=='1') ans+=a[i];
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