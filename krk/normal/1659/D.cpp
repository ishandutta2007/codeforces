#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int c[Maxn];
ll sum;
int delt[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &c[i]);
            sum += c[i];
        }
        sum /= n;
        fill(delt, delt + n, 0);
        int cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur += delt[i];
            res[i] = c[i] - cur == i + 1;
            cur++;
            if (i - sum >= 0)
                delt[i - sum]--;
            if (res[i]) sum--;
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}