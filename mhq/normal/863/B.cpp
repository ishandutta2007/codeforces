#include <bits/stdc++.h>
using namespace std;
int w[102];
int n;
int ans(int i, int j) {
    bool used[102];
    for ( int b = 1; b <= 2*n; b++) {
        used[b] = false;
    }
    int x1 = 0; int x2 = 0; int r = 0;
    used[i] = true; used[j] = true;
    for ( int k = 1; k <= 2*n; k++) {
        if ( used[k] == true) {
            continue;
        }
        if ( x1 == x2) {
                r = r - w[k];
                x1++;
                }
        else {
                r = r + w[k];
                x2++;
        }
    }
    return r;
}
int main()
{   ios_base::sync_with_stdio(0);
    cin >> n;
    int a;
    for ( int i = 1; i <= 2*n; i++) {
        cin >> w[i];
    }
    sort(w + 1, w + 2*n + 1);
    int ans1 = 100000000;
    for ( int i = 1; i <= 2*n; i++) {
        for ( int j = i + 1; j <= 2*n; j++) {
            ans1 = min(ans1, ans(i, j));
        }
    }
    cout << ans1;
    return 0;
}