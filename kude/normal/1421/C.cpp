#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<P> ans;
    ans.emplace_back(1, n-1);
    ans.emplace_back(0, n);
    ans.emplace_back(0, 2);
    cout << 3 << endl;
    rep(i, 3) cout << "LR"[ans[i].first] << ' ' << ans[i].second << '\n';
}