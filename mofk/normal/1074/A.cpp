#include <bits/stdc++.h>

using namespace std;

int n, m;
int ver[100005];
int hor[100005], l[100005], r[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> ver[i];
    sort(ver + 1, ver + n + 1);
    ver[n+1] = 1e9;
    int z = 0;
    for (int i = 1; i <= m; ++i) {
        int zzz;
        cin >> l[i] >> r[i] >> zzz;
        if (l[i] == 1) hor[++z] = r[i];
    }
    m = z;
    sort(hor + 1, hor + m + 1);
    int ans = n + m, ptr = 0;
    for (int i = 0; i <= n; ++i) {
        while (ptr < m && hor[ptr+1] < ver[i+1]) ++ptr;
        ans = min(ans, i + m - ptr);
    }
    cout << ans << endl;
    return 0;
}