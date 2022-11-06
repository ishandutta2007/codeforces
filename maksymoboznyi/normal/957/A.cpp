#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 2e5+5;
const long long inf = 2e18;

int n;
char a[N];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i != 1 && a[i] != '?' && a[i-1] == a[i])
        {
            cout << "No";
            return 0;
        }
    }
    if (a[1] == '?' || a[n] == '?')
    {
        cout << "Yes";
        return 0;
    }
    bool r = 0;
    for (int i = 2; i < n; i++)
        if (a[i] == '?')
            if ((a[i-1] == '?' || a[i+1] == '?' || (a[i-1] == a[i+1])))
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}