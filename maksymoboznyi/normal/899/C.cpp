#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define M 1000000007;
using namespace std;
const int N = 2e5+6;
int n;
vector<int> a;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    if (n % 4 == 0)
    {
        for (int i = 1; i <= n; i++)
            if (a.size() < n/2)
            {
                a.pb(i);
                a.pb(n-i+1);
            }
    }
    if (n % 4 == 2)
    {
        int i = 1;
        for (i = 1; i < n/2; i++)
            if (i % 2 == 1)
                a.pb(i), a.pb(n-i+1);
        a.pb(i+1);
    }

    if (n % 4 == 1)
    {
        for (int i = 1; i <= n/2; i++)
            if (i % 2 == 0)
                a.pb(i), a.pb(n-i+2);
    }

    if (n % 4 == 3)
    {
        for (int i = 1; i < n/2; i++)
            if (i % 2 == 0)
                a.pb(i), a.pb(n-i+2);
        a.pb(n/2+2);
    }
    int sum = n*(n+1)/2;
    for (int i = 0; i < a.size(); i++)
        sum -= 2*a[i];
    cout << abs(sum) << endl;
    cout << a.size() << ' ';
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    return 0;
}