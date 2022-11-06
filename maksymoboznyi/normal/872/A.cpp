#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int n, m, min1 = 10, min2 = 10, kol[10], kol1[10];

signed main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        kol[a]++;
        min1 = min(min1, a);
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        kol1[a]++;
        min2 = min(min2, a);
    }
    for (int i = 1; i <= 9; i++)
    if (kol[i] && kol1[i])
    {
        cout << i;
        return 0;
    }
    if (min1 > min2)
        swap(min1, min2);
    if (min1 == min2)
        cout << min1;
    else
        cout << min1*10+min2;
    return 0;
}