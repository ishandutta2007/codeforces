
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    pt operator+(const  pt &o) const {
        return pt(x + o.x, y + o.y);
    }
    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }
    ll dot(const pt &o) const {
        return x * o.x + y * o.y;
    }
    bool operator==(const pt &o) const {
        return x == o.x && y == o.y;
    }
};

bool check(const pt &a, const pt &b, const pt &c) {
    if(a == b || b == c || c == a) return false;
    return (b - a).dot(c - a) == 0 || (c - b).dot(a - b) == 0 || (a - c).dot(b - c) == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<pt> p(3);
    rep(i, 0, 3) cin >> p[i].x >> p[i].y;
    bool almost = false;
    vector<pt> dir = {pt(1, 0), pt(-1, 0), pt(0, 1), pt(0, -1)};
    rep(i, 0, 3) {
        pt a = p[i], b = p[(i + 1) % 3], c = p[(i + 2) % 3];
        if(check(a, b, c)) {
            cout << "RIGHT\n";
            return 0;
        }
        for(pt &d : dir) {
            if(check(a + d, b, c)) {
                almost = true;
            }
        }
    }
    cout << (almost ? "ALMOST\n" : "NEITHER\n");
}