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

P dv(int n) {
    int d = 0;
    while(n >> d + 1) d++;
    int x = 1 << d - 1;
    return {x, n - x};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        rep(i, k - 3) cout << "1 ";
        n -= k - 3;
        if (n & 1) {
            int x = n >> 1;
            cout << 1 << ' ' << x << ' ' << x << '\n';
        } else {
            int x = n >> 1;
            if (x & 1) {
                x ^= 1;
                cout << 2 << ' ' << x << ' ' << x << '\n';
            } else {
                int y = x >> 1;
                cout << x << ' ' << y << ' ' << y << '\n';
            }
        }
    }
}