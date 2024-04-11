 
#include<bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 200010;
 
int n,m;
vector<int> pin[MAXN];
int deg[MAXN];
 
long long contribution(int x) {
    return 1LL * pin[x].size() * (deg[x] - pin[x].size());
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        a--;
        b--;
        if (a > b) {int t = a; a = b; b = t;}
        pin[a].push_back(b);
        deg[a]++; deg[b]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) ans += contribution(i);
    printf("%I64d\n", ans);
    int q; scanf("%d", &q);
    while(q--) {
        int a; scanf("%d", &a); a--;
        ans -= contribution(a);
        for (int x : pin[a]) {
            ans -= contribution(x);
            pin[x].push_back(a);
            ans += contribution(x);
        }
        pin[a].clear();
        printf("%I64d\n", ans);
    }
    return 0;
}