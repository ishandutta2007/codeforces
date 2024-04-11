#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

const int Maxn = 100005;

int n;
ld a[Maxn];
int mn[Maxn], mx[Maxn];
ll sum;
int res[Maxn];

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int my = int(a[i]);
        if (fabs(my - a[i]) < 1e-9l)
            mn[i] = mx[i] = my;
        else if (my > a[i])
            mn[i] = my - 1, mx[i] = my;
        else mn[i] = my, mx[i] = my + 1;
        sum += mn[i];
        res[i] = mn[i];
    }
    for (int i = 0; i < n && sum != 0; i++) {
        sum += mx[i] - mn[i];
        res[i] = mx[i];
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", res[i]);
    return 0;
}