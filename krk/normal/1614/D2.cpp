#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 20000005;

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
        sum[i] = 0;
        cnt[i] = orig[i];
        for (int j = i + i; j < Maxn; j += i) if (cnt[j]) {
            cnt[i] += orig[j];
            sum[i] = max(sum[i], sum[j] - ll(i) * cnt[j]);
        }
        sum[i] += ll(i) * cnt[i];
        res = max(res, sum[i]);
    }
    cout << res << endl;
    return 0;
}