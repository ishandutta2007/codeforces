#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 100;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int s = 0;
        if(n == 1)
        {
            s += a[0];
            a[0] = 0;
        }
        if(n > 1)
        {
            if(a[0] > a[1])
            {
                s += a[0] - a[1];
                a[0] = a[1];
            }
            if(a[n - 1] > a[n - 2])
            {
                s += a[n - 1] - a[n - 2];
                a[n - 1] = a[n - 2];
            }
        }
        for(int i = 1; i < n - 1; i++)
        {
            if(a[i] > max(a[i - 1], a[i + 1]))
            {
                s += a[i] - max(a[i - 1], a[i + 1]);
                a[i] = max(a[i - 1], a[i + 1]);
            }
        }
        s += a[0] + a[n - 1];
        for(int i = 1; i < n; i++)
        {
            s += abs(a[i] - a[i - 1]);
        }
        cout << s << "\n";
    }
    return 0;
}