#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100100;

int n, a[maxn], lt[maxn], rt[maxn];

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];

    for (int i=0; i<=n+1; i++)
        if (a[i] == 0)
            lt[i] = rt[i] = 0;

    for (int i=1; i<=n; i++)
        lt[i] = min(a[i], lt[i-1]+1);

    for (int i=n; i>=1; i--)
        rt[i] = min(a[i], rt[i+1]+1);

    int ans = 0;
    for (int i=1; i<=n; i++)
        ans = max(ans, min(lt[i], rt[i]));
    cout << ans << '\n';
}