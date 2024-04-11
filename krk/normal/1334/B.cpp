#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, x;
vector <int> a;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        a.resize(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a.rbegin(), a.rend());
        ll sum = 0;
        int pnt = 0;
        while (pnt < n && sum + a[pnt] >= ll(pnt + 1) * x)
            sum += a[pnt++];
        printf("%d\n", pnt);
    }
    return 0;
}