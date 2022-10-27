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
        int k;
        cin >> k;
        int t = __gcd(k, 100);
        int a = 100;
        k /= t;
        a /= t;
        cout << a<< "\n";
    }
    return 0;
}