#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int l = 0, r = n - 1;
        while (l <= r && a[l] == 0) l++;
        while (l <= r && a[r] == 0) r--;
        if (l > r) { printf("0\n"); continue; }
        bool was = false;
        for (int i = l; i <= r; i++)
            if (a[i] == 0) was = true;
        printf("%d\n", was? 2: 1);
    }
    return 0;
}