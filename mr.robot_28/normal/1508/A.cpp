#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
const int mod = 998244353;
string funct(string a, string b, int t)
{
    int n = sz(a) / 2;
    int j = 0;
    string res = "";
    //cout << a << " " << b << " " << t << "\n";
    for(int i = 0; i < n * 2; i++)
    {
        if(a[i] - '0' != t)
        {
            res += a[i];
        }
        else
        {
            while(j < n * 2 && b[j] - '0' != t)
            {
                res += b[j];
                j++;
            }
            res += a[i];
            j++;
        }
    }
    while(j < n * 2)
    {
        res += b[j];
        j++;
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string a, b, c;
        cin >> a >> b >> c;
        int bal1 = 0, bal2 = 0, bal3 = 0;
        for(int i = 0; i < n * 2; i++)
        {
            bal1 += (a[i] == '1' ? 1 : -1);
            bal2 += (b[i] == '1' ? 1 : -1);
            bal3 += (c[i] == '1' ? 1 : -1);
        }
       // cout << bal1 << " " << bal2 << " " << bal3 << " ";
        string res = "";
        if(bal1 * bal2 >= 0)
        {
            if(min(bal1, bal2) >= 0)
            {
                res = funct(a, b, 1);
            }
            else
            {
                res = funct(a, b, 0);
            }
        }
        else if(bal1 * bal3 >= 0)
        {
            if(min(bal1, bal3)  >= 0)
            {
                res = funct(a, c, 1);
            }
            else
            {
                res = funct(a, c, 0);
            }
        }
        else
        {
            if(min(bal2, bal3) >= 0)
            {
                res = funct(b, c, 1);
            }
            else
            {
                res = funct(b, c, 0);
            }
        }
        cout << res << "\n";
    }
    return 0;
}