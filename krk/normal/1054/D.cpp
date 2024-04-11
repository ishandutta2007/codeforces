#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int all;
int n, k;
int cur;
map <int, int> M;
ll res;

int main()
{
    scanf("%d %d", &n, &k);
    all = (1 << k) - 1;
    M[cur]++;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        cur ^= a;
        int oth = (cur ^ all);
        M[min(cur, oth)]++;
    }
    res += ll(n) * (n + 1) / 2;
    for (map <int, int>::iterator it = M.begin(); it != M.end(); it++) {
        int a = it->second / 2;
        int b = it->second - a;
        res -= ll(a) * (a - 1) / 2;
        res -= ll(b) * (b - 1) / 2;
    }
    printf("%I64d\n", res);
    return 0;
}