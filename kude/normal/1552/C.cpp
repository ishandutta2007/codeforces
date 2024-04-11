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
        int n, k;
        cin >> n >> k;
        n *= 2;
        vector<P> pairs(k);
        vector<char> used(n);
        rep(i, k) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if (x > y) swap(x, y);
            pairs[i] = {x, y};
            used[x] = used[y] = true;
        }
        VI unused;
        rep(i, n) if (!used[i]) unused.push_back(i);
        assert(unused.size() == n - 2 * k);
        int d = n / 2 - k;
        rep(i, d) pairs.emplace_back(unused[i], unused[i + d]);
        int ans = 0;
        int sz = pairs.size();
        assert(sz == n / 2);
        sort(all(pairs));
        rep(j, sz) rep(i, j) {
            auto [x, y] = pairs[i];
            auto [z, w] = pairs[j];
            ans += z < y && y < w;
        }
        cout << ans << '\n';
    }
}