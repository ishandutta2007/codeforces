/*input
4
1
10
0
3
100 1 100
1 100 1
4
2 6 7 3
3 6 0 5
2
1000000000 1000000000
1000000000 1000000000
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
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif
// const int N =;

class TestX{
  public:
  int n;
  vector<pair<int,int> > a;
  void operator()(){
    cin >> n;
    a = vector<pair<int,int>>(n);
    for(auto &it:a) cin >> it.fi;
      for(auto &it:a) cin >> it.se;

      int mx = 0;
    for(auto &[x,y]:a) mx = max(mx,y);
    int ans = 0;
  for(auto &[x,y]:a) ans+=x+y;
    ans-=mx;
  cout << ans << endl;
  }  
};

int T;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while(T--){
      TestX test;
      test();
    }
}