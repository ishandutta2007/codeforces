#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 4e6+5;
ll x[N], y[N], kol[N], n;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        kol[x[i]]++;
    }
    for (int j = 1; j <= n; j++)
    {
        cin >> y[j];
        kol[y[j]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (kol[(x[i]^y[j])] > 0)
                ans++;
    if (ans % 2 == 0)
        cout << "Karen";
    else
        cout << "Koyomi";
    return 0;
}