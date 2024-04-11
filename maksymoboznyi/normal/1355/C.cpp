#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
using namespace std;

const int N = 2e5 + 5;

int n, a[N], ans = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c, d, ans = 0;
    cin >> a >> b >> c >> d;
    for (int z = c; z <= d; z++) {
        int p1 = z - b + 1, p2 = z - c;
        int lval, rval;
        if (p1 <= b)
            lval = c - b, ans += (b - max(p1, a) + 1) * (c - b + 1);
        else
            lval = c - (z - b);

        if (p2 >= a)
            rval = 0;
        else
            rval = c - (z - a);
        if (lval < rval)
            continue;
        ans += (lval + 1) * lval / 2 - (rval - 1) * rval / 2;
    }
    cout << ans;
    return 0;
}