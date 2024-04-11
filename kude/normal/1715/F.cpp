#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

double ask(vector<pair<double, double>> qs) {
  int k = qs.size();
  cout << "? " << k << '\n';
  for(auto [x, y]: qs) cout << x << ' ' << y << '\n';
  cout << flush;
  double r;
  cin >> r;
  return r;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  std::default_random_engine gen(std::chrono::system_clock::now().time_since_epoch().count());
  using dist_type = std::uniform_real_distribution<>;
  using ptype = dist_type::param_type;
  dist_type dist(0, 1);
  int n, m;
  cin >> n >> m;
  double tx = -1, ty = -1;
  double rx = dist(gen), ry = dist(gen);
  rep(_, 2) {
    vector<pair<double, double>> qs;
    for(int i = 0; i < n; i++) {
      double x = i + rx;
      double nx = x + 1e-13 * (i + 1);
      qs.emplace_back(x, i ? 1e-15 : 0.0);
      qs.emplace_back(x, m);
      qs.emplace_back(nx, m);
      qs.emplace_back(nx, i < n - 1 ? 1e-15 : 0.0);
    }
    if (_) for(auto& [x, y]: qs) swap(x, y);
    tx = rx + round(ask(qs) * 1e13) - 1;
    swap(n, m);
    swap(tx, ty);
    swap(rx, ry);
  }
  vector<pair<double, double>> q1(4);
  q1[0] = {0.0, 0.0};
  q1[1] = {tx, 0.0};
  q1[2] = {tx, ty};
  q1[3] = {0.0, ty};
  vector<pair<double, double>> q2(4);
  q2[0] = {n, 0};
  q2[1] = {tx, 0};
  q2[2] = {tx, ty};
  q2[3] = {n, ty};
  double s1 = ask(q1);
  double s2 = ask(q2);
  double dy = s1 + s2;
  ty -= dy;
  tx -= s1 / dy;
  cout << "! " << tx << ' ' << ty << endl;
}