#include <bits/stdc++.h>
using namespace std;
int l, r;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> l >> r;
    int sqr = sqrt(r + 10);
    sqr++;
    int s = sqr + 1;
    int ans = 0;
    vector < int > used(sqr + 10, 0);
    vector < int > all;
    for (int i = 2; i <= sqr; i++) {
        if (used[i] == 0) {
            all.push_back(i);
            for (int j = 2 * i; j <= sqr; j += i) used[j] = 1;
        }
    }
    vector < int > now(s);
    // all * x >= l1
    // x >= l1 / all
    for (int block = 0; block < (r + 2 * s) / s; block++) {
        for (int& j : now) j = 0;
        int l1 = block * s + 1;
        int r1 = (block + 1) * s;
        for (int j = 0; j < all.size(); j++) {
            int x = (all[j] + l1 - 1) / all[j];
            int st = x * all[j];
            if (st == all[j]) st += all[j];
            while (st <= r1) {
                now[st - l1] = 1;
                st += all[j];
            }
        }
        if (block == 0) now[0] = 1;
        for (int j = l1; j <= r1; j++) {
            if (j > r) break;
            if (now[j - l1] == 0) {
                if (j % 4 == 1 && j >= l && j <= r) {
                    ans++;
                }
            }
        }
    }
    if (2 >= l && 2 <= r) ans++;
    cout << ans;
    return 0;
}