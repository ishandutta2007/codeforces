#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
int a[Maxn], b[Maxn];
multiset <int> S;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        S.insert(b[i]);
    }
    for (int i = 0; i < n; i++) {
        int nd = (n - a[i]) % n;
        multiset <int>::iterator it = S.lower_bound(nd);
        if (it == S.end()) it = S.begin();
        printf("%d%c", (a[i] + *it) % n, i + 1 < n? ' ': '\n');
        S.erase(it);
    }
    return 0;
}