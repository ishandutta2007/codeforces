#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == a[i - 1]) continue;
        if (a[i - 1] < a[i]) res += ll(a[i] - a[i - 1]) * ll(n - a[i] + 1);
        else if (a[i - 1] > a[i]) res += ll(a[i]) * (a[i - 1] - a[i]);
    }
    cout << res << endl;
    return 0;
}