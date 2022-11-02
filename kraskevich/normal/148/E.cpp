#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

long long ans[101][10000];

int main() {
    int n, m;
    
    cin >> n >> m;
    
    vector<vector<int> > a(n);
    
    for(int i = 0; i < n; ++i) {
            int k;           
            cin >> k;
            a[i].resize(k);
            for(int j = 0; j < k; ++j)
                    cin >> a[i][j];
    }
    
    long long f[n][101];
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j <= 101; ++j)
                    f[i][j] = 0;
    
    for(int i = 0; i < n; ++i) {
            int s = a[i].size();
            int sum[s];
            sum[0] = a[i][0];
            for(int j = 1; j < s; ++j)
                  sum[j] = sum[j - 1] + a[i][j];
            for(int l = -1; l < s; ++l)
                    for(int r = s; r > l; --r) {
                            long long cur = 0;
                            if(r != s)
                                 cur += sum[s - 1] - (r == 0 ? 0 : sum[r - 1]);
                            if(l >= 0)
                                 cur += sum[l];
                            f[i][l + 1 + s - r] = max(f[i][l + 1 + s - r], cur);
                    }
    }
    for(int i = 0; i <= m; ++i)
            ans[0][i] = 0;
    for(int i = 1; i <= n; ++i) {
            int index = i - 1;
            for(int j = 0; j <= m; ++j) {
                    ans[i][j] = 0;
                    for(int k = 0; k <= min((int)a[index].size(), j); ++k)
                            ans[i][j] = max(ans[i][j], ans[i - 1][j - k] + f[index][k]);
            }
    }
    
    cout << ans[n][m];
    
    cin >> n;
    
    return 0;
}