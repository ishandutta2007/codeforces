#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
const int mod = 1e9 + 7;
const int N = 2e5+ 100;


signed main()
{
  //  ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int t = sqrt(n / 2);
        if(n % 2 == 0 && t * t == n / 2)
        {
            cout << "YES\n";
        }
        else
        {
            int t = sqrt(n / 4);
            if(n % 4 == 0 && t * t == n / 4)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}