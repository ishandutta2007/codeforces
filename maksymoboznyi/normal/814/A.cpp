#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int n, k, a[101], b[101], pos = -1;
vector<int> x;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 0)
            x.pb(a[i]);
    }
    for (int i = 1; i < int(x.size()); i++)
        if (x[i] <= x[i-1])
        {
            cout << "Yes";
            return 0;
        }
    for (int i = 1; i <= k; i++)
        cin >> b[i];
    if (k != 1)
    {
        cout << "Yes";
        return 0;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] == 0)
        {
            if (i == 1 && a[2] > b[1])
            {
                cout << "No";
                return 0;
            }else
            {
                if (i == n && a[n-1] < b[1])
                {
                    cout << "No";
                    return 0;
                }else
                {
                    if (a[i-1] < b[1] && b[1] < a[i+1])
                    {
                        cout << "No";
                        return 0;
                    }
                }
            }

        }
    cout << "Yes";
    return 0;
}