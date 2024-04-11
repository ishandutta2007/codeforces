#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
ii best[2];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int st = 0, val = 0;
        best[st] = ii(val, 0);
        best[!st] = ii(Maxn, 0);
        int res = 0;
        ii wth = ii(0, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] == 0) {
                best[st] = ii(val, i);
                best[!st] = ii(Maxn, i);
            } else {
                if (a[i] < 0) {
                    st = !st;
                    a[i] = -a[i];
                }
                if (a[i] == 2) val++;
                if (val - best[st].first > res) {
                    res = val - best[st].first;
                    wth = ii(best[st].second, i);
                }
                best[st] = min(best[st], ii(val, i));
            }
        }
        printf("%d %d\n", wth.first, n - wth.second);
    }
    return 0;
}