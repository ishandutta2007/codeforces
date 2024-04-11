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
    ll ans = 0;
    map <int, int> mp;
    map <pair <int, int>, int> mp1;
    while(n--)
    {
        int w, h;
        cin >> w >> h;
        if(w == h)
        {
            ans += mp[w];
        }
        else
        {
            ans += mp[w] + mp[h] - mp1[{w, h}] - mp1[{h, w}];
        }
        mp[w]++;
        if(h != w)
        {
            mp[h]++;
        }
        mp1[{w, h}]++;
        //cout << ans << "\n";
    }
    cout << ans;
    return 0;
}