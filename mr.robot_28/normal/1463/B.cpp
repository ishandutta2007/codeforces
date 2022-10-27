#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;

signed main()
{
 //   ifstream cin("input1.txt.4c");
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
        int t = 1;
        for(int i = 0; i < n; i++)
        {
            while(t * 2 <= a[i])
            {
                t *= 2;
            }
            while(t > a[i])
            {
                t /= 2;
            }
            cout << t << " ";
        }
        cout << "\n";
    }
    return 0;
}