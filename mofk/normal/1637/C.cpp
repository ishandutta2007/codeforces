#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        long long sum = 0, sup = 0, dem = 0;
        for (int i = 1; i < n - 1; ++i) {
            dem += a[i] % 2;
            sup += (a[i] > 1);
            sum += a[i];
        }
        if (n == 3 && dem) cout << -1 << endl;
        else if (sup == 0) cout << -1 << endl;
        else cout << (sum + dem) / 2 << endl;
    }
    return 0;
}