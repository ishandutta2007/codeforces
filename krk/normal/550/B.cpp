#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 20;
const int Inf = 1000000000;

int n, l, r, x;
int c[Maxn];
int res;

int main()
{
    scanf("%d %d %d %d", &n, &l, &r, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i < 1 << n; i++) {
        int mn = Inf, mx = -Inf;
        int bits = 0;
        int sum = 0;
        for (int j = 0; j < n; j++)
            if (i & 1 << j) {
                mn = min(mn, c[j]);
                mx = max(mx, c[j]);
                bits++; sum += c[j];
            }
        if (bits >= 2 && l <= sum && sum <= r && mx - mn >= x)
            res++;
    }
    printf("%d\n", res);
    return 0;
}