#include <iostream>
#include <array>
#include <map>
#include <set>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} It begin() const { return first; } It end() const { return last; } };
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 1e3;
using Edges = set<pair<int, int>>;
Edges edges;

array<Edges, 2> split() {
  map<int, set<int>> to;
  for (auto [u, v]: edges) {
    to[u].insert(v);
    to[v].insert(u);
  }
  Edges q1, q2 = edges;
  for (auto [V, Too]: to) if (Too.size() == 1) {
    auto v = V;
    auto too = Too;
    while (too.size() == 1) {
      auto u = *too.begin();
      q1.emplace(v, u);
      q2.erase({v, u});
      q2.erase({u, v});
      to[u].erase(v);
      to[v].clear();
      too = to[v = u];
      if (q1.size() >= edges.size() / 2) {
        return {q1, q2};
      }
    }
  }
  return {q1, q2};
}

int ask(auto edges) {
  set<int> q;
  for (auto [u, v]: edges) {
    q.insert(u);
    q.insert(v);
//    cerr << '|' << ++u << '>' << ++v << ' ';
  }
//  cerr << '\n';
  cout << "? " << q.size();
  for (auto i: q) {
    cout << ' ' << ++i;
  }
  cout << '\n';
  return $;
}

int main() {
  int n = $;
  edges.clear();
  for (int i = 1; i < n; ++i) {
    edges.emplace($ - 1, $ - 1);
  }
  int g = ask(edges);
  while (edges.size() > 1) {
    auto [e1, e2] = split();
    if (g == ask(e2)) {
      edges = e2;
    } else {
      edges = e1;
    }
  }
  auto [u, v] = *edges.begin();
  print('!', ++u, ++v);
}