#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

int n, q;
ii a[Maxn];
ii glob;
ll sum;

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = 0;
        sum += a[i].first;
    }
    glob = ii(0, -1);
    for (int i = 1; i <= q; i++) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int ind, val; scanf("%d %d", &ind, &val);
            if (a[ind].second < glob.second)
                a[ind] = glob;
            sum += val - a[ind].first;
            a[ind] = ii(val, i);
        } else {
            int x; scanf("%d", &x);
            sum = ll(x) * n;
            glob = ii(x, i);
        }
        printf("%I64d\n", sum);
    }
    return 0;
}