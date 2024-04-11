#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
ll a[Maxn];
int b[Maxn];
int in[Maxn];
queue <int> Q;
int res[Maxn], lef, rig;
ll ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        if (b[i] != -1)
            in[b[i]]++;
    }
    rig = n - 1;
    for (int i = 1; i <= n; i++) if (in[i] == 0)
        Q.push(i);
    while (!Q.empty()) {
        int ind = Q.front(); Q.pop();
        if (a[ind] > 0) {
            ans += a[ind];
            res[lef++] = ind;
            if (b[ind] != -1) {
                a[b[ind]] += a[ind];
                if (--in[b[ind]] == 0)
                    Q.push(b[ind]);
            }
        } else {
            ans += a[ind];
            res[rig--] = ind;
            if (b[ind] != -1)
                if (--in[b[ind]] == 0)
                    Q.push(b[ind]);
        }
    }
    printf("%I64d\n", ans);
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}