#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
array <int, 2> b[nax];
int n;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i][0] >> b[i][1];
    }
    sort(b + 1, b + 1 + n);
    int max_span = b[1][0] + b[1][1];
    int64_t ans = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        ans += b[i][1];
        if (b[i][0] > max_span) {
            ans -= max_span;
            ans += b[i][0];
        }
        max_span = max(max_span, b[i][0] + b[i][1]);
    }
    cout << ans << '\n';

}