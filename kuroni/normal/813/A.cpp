#include <bits/stdc++.h>
using namespace std;

int n, l, r, u, tim = 0, ans = 1E9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--)
    {
        cin >> u;
        tim += u;
    }
    cin >> n;
    while (n--)
    {
        cin >> l >> r;
        if (r >= tim)
            ans = min(ans, max(l, tim));
    }
    cout << (ans == 1E9 ? -1 : ans);
}