#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

string s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> s >> t;
    int ans = INT_MAX;
    for (int aS = 0; aS < s.size(); aS++) {
        for (int bT = 0; bT < t.size(); bT++) {
            if (aS != 0 && bT != 0) continue;
            int diff = bT;
            int i = aS;
            int j = bT;
            while (i < s.size() && j < t.size()) {
                diff += (s[i] != t[j]);
                i++;
                j++;
            }
            diff += (t.size() - j);
            ans = min(ans, diff);
        }
    }
    cout << ans;
    return 0;
}