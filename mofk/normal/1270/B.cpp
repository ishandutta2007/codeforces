#include <bits/stdc++.h>

using namespace std;

int n;
int a[200005];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int id = -1;
        for (int i = 1; i < n; ++i) if (abs(a[i] - a[i+1]) > 1) id = i;
        if (id == -1) cout << "NO" << '\n';
        else cout << "YES" << '\n' << id << ' ' << id + 1 << '\n';
    }
    return 0;
}