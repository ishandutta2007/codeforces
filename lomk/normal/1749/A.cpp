/*input
2
2 2
1 2
2 1
3 1
2 2

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
    int n,m;
    vector<pair<int,int> > a;
    
    bool check(vector<pair<int,int>> b){
      bool row[9],col[9];
      memset(row,0,sizeof(row));
      memset(col,0,sizeof(col));
      for(auto [x,y]:b){
        if (row[x]||col[y]) return false;
        row[x] = col[y] = true;
      }
      return true;
    }
  void operator()(){
    cin >> n >> m;
    loop(i,1,m){
      int x,y; cin >> x >> y;
      a.push_back({x,y});
    }
    for(auto &it:a){
      auto ori = it;
      loop(i,1,n) loop(j,1,n) {
        it = {i,j};
        if (it == ori) continue;
        if (check(a)){
          cout << "YES" << endl;
          return;
        }
      }  
      it = ori;
    }
    cout << "NO" << endl;
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