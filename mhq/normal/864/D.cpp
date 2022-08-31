#include <bits/stdc++.h>
using namespace std;
int f[200010];
bool g[200010];
int a[200010];
queue < int > t[200010];
int main() {
    //freopen("jellous.in", "r", stdin);
    //freopen("jellous.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for ( int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]]++;
        t[a[i]].push(i);
        g[a[i]] = true;
    }
    int ind = 1;
    int ans = 0;
    for ( int i = 1; i <= n; i++) {
        if  ( g[i] == true) continue;
        for ( int j = ind; j <= n; j++) {
            if ( f[a[j]] <= 1) continue;
            if ( i < a[j]) {
                f[a[j]]--;
                t[a[j]].pop();
                a[j] = i;
                ind = j + 1;
                break;
            }
            else {
                if (t[a[j]].front() != j) {
                    f[a[j]]--;
                    t[a[j]].pop();
                    a[j] = i;
                    ind = j + 1;
                    break;
                }
            }
        }
        ans++;
    }
    cout << ans << '\n';
    for ( int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}