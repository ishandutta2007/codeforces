
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int t, n, m, a[N], b;
bool vis[N];

// vis[x] = true if x appears in array a
// for each element b[i], we check if it is also in a
// don't forget to reset vis array before the next test case

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            vis[a[i]] = true;
        }
        int e = -1;
        for(int j = 0; j < m; j++) {
            cin >> b;
            if(vis[b]) e = b;
        }
        for(int i = 0; i < n; i++) {
            vis[a[i]] = false;
        }
        if(e == -1) {
            cout << "NO\n";
        }else {
            cout << "YES\n1 " << e << '\n';
        }
    }
}