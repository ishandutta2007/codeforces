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
  int tt;
  cin >> tt;
  while(tt--) {
    string s, t;
    int cnt[26] = {};
    cin >> s >> t;
    for(char c: s) {
      cnt[c - 'a']++;
    }
    string ans;
    ans.insert(ans.end(), cnt[0], 'a');
    if (cnt[0] && cnt[1] && cnt[2] && t == "abc") {
      ans.insert(ans.end(), cnt[2], 'c');
      ans.insert(ans.end(), cnt[1], 'b');
    } else {
      ans.insert(ans.end(), cnt[1], 'b');
      ans.insert(ans.end(), cnt[2], 'c');
    }
    for(int i = 3; i < 26; i++) {
      ans.insert(ans.end(), cnt[i], char('a' + i));
    }
    cout << ans << '\n';
  }
}