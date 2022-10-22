#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n;
ll W;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %I64d", &n, &W);
        ll nd = (W + 1) / 2;
        ll cur = 0;
        vector <int> res;
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            if (a > W || cur >= nd) continue;
            if (a >= nd) {
                cur = a;
                res.clear();
                res.push_back(i);
                continue;
            }
            cur += a;
            res.push_back(i);
        }
        if (cur < nd) printf("-1\n");
        else {
            printf("%d\n", int(res.size()));
            for (int i = 0; i < res.size(); i++)
                printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
        }
    }
    return 0;
}