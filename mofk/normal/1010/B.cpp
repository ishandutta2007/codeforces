#include <bits/stdc++.h>

using namespace std;

int n, m;
int p[35];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        cout << m << endl;
        int ans;
        cin >> ans;
        if (ans == 0) exit(0);
        else p[i] = -ans;
    }
    int l = 1, r = m - 1, ptr = 1;
    while (l < r) {
        int md = l + r >> 1;
        cout << md << endl;
        int ans;
        cin >> ans;
        ans *= p[ptr];
        if (ans == 0) exit(0);
        else if (ans == -1) r = md;
        else l = md + 1;
        ptr = ptr % n + 1;
    }
    cout << l << endl;
    int ans;
    cin >> ans;
    exit(ans);
    return 0;
}