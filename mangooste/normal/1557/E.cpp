#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

void solve() {
    int x, y;
    auto go = [&](int new_x, int new_y) {
        assert(x != new_x || y != new_y);
        cout << new_x << ' ' << new_y << endl;
        x = new_x, y = new_y;
        string s;
        cin >> s;
        return s;
    };

    if (go(1, 8) == "Done")
        return;

    while (x < 7) {
        bool up = false;
        bool down = false;

        for (int i = 1; i <= 8; i++) {
            string s = go(x, i);
            if (s == "Done")
                return;

            if (s == "Down" || s == "Down-Left" || s == "Down-Right") {
                down = true;
                break;
            }
            up |= s != "Left" && s != "Right";
        }

        if (down || !up) {
            if (go(x + 1, y) == "Done")
                return;

            if (y == 1)
                if (go(x, 8) == "Done")
                    return;
        }
    }

    for (int i = 1; i <= 7; i++)
        if (go(x, i) == "Done")
            return;

    assert(false);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}