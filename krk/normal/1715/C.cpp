#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m;
int a[Maxn];
ll cur;

ll Get(int ind)
{
    ll ways = n - ind;
    if (ind > 0 && a[ind - 1] != a[ind])
        ways += ll(ind) * (n - ind);
    return ways;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cur += Get(i);
    }
    while (m--) {
        int ind, val;
        scanf("%d %d", &ind, &val);
        ind--;
        cur -= Get(ind);
        if (ind + 1 < n) cur -= Get(ind + 1);
        a[ind] = val;
        cur += Get(ind);
        if (ind + 1 < n) cur += Get(ind + 1);
        printf("%I64d\n", cur);
    }
    return 0;
}