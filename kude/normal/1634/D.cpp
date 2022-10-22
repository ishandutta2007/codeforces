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

int ask(int i, int j, int k) {
  cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
  int res;
  cin >> res;
  return res;
}

void answer(int i, int j) {
  cout << "! " << i + 1 << ' ' << j + 1 << endl;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int r[4];
    r[0] = ask(   1, 2, 3);
    r[1] = ask(0,    2, 3);
    r[2] = ask(0, 1,    3);
    r[3] = ask(0, 1, 2   );
    int now = *max_element(r, r + 4);
    int p1 = -1, p2 = -1, dummy = -1;
    if (r[0] == now && r[1] == now) p1 = 2, p2 = 3, dummy = 0;
    else if (r[0] == now && r[2] == now) p1 = 1, p2 = 3, dummy = 0;
    else if (r[0] == now && r[3] == now) p1 = 1, p2 = 2, dummy = 0;
    else if (r[1] == now && r[2] == now) p1 = 0, p2 = 3, dummy = 1;
    else if (r[1] == now && r[3] == now) p1 = 0, p2 = 2, dummy = 1;
    else if (r[2] == now && r[3] == now) p1 = 0, p2 = 1, dummy = 2;
    else assert(false);
    for (int i = 4; i < n; i++) {
      int r1 = ask(p1, dummy, i);
      int r2 = ask(p2, dummy, i);
      if (max(r1, r2) > now) {
        if (r1 > r2) p2 = i;
        else p1 = i;
        now = max(r1, r2);
      }
    }
    answer(p1, p2);
  }
}