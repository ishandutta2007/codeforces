#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    pair<int, int> me;
    cin >> me.first >> me.second;
    me.first--, me.second--;
    int n = 666;
    vec<pair<int, int>> where(n);
    int sz = 999;
    for (auto &[x, y] : where) {
        cin >> x >> y, x--, y--;
    }
    set<pair<int, int>> who(all(where));
    auto make_step = [&]() {
        cout << me.first + 1 << ' ' << me.second + 1 << endl;
        for (auto [x, y] : where) {
            if (x == me.first || y == me.second) exit(0);
        }
        int k, new_x, new_y;
        cin >> k >> new_x >> new_y, new_x--, new_y--;
        k--;
        who.erase(where[k]);
        where[k] = {new_x, new_y};
        who.insert(where[k]);
    };
    while (me != pair<int, int>{sz / 2, sz / 2}) {
        auto before = me;
        if (me.first != sz / 2) {
            if (me.first > sz / 2) me.first--;
            else me.first++;
        }
        if (me.second != sz / 2) {
            if (me.second > sz / 2) me.second--;
            else me.second++;
        }
        if (who.count(me)) me.first = before.first;
        make_step();
    }
    int cnt[4]{0, 0, 0, 0};
    for (auto [x, y] : where) {
        cnt[(x > sz / 2) * 2 + (y > sz / 2)]++;
    }
    int mn = min_element(all(cnt)) - cnt;
    int dir = mn ^ 3;
    int dx = ((dir >> 1) % 2 == 0 ? -1 : 1);
    int dy = (dir % 2 == 0 ? -1 : 1);
    while (true) {
        me.first += dx;
        me.second += dy;
        if (who.count(me)) me.first -= dx;
        make_step();
    }
}