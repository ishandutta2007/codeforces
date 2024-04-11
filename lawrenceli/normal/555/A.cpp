#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100100;

int n, k, ans;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i=0; i<k; i++) {
        int m; cin >> m;
        for (int j=0; j<m; j++) cin >> a[j];
        if (a[0] == 1) {
            for (int j=0; j+1<m; j++)
                if (a[j]+1 != a[j+1]) {
                    ans += 2*(m-j-1);
                    break;
                }
        } else ans += 2*(m-1);
    }
    ans += k-1;

    cout << ans;
}