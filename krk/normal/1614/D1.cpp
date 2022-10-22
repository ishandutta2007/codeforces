#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5000005;

int n;
int orig[Maxn], cnt[Maxn];
ll sum[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        orig[a]++;
    }
    for (int i = Maxn - 1; i > 0; i--) {
        for (int j = i; j < Maxn; j += i) cnt[i] += orig[j];
        if (cnt[i] == 0) continue;
        sum[i] = ll(i) * cnt[i];
        for (int j = i + i; j < Maxn; j += i)
            sum[i] = max(sum[i], sum[j] + ll(i) * (cnt[i] - cnt[j]));
        res = max(res, sum[i]);
    }
    cout << res << endl;
    return 0;
}