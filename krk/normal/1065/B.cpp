#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;

int main()
{
    scanf("%I64d %I64d", &n, &m);
    ll res1 = max(0ll, n - 2 * m);
    printf("%I64d ", res1);
    ll cur = 0;
    while (cur * (cur - 1) / 2 < m) cur++;
    cout << n - cur << endl;
    return 0;
}