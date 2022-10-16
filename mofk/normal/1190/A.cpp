#include <bits/stdc++.h>

using namespace std;

long long n, k;
int m;
long long a[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) cin >> a[i], a[i] -= i;
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ++ans;
        long long blk = a[i] / k, pos = 0;
        while (i <= m && (a[i] + pos) / k == blk) ++pos, ++i;
        --i;
    }
    cout << ans << endl;
    return 0;
}