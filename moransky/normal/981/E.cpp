#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10005;
int n, Q;
int f[N];
struct Node{
    int l, r, x;
    bool operator < (const Node &x) const {
        return r < x.r;
    }
}e[N];
/*
f[i]  i 

*/
int main() {
    scanf("%d%d", &n, &Q);
    for(int i = 1; i <= Q; i++) {
        scanf("%d%d%d", &e[i].l, &e[i].r, &e[i].x);
    }
    sort(e + 1, e + 1 + Q);
    f[0] = n + 1;
    for(int i = 1; i <= Q; i++) {
        for (int j = n; j >= e[i].x; j--) {
            if(f[j - e[i].x] >= e[i].l) f[j] = max(f[j], min(f[j - e[i].x], e[i].r));
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(f[i]) ans++;
    printf("%d\n", ans);
    for(int i = 1; i <= n; i++)
        if(f[i]) printf("%d ", i);
    return 0;
}