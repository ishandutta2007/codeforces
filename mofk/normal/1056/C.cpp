#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[2005];
int match[2005];
int picked[2005];
int t;

void pick(int x) {
    cout << x << endl;
    picked[x] = 1;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n + n; ++i) cin >> a[i];
    for (int i = 1; i <= k; ++i) {
        int u, v;
        cin >> u >> v;
        match[u] = v;
        match[v] = u;
    }
    cin >> t;
    int forced = 0;
    for (int i = 1; i <= n + n; ++i) {
        if (t == 1) {
            if (forced > 0) pick(forced);
            else {
                int flag = 0;
                for (int j = 1; j <= n + n; ++j) if (!picked[j] && match[j]) {
                    if (a[j] < a[match[j]]) pick(match[j]);
                    else pick(j);
                    flag = 1;
                    break;
                }
                if (!flag) {
                    for (int j = 1; j <= n + n; ++j) if (!picked[j] && a[j] > a[flag]) flag = j;
                    pick(flag);
                }
            }
        }
        else {
            int x;
            cin >> x;
            if (x == -1) return 3;
            picked[x] = 1;
            if (match[x] && !picked[match[x]]) forced = match[x];
            else forced = 0;
        }
        t = 3 - t;
    }
    return 0;
}