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

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  auto check = [&](int i) {
    if (i < 0 || i + 2 >= n) return false;
    return s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c';
  };
  int now = 0;
  rep(i, n) now += check(i);
  while(q--) {
    int pos;
    char c;
    cin >> pos >> c;
    pos--;
    for(int i = pos - 2; i <= pos; i++) now -= check(i);
    s[pos] = c;
    for(int i = pos - 2; i <= pos; i++) now += check(i);
    cout << now << '\n';
  }
}