#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
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
        vector<P> es, os;
        int n, m;
        cin >> n >> m;
        VI a(n);
        rep(i, n) cin >> a[i];
        VI ans(n, -1);
        VI ord(n);
        iota(all(ord), 0);
        sort(all(ord), [&](int i, int j) {return a[i] < a[j];});
        vector<char> s(n);
        rep(i, n) {
            char c;
            cin >> c;
            s[i] = c;
        }
        rep(zz, n) {
            int i = ord[zz];
            // cout << i << endl;
            if (a[i] % 2) swap(es, os);
            char c;
            c = s[i];
            if (c == 'R') {
                es.emplace_back(i, a[i]);
            } else {
                if (!es.empty()) {
                    auto [j, p] = es.back(); es.pop_back();
                    // cout << "!! " << j << ' ' << p << i << ' ' << a[i] << endl;
                    int t = (a[i] - p) / 2;
                    ans[i] = ans[j] = t;
                } else {
                    es.emplace_back(i, -a[i]);
                }
            }
            if (a[i] % 2) swap(es, os);
        }
        rep(_, 2) {
            while(es.size() >= 2) {
                auto [i, pi] = es.back(); es.pop_back();
                auto [j, pj] = es.back(); es.pop_back();
                int t = (2 * m - pi - pj) / 2;
                ans[i] = ans[j] = t;
            }
            swap(es, os);
        }
        rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    }
}