#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5;

signed main()
{
//  ios_base::sync_with_stdio(0);
//  cin.tie(0);
//  cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int s;
        cin >> s;
        int n = 1;
        while(n * n < s)
        {
            n++;
        }
        cout << n << "\n";
    }
    return 0;
}