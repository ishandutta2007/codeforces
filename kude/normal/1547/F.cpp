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
        int n;
        cin >> n;
        VI a(2 * n);
        rep(i, n) cin >> a[i], a[i + n] = a[i];
        int l = 0, r = n;
        while(r - l > 1) {
            int c = (l + r) >> 1;
            VI st_l{0}, st_r{0};
            rep(i, c) st_r.push_back(gcd(st_r.back(), a[i]));
            bool ok = true;
            const int x = gcd(st_l.back(), st_r.back());
            rep(i, n) {
                if (gcd(st_l.back(), st_r.back()) != x) {
                    ok = false;
                    break;
                }
                if (st_l.size() == 1) {
                    for(int j = i + c - 1; j >= i; j--) {
                        st_l.push_back(gcd(st_l.back(), a[j]));
                    }
                    st_r.resize(1);
                }
                st_l.pop_back();
                st_r.push_back(gcd(st_r.back(), a[i + c]));
            }
            if (ok) r = c;
            else l = c;
        }
        cout << r - 1 << '\n';
    }
}