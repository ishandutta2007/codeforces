#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    auto query = [&](vector<bool> v) {
        for (auto x : v) cout << "FT"[x];
        cout << endl;
        int correct;
        cin >> correct;
        if (correct == n) exit(0);
        return correct;
    };
    
    int tot_false = query(vector<bool>(n));
    vector<bool> diff(n), ans(n);
    for (int i = 0; i < n; i += 2) diff[i] = true;
    int tot_diff = query(diff);

    for (int pos = 0;;) {
        assert(pos <= n);
        if (pos == n) {
            query(ans);
            assert(false);
        }

        if (pos == n - 1) {
            query(ans);
            ans[pos] = true;
            query(ans);
            assert(false);
        }

        if (pos == n - 2) {
            for (int first : {0, 1}) {
                for (int second : {0, 1}) {
                    ans[pos] = first;
                    ans[pos + 1] = second;
                    query(ans);
                }
            }
            assert(false);
        }

        vector<bool> tmp(n);
        tmp[pos] = tmp[pos + 1] = true;
        int cur = query(tmp) - tot_false;
        if (cur == 2) {
            ans[pos] = ans[pos + 1] = true;
            pos += 2;
            continue;
        } else if (cur == -2) {
            pos += 2;
            continue;
        }
        assert(cur == 0);

        // 01 or 10
        tmp = diff;
        for (int d : {0, 1, 2}) tmp[pos + d] = !tmp[pos + d];
        cur = query(tmp) - tot_diff;

        if (cur == 3) {
            ans[pos] = tmp[pos];
            ans[pos + 1] = tmp[pos + 1];
            ans[pos + 2] = tmp[pos + 2];
        } else if (cur == 1) {
            ans[pos] = tmp[pos];
            ans[pos + 1] = tmp[pos + 1];
            ans[pos + 2] = diff[pos + 2];
        } else if (cur == -1) {
            ans[pos] = diff[pos];
            ans[pos + 1] = diff[pos + 1];
            ans[pos + 2] = tmp[pos + 2];
        } else if (cur == -3) {
            ans[pos] = diff[pos];
            ans[pos + 1] = diff[pos + 1];
            ans[pos + 2] = diff[pos + 2];
        }
        pos += 3;
    }
}