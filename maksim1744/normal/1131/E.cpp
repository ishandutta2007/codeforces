/*
    27.03.2019 19:18:58
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    int n;
    cin >> n;
    vector<string> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<long long> best(26, 0);
    for (int i = 0; i < n; ++i) {
        if (p[i] == string(p[i].size(), p[i][0])) {
            long long k = best[p[i][0] - 'a'];
            for (int k = 0; k < 26; ++k) {
                best[k] = min(1ll, best[k]);
            }
            best[p[i][0] - 'a'] = min(k + (long long)p[i].size() * (k + 1), 1000000000ll);
        } else {
            vector<long long> new_best(26, 0);
            long long nowl = 1;
            for (int j = 1; j <= p[i].size(); ++j) {
                if (j == p[i].size() || p[i][j] != p[i][j - 1]) {
                    new_best[p[i][j - 1] - 'a'] = max(new_best[p[i][j - 1] - 'a'], nowl);
                    nowl = 0;
                }
                ++nowl;
            }
            // show(new_best);
            long long pref = 0;
            while (p[i][pref] == p[i][0])
                ++pref;
            long long suf = 0;
            while (p[i][p[i].size() - suf - 1] == p[i].back())
                ++suf;
            if (p[i][0] == p[i].back()) {
                suf += pref;
                pref = suf;
            }
            if (best[p[i][0] - 'a'] > 0)
                new_best[p[i][0] - 'a'] = max(new_best[p[i][0] - 'a'], pref + 1);
            if (best[p[i].back() - 'a'] > 0)
                new_best[p[i].back() - 'a'] = max(new_best[p[i].back() - 'a'], suf + 1);
            for (int i = 0; i < 26; ++i) {
                best[i] = min(max((long long)(best[i] > 0), new_best[i]), 1000000000ll);
            }
            // swap(best, new_best);
        }
        // show(best);
    }
    cout << *max_element(best.begin(), best.end()) << '\n';
    return 0;
}