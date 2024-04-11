# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cstring>
# include <vector>
using namespace std;

const int N = 100010;

int a[N], b[N], f[N][320];
vector<int> c[N];

int main() {
    int n, m, s, e, r = 0;
    cin >> n >> m >> s >> e;
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]), r = max(r, a[i]);
    for(int i=1; i<=m; ++i) scanf("%d", &b[i]), c[b[i]].push_back(i);
    for(int i=1; i<=r; ++i) c[i].push_back(0x3fffffff);
    int limit = s / e;
    memset(f, 0x3f, sizeof(f));

    f[0][0] = 0;
    for(int i=0; i<n; ++i)
        for(int j=0; j<=limit; ++j) {
            f[i+1][j] = min(f[i+1][j], f[i][j]);
            vector<int> &t = c[a[i+1]];
            int k = *upper_bound(t.begin(),t.end(),f[i][j]);
            if(k != 0x3fffffff) 
                f[i+1][j+1] = min(f[i+1][j+1], k);
        }

    int ans = 0;
    for(int j=0; j<=limit; ++j)
        for(int i=1; i<=n; ++i) 
            if(f[i][j] != 0x3f3f3f3f)
                if(j*e+i+f[i][j] <= s) ans = j;
    cout << ans << endl;
    return 0;
}