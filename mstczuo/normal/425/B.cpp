# include <iostream>
# include <cstdio>

using namespace std;
int a[120][120];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin >> a[i][j];
    int ans = n * m;
    if(n <= k) {
        for(int mask = 0; mask < (1<<n); ++mask) {
            int cur = 0;
            for(int j=0; j<m; ++j) {
                int sum = 0;
                for(int i=0; i<n; ++i) 
                    sum += a[i][j] != ((mask &(1<<i)) > 0);
                cur += min(sum, n - sum);
            }
            if(cur < ans) ans = cur;
        }
    } else {
        for(int s = 0; s < m; ++s) {
            int cur = 0;
            for(int j=0; j<m; ++j) {
                int sum = 0;
                for(int i=0; i<n; ++i)
                    sum += (a[i][j] != a[i][s]);
                cur += min(sum, n-sum);
            }
            if(cur < ans) ans = cur;
        }
    }

    if(ans > k) ans = -1;
    cout << ans << endl;
}