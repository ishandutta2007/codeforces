#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 3005;

int T;
int n, k;
int a[Maxn];
int cur[Maxn];
set <ii> S;
int res;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        S.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            cur[i] = 1;
            S.insert(ii(a[i] / cur[i], i));
        }
        res = Maxn;
        while (!S.empty()) {
            res = min(res, S.rbegin()->first - S.begin()->first);
            auto it = S.end(); it--;
            int ind = it->second; S.erase(it);
            if (cur[ind] == k) break;
            cur[ind]++;
            S.insert(ii(a[ind] / cur[ind], ind));
        }
        printf("%d\n", res);
    }
    return 0;
}