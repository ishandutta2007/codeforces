#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn], b[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    int lsta = -1, lstb = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        int mx = lsta == lstb? lsta + 1: max(lsta, lstb);
        int mn = min(a[i], b[i]);
        if (mx <= mn) res += mn - mx + 1;
        lsta = a[i], lstb = b[i];
    }
    cout << res << endl;
    return 0;
}