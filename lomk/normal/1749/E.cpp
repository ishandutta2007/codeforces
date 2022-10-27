/*input
4
2 4
.#..
..#.
3 3
#.#
...
.#.
5 5
.....
.....
.....
.....
.....
4 3
#..
.#.
#.#
...

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
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 1, 1, -1};
const int dy8[] = {1, 1, -1, -1};

class TestX {
public:
  // mark all cells next to
  int n, m;
  vector<string> a;
  vector<vector<bool>> block;
  vector<vector<int>> cost;
  vector<vector<pair<int, int>>> par;

  void blockCells() {
    block.assign(n, vector<bool>(m, 0));

    auto markAdj4 = [&](pair<int, int> cell) {
      loop(k, 0, 3) {
        int ax = cell.fi + dx4[k];
        int ay = cell.se + dy4[k];
        if (0 <= ax && ax < n && 0 <= ay && ay < m) {
          block[ax][ay] = true;
        }
      }
    };

    loop(i, 0, n - 1) {
      loop(j, 0, m - 1) {
        if (a[i][j] == '#') {
          markAdj4({i, j});
        }
      }
    }
  }

  void findShortestPath() {
    deque<pair<int, int>> dq;
    cost.assign(n, vector<int>(m, INF));
    par.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    loop(i, 0, n-1) {
      if (block[i][0])
        continue;
      cost[i][0] = (a[i][0]=='#'?0:1);
      dq.push_front({i, 0});
    }

    while (!dq.empty()) {
      auto [x,y] = dq.front();
      dq.pop_front();
      loop(i, 0, 3) {
        int ax = x + dx8[i];
        int ay = y + dy8[i];

        if (0 <= ax && ax < n && 0 <= ay && ay < m && !block[ax][ay]) {
          int c = (a[ax][ay] == '#') ? 0 : 1;
          if (cost[ax][ay] > cost[x][y] + c) {
            cost[ax][ay] = cost[x][y] + c;
            par[ax][ay] = {x,y};
            if (c == 0)
              dq.push_front({ax, ay});
            else
              dq.push_back({ax, ay});
          }
        }
      }
    }
  }
  
  vector<pair<int,int> >  tracePath(){
    int mn = INF;
    pair<int,int> root;
    loop(i,0,n-1){
      if (cost[i][m-1]<mn){
        mn = cost[i][m-1];
        root = {i,m-1};
      }
    }
    
    if (mn==INF) return {};
    vector<pair<int,int> > ret;
    while(true){
      if (root.fi == -1) break;
      ret.push_back(root);
      root = par[root.fi][root.se];
    }
    return ret;
  }
  
  void markPath(vector<pair<int,int> > &inp){
    for(auto [x,y]:inp) a[x][y] = '#';  
  }
  
  void operator()() {
    cin >> n >> m;

    a = vector<string>(n);
    for (auto &it : a)
      cin >> it;
    blockCells();
    findShortestPath();
    auto rec = tracePath();
    if (rec.size()==0){
      cout << "NO" << endl;
      return;
    }
    markPath(rec);
    cout << "YES" << endl;
    for(auto it:a) cout << it << endl;
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  loop(t, 1, T) {
    TestX test;
    test();
  }
}