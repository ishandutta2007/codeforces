#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, a, b, k;
ll res;

int main()
{
    scanf("%d %d %d %d %d", &t, &n, &a, &b, &k);
    if (k > n) { printf("0\n"); return 0; }
    int A = (n + 1) / 2, B = n / 2;
    if (a > b) { swap(a, b); swap(A, B); }
    res = (ll(a) * A + ll(b) * B) / k;
    if (k > B)
        res = min(res, ll(a) * A / (k - B));
    res = min(res, ll(t));
    cout << res << endl;
    return 0;
}