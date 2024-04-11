#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100005;
int n, a[N], b[N], cnt[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i), cnt[b[i]] = i;
    int ans = 0, s = 0;
    for (int i = 1; i <= n; i++) {
        if(cnt[a[i]] < s) ans++;
        s = max(s, cnt[a[i]]);
    }
    printf("%d\n", ans);
}