#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long

using namespace std;

const int N = 1e5+5;
const ll inf = 2e18;
int n, a[N], b[N];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    int po=0, p = a[1], q = a[n], x = 0, y = 0;
    if (q-p == 2)
    {
        po = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == q-1)
                po++;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] == p)
            x++;
        else
            if (a[i] == q)
                y++;
    int z = min(x, y), ans = 0;
    if (2*z >= po && p != q) {
    for (int i = 1; i <= z; i++)
        ans++, a[i] = p+1;
    for (int i = n; n-i+1 <= z; i--)
        ans ++, a[i] = q-1;}
    else
    {
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == q-1 && c1 < po/2)
                a[i] = q, c1++;
        for (int i = 1; i <= n; i++)
            if (a[i] == q-1 && c2 < po/2)
                a[i] = p, c2++;
    }
    ans = 0;
    sort(a+1, a+n+1);
    for (int i  = 1; i <= n; i++)
        if (a[i] == b[i])
        ans++;
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';

    return 0;
}