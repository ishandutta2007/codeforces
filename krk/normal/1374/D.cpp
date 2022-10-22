#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, k;
map <int, int> M;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        ll res = 0;
        M.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (a % k) M[k - a % k]++;
        }
        for (auto it: M)
            res = max(res, ll(it.second - 1) * k + it.first + 1);
        printf("%I64d\n", res);
    }
    return 0;
}