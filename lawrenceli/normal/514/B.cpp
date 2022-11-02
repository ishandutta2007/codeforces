#include <bits/stdc++.h>
using namespace std;

int n, x0, y0, x[1005], y[1005], b[1005];

int main() {
    cin >> n >> x0 >> y0;
    for (int i=0; i<n; i++) { cin >> x[i] >> y[i]; b[i] = 1; }
    int ans = 0;
    for (int i=0; i<n; i++) if (b[i]) {
        b[i] = 0;
        ans++;
        for (int j=0; j<n; j++)
            if ((y[i]-y0)*(x[j]-x0) == (y[j]-y0)*(x[i]-x0))
                b[j] = 0;
    }
    cout << ans;
}