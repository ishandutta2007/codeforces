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

template <class S, S (*op)(S, S), S (*e)()>
struct SWAG {
    std::vector<S> ar, sl, sr;
    SWAG() : sl{e()}, sr{e()} {}
    explicit SWAG(const std::vector<S>& v) : sr{e()} {
        const int n = v.size();
        S x = e();
        sl.reserve(n + 1);
        sl.push_back(x);
        for (int i = n - 1; i >= 0; i--) {
            x = op(v[i], x);
            sl.push_back(x);
        }
    }

    void push(S x) {
        ar.push_back(x);
        sr.push_back(op(sr.back(), x));
    }

    void pop() {
        assert(sl.size() != 1 || ar.size() != 0);
        if (sl.size() != 1) {
            sl.pop_back();
        } else {
            const int n = ar.size();
            S x = e();
            for (int i = n - 1; i >= 1; i--) {
                x = op(ar[i], x);
                sl.push_back(x);
            }
            ar.resize(0);
            sr.resize(1);
        }
    }

    S all_prod() { return op(sl.back(), sr.back()); }

    int size() { return (int)sl.size() - 1 + ar.size(); }
};

ll op(ll x, ll y) {return gcd(x, y);}
ll e() {return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VL a(n);
        rep(i, n) cin >> a[i];
        rep(i, n - 1) a[i] = abs(a[i + 1] - a[i]);
        a.pop_back();
        int ans = 0;
        SWAG<ll, op, e> sw;
        int r = 0;
        rep(l, n - 1) {
            r = max(l, r);
            while(r < n - 1 && gcd(sw.all_prod(), a[r]) != 1) sw.push(a[r++]);
            chmax(ans, r - l);
            if (l < r) sw.pop();
        }
        cout << ans + 1 << '\n';
    }
}