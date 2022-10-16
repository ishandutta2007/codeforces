#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 7005;

int n;

LL a[N], ans;

bool st[N];

int b[N]; 

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", b + i);
    for (int i = 1; i <= n; i++) {
        int c1 = 0, c2 = 0;
        LL s = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] == a[i]) c1++;
        }
        if (c1 > 1) st[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        bool o = st[i];
        for (int j = 1; j <= n; j++) {
            if ((a[i] | a[j]) == a[j] && st[j]) o = 1;
        }
        if (o) ans += b[i];
    }
    printf("%lld\n", ans);
    return 0;
}