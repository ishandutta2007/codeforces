#line 1 "Contests/Codeforces_1534/F2/main.cpp"
using namespace std;
#line 2 "library/bits/stdc++.h"

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#line 3 "Contests/Codeforces_1534/F2/main.cpp"

// add your library with double quotation #include"" here.
// define your macros here.
#line 2 "library/ei1333/graph/graph-template.cpp"

template< typename T = int >
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator int() const { return to; }
};

template< typename T = int >
struct Graph {
  vector< vector< Edge< T > > > g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }
};

template< typename T = int >
using Edges = vector< Edge< T > >;
#line 2 "library/ei1333/graph/connected-components/strongly-connected-components.cpp"

/**
 * @brief Strongly-Connected-Components()
 * @docs docs/strongly-connected-components.md
 */
template< typename T = int >
struct StronglyConnectedComponents : Graph< T > {
public:
  using Graph< T >::Graph;
  using Graph< T >::g;
  vector< int > comp;
  Graph< T > dag;
  vector< vector< int > > group;

  void build() {
    rg = Graph< T >(g.size());
    for(int i = 0; i < g.size(); i++) {
      for(auto &e : g[i]) {
        rg.add_directed_edge(e.to, e.from, e.cost);
      }
    }
    comp.assign(g.size(), -1);
    used.assign(g.size(), 0);
    for(int i = 0; i < g.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;
    dag = Graph< T >(ptr);
    for(int i = 0; i < g.size(); i++) {
      for(auto &e : g[i]) {
        int x = comp[e.from], y = comp[e.to];
        if(x == y) continue;
        dag.add_directed_edge(x, y, e.cost);
      }
    }
    group.resize(ptr);
    for(int i = 0; i < g.size(); i++) {
      group[comp[i]].emplace_back(i);
    }
  }

  int operator[](int k) const {
    return comp[k];
  }

private:
  vector< int > order, used;
  Graph< T > rg;

  void dfs(int idx) {
    if(exchange(used[idx], true)) return;
    for(auto &to : g[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(auto &to : rg.g[idx]) rdfs(to, cnt);
  }
};
#line 7 "Contests/Codeforces_1534/F2/main.cpp"
using namespace std;
typedef string::const_iterator State;
#define eps 1e-8L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(int (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

#define int long long
#undef int
int visited[600000];
int checked[600000];
vector<int> gyaku[600000];
int cando[600000];
StronglyConnectedComponents<> scc;
void dfs(int now){
    for(auto x:scc.dag.g[now]){
        if(visited[x.to] == 0){
            visited[x.to] = 1;
            dfs(x.to);
        }
    }
}
void solve(){
    // write your solution here.
    int n,m;
    cin >> n >> m;
    vector<string> inputs;
    REP(i,n){
        string a;
        cin >> a;
        inputs.push_back(a);
    }
    scc = StronglyConnectedComponents<>(n*m);
    vector<int> A;
    REP(i,m){
        int a;
        cin >> a;
        A.push_back(a);
    }
    REP(q,m){
        int now = -2;
        REP(i,n){
            if(inputs[i][q] == '#'){
                if(now != -2){
                    scc.add_directed_edge(now * m + q,i * m + q);
                }
                if(now + 1 == i){
                    scc.add_directed_edge(i*m+q,now*m+q);
                }
                now = i;
            }
            if(q != 0 and inputs[i][q-1] == '#'){
                if(now != -2){
                    scc.add_directed_edge(now*m+q,i * m + q - 1);
                }
            }
            if(q != m-1 and inputs[i][q+1] == '#'){
                if(now != -2){
                    scc.add_directed_edge(now*m+q,i * m + q + 1);
                }
            }
        }
    }
    scc.build();
    int ans = 0;
    queue<int> targets;
    for(int i = n-1;i >= 0;--i){
        REP(q,m){
            if(inputs[i][q] != '#') continue;
            if(visited[scc[i*m+q]] == 1) continue;
            if(A[q] == 0) continue;
            A[q]--;
            if(A[q] == 0)
                targets.push(i*m+q);
        }
    }
    while(targets.empty() == false){
        int hoge = targets.front();
        targets.pop();
        if(visited[scc[hoge]] == 1) continue;
        checked[scc[hoge]] = 1;
        queue<int> nexts;
        nexts.push(scc[hoge]);
        visited[scc[hoge]] = 1;
        while(nexts.empty() == false){
            int now = nexts.front();
            nexts.pop();
            for(auto x:scc.dag.g[now]){
                if(visited[x.to] == 1){
                    if(checked[x.to] == 1){
                        checked[x.to] = 0;
                    }
                }
                if(visited[x.to] == 0){
                    visited[x.to] = 1;
                    nexts.push(x.to);
                }
            }
        }
    }
    REP(i,n*m){
        visited[i] = 0;
    }
    set<int> visiteds;
    REP(i,n){
        REP(q,m){
            if(inputs[i][q] != '#') continue;
            if(visiteds.count(scc[i*m+q]) == 1) continue;
            visiteds.insert(scc[i*m+q]);
            for(auto x: scc.dag.g[scc[i*m+q]]){
                gyaku[x.to].push_back(x.from);
            }
        }
    }
    vector<int> kouho(m+2,-1);
    REP(q,m){
        REP(i,n){
            if(inputs[i][q] == '#'){
                kouho[q] = scc[i*m+q];
                break;
            }
        }
    }
    int now_left = 0;
    REP(q,m){
        now_left = max(now_left,q);
        REP(i,n){
            if(checked[scc[i*m+q]] == 1){
                if(visited[scc[i*m+q]] == 0){
                    // cost!
                    queue<int> gogo;
                    gogo.push(scc[i*m+q]);
                    cando[gogo.front()] = 1;
                    while(gogo.empty() == false){
                        int now = gogo.front();
                        gogo.pop();
                        for(auto &x:gyaku[now]){
                            if(cando[x] == false){
                                cando[x] = true;
                                gogo.push(x);
                            }
                        }
                    }
                    while(kouho[now_left + 1] != -1){
                        if(cando[kouho[now_left+1]] == 0) break;
                        now_left++;
                    }
                    ans++;
                    {
                        // flow from it
                        visited[kouho[now_left]] = 1;
                        dfs(kouho[now_left]);
                    }
                }
                break;
            } 
        }
    }
    cout << ans << endl;
}
#undef int

// generated by oj-template v4.7.2 (https://github.com/online-judge-tools/template-generator)
int main() {
    // Fasterize input/output script
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(100);
    // scanf/printf user should delete this fasterize input/output script

    int t = 1;
    //cin >> t; // comment out if solving multi testcase
    for(int testCase = 1;testCase <= t;++testCase){
        solve();
    }
    return 0;
}