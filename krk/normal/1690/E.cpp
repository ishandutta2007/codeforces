#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n, k;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        set <ii> S;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            S.insert(ii(a[i] % k, i));
        }
        ll res = 0;
        while (!S.empty()) {
            ii p = *S.begin(); S.erase(S.begin());
            auto it = S.lower_bound(ii(k - p.first, 0));
            if (it == S.end()) it = S.begin();
            res += ((a[p.second] + a[it->second]) / k);
            S.erase(it);
        }
        printf("%I64d\n", res);
    }
    return 0;
}