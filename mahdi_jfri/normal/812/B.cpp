#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll res , ans = 1e18 , n , m;
string s[maxn];
void bt(int i , int k)
{
    if(i == n - 1)
    {
        ll x = 0;
        if(k == 0)
            for(int j = 0; j < m + 2; j++)
                if(s[i][j] == '1')
                    x = j;
        if(k == 1)
            for(int j = m + 1; j > -1; j--)
                if(s[i][j] == '1')
                    x = (m + 1 - j);
        ans = min(ans , res + x);
        return;
    }
    ll x = 0;
    if(k == 0)
        for(int j = 0; j < m + 2; j++)
            if(s[i][j] == '1')
                x = j;
    if(k == 1)
        for(int j = m + 1; j > -1; j--)
            if(s[i][j] == '1')
                x = (m + 1 - j);
    res += x * 2;
    bt(i + 1 , k);
    res -= x * 2;
    res += m + 1;
    bt(i + 1 , 1 - k);
    res -= m + 1;
}
int main()
{
    cin >> n >> m;
    for(int i = n - 1; i > -1; i--)
        cin >> s[i];
    ll k = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i].find("1") != string::npos)
            k = i;
    }
    n = k + 1;
    bt(0 , 0);
    cout << ans + n - 1 << endl;
}