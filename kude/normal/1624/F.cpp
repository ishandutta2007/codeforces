#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int ask(int x) {
  cout << "+ " << x << endl;
  int res;
  cin >> res;
  return res;
}

void answer(int x) {
  cout << "! " << x << endl;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int q = 0;
  int l = 1, r = n;  // [l, r)
  while(r - l > 1) {
    int c = (l + r) / 2;
    // [l, c), [c, r)
    int add = n - c;
    int nq = ask(add);
    if (q == nq) {
      // was in [l, c) -> [l+add, n)
      l = l + add;
      r = n;
    } else {
      // [c, r) -> [0, r-c)
      r = r - c;
      l = 0;
    }
    q = nq;
  }
  answer(n * q + l);
}