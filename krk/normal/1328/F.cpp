#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 200005;

int n, k;
int a[Maxn];
ll L[Maxn], R[Maxn];
ll res = Inf;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    L[0] = 0;
    for (int i = 1; i < n; i++)
        L[i] = L[i - 1] + ll(i) * (a[i] - a[i - 1]);
    R[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
        R[i] = R[i + 1] + ll(n - 1 - i) * (a[i + 1] - a[i]);
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && a[i] == a[j]) j++;
        if (j - i >= k) res = 0;
        if (j >= k && i > 0) {
            ll cand = ll(i) * (a[i] - a[i - 1] - 1) + L[i - 1];
            if (j - i < k) cand += k - (j - i);
            res = min(res, cand);
        }
        if (n - i >= k && j < n) {
            ll cand = ll(n - j) * (a[j] - a[j - 1] - 1) + R[j];
            if (j - i < k) cand += k - (j - i);
            res = min(res, cand);
        }
        if (i > 0 && j < n) {
            ll cand = ll(i) * (a[i] - a[i - 1] - 1) + L[i - 1] + ll(n - j) * (a[j] - a[j - 1] - 1) + R[j];
            if (j - i < k) cand += k - (j - i);
            res = min(res, cand);
        }
    }
    cout << res << endl;
    return 0;
}