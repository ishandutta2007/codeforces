#include<bits/stdc++.h>
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

int hist[2100000];
int a[101];

std::vector<int> divisors(int x) {
    std::vector<int> res1, res2;
    int d = 1;
    for(; d * d < x; d++) {
        if (x % d == 0) {
            res1.push_back(d);
            res2.push_back(x / d);
        }
    }
    if (d * d == x) res1.push_back(d);
    int sz = res2.size();
    res1.reserve(res1.size() + sz);
    for(int i = sz - 1; i >= 0; i--) res1.push_back(res2[i]);
    return res1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        rep(i, n) cin >> a[i];
        int mn = *min_element(a, a + n);
        rep(i, n) a[i] -= mn;
        {
            rep(i, n) hist[a[i]]++;
            bool ok = false;
            rep(i, n) if (hist[a[i]] >= n / 2) ok = true;
            rep(i, n) hist[a[i]] = 0;
            if (ok) {
                cout << -1 << '\n';
                continue;
            }
        }
        int ans = 1;
        rep(i, n) rep(j, i) if (a[i] != a[j]) {
            int x = abs(a[i] - a[j]);
            for(int d: divisors(x)) if (d > ans) {
                int r = a[i] % d;
                int cnt = 0;
                rep(i, n) if (a[i] % d == r) cnt++;
                if (cnt >= n / 2) ans = d;
            }
        }
        cout << ans << '\n';
    }
}