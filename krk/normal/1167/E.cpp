#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n, x;
int a[Maxn];
set <int> S;
int mx[Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= x; i++)
        mx[i] = i;
    int mn = x;
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        set <int>::iterator it = S.upper_bound(a);
        if (it != S.end()) {
            mx[1] = max(mx[1], a);
            auto oth = S.end(); oth--;
            mx[a + 1] = max(mx[a + 1], *oth);
            mn = min(mn, *it);
        }
        S.insert(a);
    }
    for (int i = 1; i <= mn; i++) {
        mx[i] = max(mx[i - 1], mx[i]);
        res += x - mx[i] + 1;
    }
    cout << res << endl;
    return 0;
}