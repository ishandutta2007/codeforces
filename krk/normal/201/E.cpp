#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, m;

bool Check(int n, int m, int b)
{
    if (b < 30 && (1 << b) < n) return false;
    n--;
    ll lst = 1;
    for (int i = 1; i <= b; i++) {
        if (lst <= m) {
            ll all = lst * ll(b) / i;
            if (all >= n) return true;
            else n -= all;
            m -= lst;
        } else {
            ll got = ll(m) * b / i;
            return got >= n;
        }
        lst = lst * ll(b - i) / i;
    }
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        if (n == 1) { printf("0\n"); continue; }
        if (m == 1) { printf("%d\n", n - 1); continue; }
        int lef = 1, rig = n - 1;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Check(n, m, mid)) rig = mid - 1;
            else lef = mid + 1;
        } 
        printf("%d\n", lef);
    }
    return 0;
}