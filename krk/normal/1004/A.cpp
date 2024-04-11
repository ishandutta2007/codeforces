#include <bits/stdc++.h>
using namespace std;

const int Inf = 2000000005;
const int Maxn = 105;

int a[Maxn];
int n, d;
set <int> S;

int main()
{
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        S.insert(a[i] - d);
        S.insert(a[i] + d);
    }
    int res = 0;
    for (auto p: S) {
        int mn = Inf;
        for (int i = 0; i < n; i++)
            mn = min(mn, abs(a[i] - p));
        res += mn == d;
    }
    cout << res << endl;
    return 0;
}