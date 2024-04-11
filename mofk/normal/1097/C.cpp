#include <bits/stdc++.h>

using namespace std;

int n;
string s[100005];
int l[500005], r[500005], f0;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        int depth = 0, min_depth = 0;
        for (int j = 0; j < s[i].size(); ++j) {
            if (s[i][j] == '(') ++depth;
            else --depth;
            min_depth = min(min_depth, depth);
        }
        if (depth > 0) {
            if (min_depth == 0) ++l[depth];
        }
        else if (depth == 0) {
            if (min_depth == 0) ++f0;
        }
        else {
            if (min_depth == depth) ++r[-depth];
        }
    }
    int ans = 0;
    for (int i = 1; i <= 500000; ++i) ans += min(l[i], r[i]);
    ans += f0 / 2;
    cout << ans << endl;
    return 0;
}