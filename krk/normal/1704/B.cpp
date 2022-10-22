#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, x;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int res = -1;
        for (int i = 0, j; i < n; i = j) {
            res++;
            j = i + 1;
            int L = a[i] - x, R = a[i] + x;
            while (j < n && max(L, a[j] - x) <= min(R, a[j] + x)) {
                L = max(L, a[j] - x);
                R = min(R, a[j] + x);
                j++;
            }
        }
        printf("%d\n", res);
    }
    return 0; 
}