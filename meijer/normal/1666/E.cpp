#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;

int n, L, a[N];

int check(int l, int r) {
    int cur_l = 0, cur_r = 0;
    for (int i = 1; i <= n; i++) {
        if (cur_l + l > a[i + 1])
            return 2;
        if (cur_r + r < a[i])
            return 0;
        int new_l = max(a[i], cur_l + l);
        int new_r = min(a[i + 1], cur_r + r);
        cur_l = new_l;
        cur_r = new_r;

    }
    return (cur_l <= L && cur_r >= L);
}

int is_ok(int diff) {
    int l = 1, r = L;
    while (l < r - 1) {
        int mn = (l + r) / 2;
        int x = check(mn, mn + diff);
        if (x == 1)
            return mn;
        if (x == 2)
            r = mn;
        if (x == 0)
            l = mn;
    }
    for (int i = l; i <= r; i++)
        if (check(i, i + diff) == 1)
            return i;
    return 0;
}

int main() {
    cin >> L >> n;
    a[n + 1] = L;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = -1, r = L;
    while (l < r - 1) {
        int diff = (l + r) / 2;
        if (is_ok(diff) != 0)
            r = diff;
        else
            l = diff;
    }
    int diff = r;




    l = is_ok(diff);
    r = l + diff;
    vector<pair<int, int> > q;
    int cur_l = 0, cur_r = 0;
    for (int i = 1; i <= n; i++) {
        q.pb({cur_l, cur_r});
        int new_l = max(a[i], cur_l + l);
        int new_r = min(a[i + 1], cur_r + r);
        cur_l = new_l;
        cur_r = new_r;
    }

    vector<pair<int, int> > ans;
    int cur = L;
    for (int i = q.size() - 1; i >= 0; i--) {
        if (cur - l <= q[i].second) {
            ans.pb({cur - l, cur});
            cur -= l;
        } else {
            ans.pb({q[i].second, cur});
            cur = q[i].second;
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto [x, y] : ans)
        cout << x << ' ' << y << "\n";
}