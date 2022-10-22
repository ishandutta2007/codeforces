#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int cur = 2000000000;
    for (int i = n - 1; i >= 0; i--) {
        cur = min(cur - 1, a[i]);
        if (cur < 0) break;
        res += cur;
    }
    cout << res << endl;
    return 0;
}