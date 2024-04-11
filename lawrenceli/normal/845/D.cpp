#include <bits/stdc++.h>

using namespace std;

int n;
int numo;
int stk[200100], stksze;
int cur;
int ans;

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t == 1) {
            cin >> cur;
            while (stksze && cur > stk[stksze - 1]) stksze--, ans++;
        } else if (t == 2) ans += numo, numo = 0;
        else if (t == 3) {
            int s; cin >> s;
            if (s >= cur) stk[stksze++] = s;
            else ans++;
        } else if (t == 4) numo = 0;
        else if (t == 5) stksze = 0;
        else numo++;
    }

    cout << ans << '\n';
}