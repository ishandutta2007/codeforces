#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 105;

int n, m, d, a[MAXN][MAXN];

int main() {
    ios :: sync_with_stdio(false);
    
    cin >> n >> m >> d;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];
    
    int ans = 1e9;
    
    for (int i=0; i<=10000; i++) {
        int cur = 0;
        
        for (int j=0; j<n; j++) {
            if (cur == -1) break;
            for (int k=0; k<m; k++) {
                if (abs(a[j][k] - i) % d) {
                    cur = -1; break;
                } else cur += (abs(a[j][k] - i) / d);
            }
        }
        
        if (cur != -1) ans = min(ans, cur);
    }
    
    if (ans != 1e9) cout << ans << '\n';
    else cout << "-1\n";
    return 0;
}