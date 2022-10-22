#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int v[Maxn];
ll maxt;

int main()
{
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
        maxt = max(maxt, (sum - 1) / i + 1);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int t; scanf("%d", &t);
        if (t < maxt) printf("-1\n");
        else {
            int k = (sum - 1) / t + 1;
            printf("%d\n", k);
        }
    }
    return 0;
}