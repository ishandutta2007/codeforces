#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, m;
int a[Maxn], b[Maxn];
multiset <ii> A;

bool Works(int x)
{
    if (x == n) return false;
    multiset <ii> B = A;
    for (int i = 0; i < m; i++) {
        int na = (a[i] + x) % n;
        int nb = (b[i] + x) % n;
        if (na > nb) swap(na, nb);
        multiset <ii>::iterator it = B.find(ii(na, nb));
        if (it == B.end()) return false;
        B.erase(it);
    }
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]); a[i]--; b[i]--;
        if (a[i] > b[i]) swap(a[i], b[i]);
        A.insert(ii(a[i], b[i]));
    }
    for (int i = 1; i * i <= n; i++) if (n % i == 0) {
        if (Works(i)) { printf("Yes\n"); return 0; }
        if (Works(n / i)) { printf("Yes\n"); return 0; }
    }
    printf("No\n");
    return 0;
}