#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VI a(2 * n);
        rep(i, 2 * n) cin >> a[i];
        sort(rall(a));
        bool ok = false;
        for(int i = 1; i < 2 * n; ++i) {
            int x_init = a[0] + a[i];
            int x = x_init;
            multiset<int> s(all(a));
            vector<pair<int, int>> ans;
            while(!s.empty()) {
                int ai = *s.rbegin();
                s.erase(s.find(ai));
                int aj = x - ai;
                auto it = s.find(aj);
                if (it != s.end()) {
                    s.erase(it);
                } else {
                    break;
                }
                ans.emplace_back(aj, ai);
                x = ai;
            }
            if (s.empty()) {
                ok = true;
                cout << "YES\n";
                cout << x_init << '\n';
                for(auto [x, y]: ans) cout << x << ' ' << y << '\n';
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
        }
    }
}