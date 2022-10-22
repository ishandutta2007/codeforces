#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 30;

int T;
int n;
int cnt[Maxb];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll res = 0;
        fill(cnt, cnt + Maxb, 0);
        for (int i = 0; i < n; i++) {
            int num; scanf("%d", &num);
            int b = Maxb - 1;
            while (!(num & 1 << b)) b--;
            res += cnt[b]++;
        }
        printf("%I64d\n", res);
    }
    return 0;
}