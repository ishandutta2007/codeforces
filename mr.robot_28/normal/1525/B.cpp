#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;

signed main()
{
   // ifstream cin("rt.txt.txt");
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
        bool fl = 1;
        for(int i = 1; i < n; i++)
        {
            if(a[i] < a[i - 1])
            {
                fl = 0;
            }
        }
        if(fl)
        {
            cout << 0 << "\n";
        }
        else if(a[0] == 1 || a[n - 1] == n)
        {
            cout << 1 << "\n";
        }
        else if(a[0] == n && a[n - 1] == 1)
        {
            cout << 3 << "\n";
        }
        else
        {
            cout << 2 << "\n";
        }
    }
    return 0;
}