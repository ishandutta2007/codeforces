#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int mx = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > mx + 1) return cout << i << endl, 0;
        mx = max(mx, a[i]);
    }
    cout << -1 << endl;
    return 0;
}