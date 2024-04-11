#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int n, m;
string ar[MAXN], cur[MAXN], cur2[MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> ar[i], cur[i] = "";
    int ans = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) cur2[j] = cur[j]+ar[j][i];
        bool good = 1;
        for (int j=0; j<n-1; j++)
            if (cur2[j] > cur2[j+1])
                good = 0;
        if (!good) ans++;
        else {
            for (int j=0; j<n; j++) cur[j] = cur2[j];
        }
    }

    cout << ans << '\n';
    return 0;
}