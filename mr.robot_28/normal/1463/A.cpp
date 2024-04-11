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
        int a, b, c;
        cin >> a >> b >> c;
        int s = a + b + c;
        if(s % 9 != 0)
        {
            cout << "NO\n";
            continue;
        }
        int k = s / 9;
        if(k > a || k > b || k > c)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}