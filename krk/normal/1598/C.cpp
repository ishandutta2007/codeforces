#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll sum = 0ll;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sum *= 2;
        if (sum % n) { printf("0\n"); continue; }
        sum /= n;
        map <ll, int> M;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += M[sum - a[i]];
            M[a[i]]++;
        }
        printf("%I64d\n", res);
    }
    return 0;
}