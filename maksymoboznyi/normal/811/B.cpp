#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned ll
#define big 99999999999999999
#define small -big
using namespace std;
ll n, m, rr = 0, p[10005], l, r, x;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int o = 0; o < m; o++)
    {
        cin >> l >> r >> x;
        if (x < l || x > r)
        {
            cout << "No" << endl;
            continue;
        }
        rr = 0;
        for (int i = l; i <= r; i++)
            if (p[i] < p[x])
                rr++;
       // cout << rr << endl;
        if (rr == x - l)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}