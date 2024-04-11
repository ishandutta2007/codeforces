#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int pnt = 1;
        queue <int> Q; Q.push(a[0]);
        res[a[0]] = 0;
        int ans = 0;
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            ans = max(ans, res[v]);
            if (pnt < n) {
                res[a[pnt]] = res[v] + 1;
                Q.push(a[pnt]);
                pnt++;
                while (pnt < n && a[pnt - 1] < a[pnt]) {
                    res[a[pnt]] = res[v] + 1;
                    Q.push(a[pnt]);
                    pnt++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}