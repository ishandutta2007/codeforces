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

bool ask(const VI& xs) {
  int sz = xs.size();
  cout << "? " << sz;
  rep(i, sz) cout << ' ' << xs[i];
  cout << endl;
  string res;
  cin >> res;
  return res[0] == 'Y';
}
bool ask(const VI& xs1, const VI& xs2) {
  static VI xs;
  xs.clear();
  xs.insert(xs.end(), all(xs1));
  xs.insert(xs.end(), all(xs2));
  return ask(xs);
}

bool answer(int x) {
  cout << "! " << x << endl;
  string res;
  cin >> res;
  return res[1] == ')';
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VI rest;
  for(int i = 1; i <= n; i++) rest.emplace_back(i);
  VI a, b, c, d;
  while(rest.size() >= 4) {
    a.clear();
    b.clear();
    c.clear();
    d.clear();
    int sz = rest.size();
    int c2 = sz / 2;
    int c1 = c2 / 2;
    int c3 = (c2 + sz) / 2;
    for(int i = 0; i < c1; i++) a.emplace_back(rest[i]);
    for(int i = c1; i < c2; i++) b.emplace_back(rest[i]);
    for(int i = c2; i < c3; i++) c.emplace_back(rest[i]);
    for(int i = c3; i < sz; i++) d.emplace_back(rest[i]);
    // cout << "aa" << endl;
    bool r0 = ask(a, b);
    bool r1 = ask(a, c);
    if (!r0) {
      if (!r1) a.clear();
      else b.clear();
    } else {
      if (!r1) c.clear();
      else d.clear();
    }
    rest.clear();
    rest.insert(rest.end(), all(a));
    rest.insert(rest.end(), all(b));
    rest.insert(rest.end(), all(c));
    rest.insert(rest.end(), all(d));
  }
  if (rest.size() == 3) {
    VI d{rest[0], rest[1]};
    bool r0 = ask(d);
    if (r0) {
      bool r1 = ask(d);
      if (r1) {
        if (!answer(d[0])) answer(d[1]);
        return 0;
      }
    }
    // last answer = false
    if (answer(rest[2])) return 0;
    if (ask({d[0]})) answer(d[0]);
    else answer(d[1]);
  } else {
    if (!answer(rest[0])) answer(rest[1]);
  }
}