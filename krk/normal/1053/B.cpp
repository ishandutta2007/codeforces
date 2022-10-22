#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxt = 66;

int n;
int a[Maxn];
int sum[Maxn];
int odd[Maxn], even[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll x; scanf("%I64d", &x);
        a[i] = __builtin_popcountll(x);
        sum[i + 1] = (sum[i] + a[i]) % 2;
    }
    for (int i = n; i >= 0; i--) {
        odd[i] = odd[i + 1] + (sum[i] % 2 == 1);
        even[i] = even[i + 1] + (sum[i] % 2 == 0);
    }
    for (int i = 0; i < n; i++) {
        int mysum = 0, mymx = 0;
        for (int j = i; j < n && j - i < Maxt; j++) {
            mysum += a[j];
            mymx = max(mymx, a[j]);
            if (mymx <= mysum - mymx && mysum % 2 == 0)
                res++;
        }
        int ind = i + Maxt + 1;
        if (ind <= n)
            if (sum[i] == 0) res += even[ind];
            else res += odd[ind];
    }
    printf("%I64d\n", res);
    return 0;
}