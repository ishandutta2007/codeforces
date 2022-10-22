#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 505;

int n;
ll a[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        res = max(res, a[i]);
        for (int j = i - 1; j >= 0; j--) {
            ll cand = (a[i] | a[j]);
            res = max(res, cand);
            for (int k = j - 1; k >= 0; k--) {
                ll cand2 = (cand | a[k]);
                res = max(res, cand2);
            }
        }
    }
    printf("%I64d\n", res);
    return 0;
}