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

P ask() {
    string s;
    cin >> s;
    // if (s == "Right") return {0, 1};
    // else if (s == "Left") return {0, -1};
    // else if (s == "Up") return {-1, 0};
    // else if (s == "Down") return {1, 0};
    // else if (s == "Down-Right") return {1, 1};
    // else if (s == "Down-Left") return {1, -1};
    // else if (s == "Up-Left") return {-1, -1};
    // else if (s == "Up-Right") return {-1, 1};
    if (s == "Right") return {0, 1};
    else if (s == "Left") return {0, 1};
    else if (s == "Up") return {1, 0};
    else if (s == "Down") return {1, 0};
    else if (s == "Down-Right") return {1, 1};
    else if (s == "Down-Left") return {1, 1};
    else if (s == "Up-Left") return {1, 1};
    else if (s == "Up-Right") return {1, 1};
    else throw 111;
}

void tell(int x, int y) {
    cout << x + 1 << ' ' << y + 1 << endl;
}

void solve() {
    int x = 1, y = 1;
    tell(x, y);
    int dx = 1, dy = 1;
    vector<P> pq{{1, 1}, {6, 1}, {6, 6}, {1, 6}};
    bool next_ask = true;
    rep(z, 4) {
        for(auto [p, q]: pq) {
            while(x != p || y != q) {
                if (next_ask) {
                    auto [mx, my] = ask();
                    dx ^= mx, dy ^= my;
                }
                next_ask = false;
                int nx = x, ny = y;
                if (dx == 0) {
                    if (x == p) break;
                    nx += (x < p ? 1 : -1);
                }
                if (dy == 0) {
                    if (y == q) break;
                    ny += (y < q ? 1 : -1);
                }
                next_ask = true;
                dx = 1, dy = 1;
                x = nx, y = ny;
                tell(x, y);
            }
        }
        if (z == 0) {
            dx ^= 1;
        } else if (z == 1) {
            dy ^= 1;
        } else if (z == 2) {
            dx ^= 1;
        } else ask();
        if (next_ask) {
            auto [mx, my] = ask();
            dx ^= mx, dy ^= my;
        }
        next_ask = false;
        if (dx == 1 && dy == 1) {
            int nx = x + (x >= 3 ? -2 : 2);
            int ny = y + (y >= 3 ? -2 : 2);
            x = nx, y = ny;
            tell(x, y);
            next_ask = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        try {
            solve();
        } catch(int i) {
            ;
        }
    }
}