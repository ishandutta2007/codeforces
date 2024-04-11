#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n;
int a[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        res += a[i] * a[i];
    }
    sort(a, a + n);
    int mn = 1000000000;
    int l = 0, r = n - 1;
    while (l < r) {
        mn = min(mn, a[l] + a[r]);
        res += 2 * a[l] * a[r];
        l++; r--;
    }
    if (l == r) res += 2 * a[l] * mn;
    cout << res << endl;
    return 0;
}