#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
map<string , int> mp[maxn];
ll ans = 1e18 , res = 0;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        s += s;
        for(int j = 0; j <= s.size() / 2; j++)
        {
            string s1 = s.substr(j , s.size() / 2);
            if(mp[i].find(s1) == mp[i].end())
                mp[i][s1] = j;
        }
    }
    for(auto s : mp[0])
    {
        res = 0;
        for(int i = 0; i < n; i++)
        {
            if(mp[i].find(s.first) == mp[i].end())
                res = 1e18;
            else
                res += mp[i][s.first];
        }
        ans = min(ans , res);
    }
    if(ans >= 1e18)
    {
        cout << -1;
        return 0;
    }
    cout << ans;
}