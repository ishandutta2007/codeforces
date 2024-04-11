#include <bits/stdc++.h>

using namespace std;

int n;
long long a[2005], b[2005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    long long s = 0, t = 0;
    for (int i = 0; i < n + n; ++i) {
        cin >> a[i] >> b[i];
        s += a[i];
        t += b[i];
    }
    cout << s / n << ' ' << t / n << endl;
    return 0;
}