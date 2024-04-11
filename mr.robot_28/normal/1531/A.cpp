#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;

signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    bool fl = 0;
    string ans = "blue";
    while(n--)
    {
        string s;
        cin >> s;
        if(s == "lock")
        {
            fl = 1;
        }
        else if(s == "unlock")
        {
            fl = 0;
        }
        else if(!fl)
        {
            ans = s;
        }
    }
    cout << ans;
    return 0;
}