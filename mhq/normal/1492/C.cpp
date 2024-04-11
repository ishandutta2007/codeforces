#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int n, m;
int pref[maxN];
int suf[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int cur_sz = 0;
    pref[0] = 0;
    for (int i = 0; i < s.size(); i++) {
        if (cur_sz < t.size() && s[i] == t[cur_sz]) {
            pref[cur_sz + 1] = i;
            cur_sz++;
        }
    }
    cur_sz = t.size() - 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (cur_sz >= 0 && s[i] == t[cur_sz]) {
            suf[cur_sz] = i;
            cur_sz--;
        }
    }
    int best = -1e9;
    for (int i = 0; i + 1 < t.size(); i++) {
        best = max(best, suf[i + 1] - pref[i + 1]);
    }
    cout << best;
    return 0;
}