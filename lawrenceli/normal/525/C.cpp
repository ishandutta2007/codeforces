#include <bits/stdc++.h>
using namespace std;

long long n, a[100100], i, m, s;

main() {
    cin >> n;
    for (i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    for (i=n-2; i>=0; i--)
        if (a[i+1]-a[i] < 2) {
            if (m) s += m*a[i], m = 0;
            else m = a[i];
            i--;
        }
    cout << s;
}