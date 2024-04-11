#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
#define int long long
using namespace std;

signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
        cout << (n / 2) * 6 << "\n";
        for(int i = 0; i < n; i += 2)
        {
            cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
            cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
            cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
            cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
            cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
            cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
        }
    }
    return 0;
}