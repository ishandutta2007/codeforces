#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 2000000000;
const int Maxm = 10000005;
const int Maxn = 5005;

int n, k;
int a[Maxn];
bool has[Maxm];
int q;
int x;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); has[a[i]] = true;
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        int res = Inf;
        for (int i = 0; i < n; i++)
            for (int j = k - 1, sum = x - a[i]; j >= 0 && sum >= 0; j--, sum -= a[i])
                if (sum == 0) res = min(res, k - j);
                else for (int l = 1; l <= j; l++) {
                    int d = sum / l;
                    if (d * l == sum && d < Maxm && has[d]) res = min(res, (k - j) + l);
                }
        printf("%d\n", res == Inf? -1: res);
    }
    return 0;
}