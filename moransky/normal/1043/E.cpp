/*

 i, ji -> j -> 
a[i] + b[j] < a[j] + b[i]
a[i] - b[i] < b[i] - b[j]
 a[i] - b[i] 

ans[i] += (i - 1) * b[i] + (n - i) * a[i]
a[1 ~ i - 1] 
b[i + 1 ~ n] 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 300005;
struct Node{
    int a, b, id;
    bool operator < (const Node &x) const{
        return a - b < x.a - x.b;
    }
}e[N];
int n, m, ne[N];
LL pre[N], suf[N], ans[N];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &e[i].a, &e[i].b);
        e[i].id = i;
    }
    sort(e + 1, e + 1 + n);
    for(int i = 1; i <= n; i++) ne[e[i].id] = i;
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + e[i].a;
    for(int i = n; i; i--) suf[i] = suf[i + 1] + e[i].b;
    for(int i = 1; i <= n; i++) {
        ans[i] = (LL)e[i].b * (i - 1) + (LL)e[i].a * (n - i) + pre[i - 1] + suf[i + 1]; 
    }

    for(int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        u = ne[u], v = ne[v];
        if(u > v) swap(u, v);
        ans[u] -= e[u].a + e[v].b;
        ans[v] -= e[u].a + e[v].b;
    }
    for(int i = 1; i <= n; i++)
        printf("%lld ", ans[ne[i]]);
    return 0;
}