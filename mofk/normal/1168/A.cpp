#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[300005];

bool check(int k) {
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= cur) {
            if (a[i] + k < cur) return 0;
        }
        else {
            if (a[i] + k < m) cur = a[i];
            else if ((a[i] + k) % m < cur) cur = a[i];
        }
    }
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int l = 0, r = m;
    while (l < r) {
        int k = l + r >> 1;
        if (check(k)) r = k;
        else l = k + 1;
    }
    cout << l << endl;
    return 0;
}