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
    int zero, one, k;
    cin >> zero >> one >> k;
    if (k == 0) {
        cout << "Yes\n";
        rep(_, 2) {
            rep(i, one) cout << 1;
            rep(i, zero) cout << 0;
            cout << '\n';
        }
        return 0;
    }
    if (one == 1 || zero == 0) {
        cout << "No\n";
        return 0;
    }
    int s = zero + one;
    if (k >= s - 1) {
        cout << "No\n";
        return 0;
    }
    VI y(s), x;
    y.back() = 1;
    int rest = one - 1;
    rep(i, s) {
        if (i == k) continue;
        if (rest) {
            y[i] = 1;
            rest--;
        } else break;
    }
    int carry = 0;
    x = y;
    rep(i, k) {
        int z = x[i] + carry + 1;
        x[i] = z & 1;
        carry = z >> 1;
    }
    x[k] += carry;
    cout << "Yes\n";
    rrep(i, s) cout << x[i];
    cout << '\n';
    rrep(i, s) cout << y[i];
    cout << '\n';
}