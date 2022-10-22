#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int q;
int n, r;
int a[Maxn];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &n, &r);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        ll sub = 0;
        int res = 0;
        for (int i = n - 1; i >= 0; i--)
            if (a[i] - sub > 0) {
                sub += r;
                res++;
                int j = i - 1;
                while (j >= 0 && a[i] == a[j]) j--;
                i = j + 1;
            } else break;
        printf("%d\n", res);
    }
    return 0;
}