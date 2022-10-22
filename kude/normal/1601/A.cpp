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

std::vector<long long> divisors(long long x) {
    std::vector<long long> res1, res2;
    long long d = 1;
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
        int hist[30] = {};
        rep(i, n) {
            int x;
            cin >> x;
            rep(k, 30) if (x >> k & 1) hist[k]++;
        }
        int g = 0;
        rep(k, 30) g = gcd(g, hist[k]);
        if (g == 0) {
            for(int k = 1; k <= n; k++) cout << k << " \n"[k == n];
            continue;
        }
        auto d = divisors(g);
        int sz = d.size();
        rep(i, sz) cout << d[i] << " \n"[i + 1 == sz];
    }
}