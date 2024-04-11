#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;

int n;
int a[N], used[N], kol[N];
char ans[N];

signed main()
{
    cin >> n;
    int c = 0;
    int can = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], kol[a[i]]++;
    //cout << kol[a[1]] << endl;
    for (int i = 1; i <= n; i++)
        if (kol[a[i]] == 1)
            used[i] = 1, c++;
        else
            if (kol[a[i]] != 2)
                used[i] = 2, can = i;
    //cout << ca
    if (c % 2 != 0 && !can)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    if (c % 2 == 0)
    {
        int c1 = 0;
        for (int i = 1; i <= n; i++)
            if (kol[a[i]] == 1 && c1 < c / 2)
                ans[i] = 'A', c1++;
            else
                ans[i] = 'B';
    }else
    {
        //cout << can << endl;
        ans[can] = 'A';
        c++;
        int c1 = 1;
        for (int i = 1; i <= n; i++)
            if (i != can)
            if (kol[a[i]] == 1 && c1 < c / 2)
                ans[i] = 'A', c1++;
            else
                ans[i] = 'B';
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i];
    return 0;
}