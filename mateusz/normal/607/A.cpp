#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int a[N], b[N], dp[N];
pair<int, int> tab[N];
int n;

int find(int p, int w) {
    int poc = 1;
    int kon = p;
    int ret = 0;
    while (poc <= kon) {
        int sr = (poc + kon) / 2;
        if (a[sr] < w) {
            ret = sr;
            poc = sr + 1;
        } else {
            kon = sr - 1;
        }
    }
    return ret;
}

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &tab[i].first, &tab[i].second);
    }
    
    sort(tab + 1, tab + 1 + n);
    for (int i = 1; i <= n; i++) {
        a[i] = tab[i].first;
        b[i] = tab[i].second;
    }
    
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        int f = find(i, a[i] - b[i]);
        dp[i] = dp[f] + (i - f - 1);
        ans = min(ans, dp[i] + (n - i));
    }
    
    printf("%d\n", ans);    
    return 0;
}