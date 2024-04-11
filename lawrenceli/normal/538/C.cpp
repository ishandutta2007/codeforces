#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;

int n, m, d[MAXN], h[MAXN];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> d[i] >> h[i];
        if (i == 0) {
            ans = max(ans, h[i]+d[i]-1);
        } else {
            if (abs(h[i]-h[i-1]) > d[i]-d[i-1]) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
            ans = max(ans, (d[i]-d[i-1]-abs(h[i]-h[i-1]))/2+max(h[i], h[i-1]));
        }
    }
    ans = max(ans, h[m-1]+n-d[m-1]);

    cout << ans;
}