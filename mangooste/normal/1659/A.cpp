#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n, r, b;
    cin >> n >> r >> b;
    int ans = r;
    string s;
    s += string(r, 'R');
    s += string(b, 'B');

    for (int c1 = 1; c1 <= n; c1++) {
        int blocks = (r + c1 - 1) / c1;
        int c2 = (b + blocks - 1) / blocks;
        int when_sub = b % blocks;
        if (b % blocks == 0) when_sub = -1;

        string cur;
        int left1 = r, left2 = b;
        while (len(cur) != n) {
            for (int i = 0; i < c1 && left1; i++, left1--) {
                cur += "R";
            }
            for (int i = 0; i < c2 && left2; i++, left2--) {
                cur += "B";
            }
            if (--when_sub == 0) c2--;
        }
        int cur_ans = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && cur[i] == cur[j]) j++;
            cur_ans = max(cur_ans, j - i);
        }
        if (ans > cur_ans) {
            ans = cur_ans;
            s = cur;
        }
    }

    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}