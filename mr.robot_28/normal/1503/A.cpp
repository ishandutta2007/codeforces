#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long

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
        string s;
        cin >> s;
        int bal1 = 0, bal2 = 0;
        int cnt = 0;
        bool fl = 1;
        string a = "";
        string b = "";
        for(int i = 0; i < sz(s); i++)
        {
            if(s[i] == '1')
            {
                a += '(';
                b += '(';
                cnt++;
                bal1++;
                bal2++;
            }
            else if(bal1 > bal2)
            {
                a += ')';
                b += '(';
                bal1--;
                bal2++;
            }
            else
            {
                a += '(';
                b += ')';
                bal1++;
                bal2--;
            }
            if(bal1 < 0 || bal2 < 0)
            {
                fl = 0;
                break;
            }
        }
        if(fl && bal1 != bal2)
        {
            fl = 0;
        }
        if(!fl)
        {
            cout << "NO\n";
            continue;
        }
        int allbal = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(a[i] == '(' && b[i] == '(' && bal1 > 0)
            {
                bal1 -= 2;
                a[i] = ')';
                b[i] = ')';
            }
        }
        if(bal1 != 0)
        {
            cout << "NO\n";
            continue;
        }
        int allbal1 = 0;
        for(int i = 0; i < n; i++)
        {
            allbal += a[i] == '(' ? 1 : -1;
            if(allbal < 0)
            {
                fl = 0;
            }
            allbal1 += b[i] == '(' ? 1 :-1;
            if(allbal1 < 0)
            {
                fl = 0;
            }
        }
        if(fl && allbal == 0 && allbal1 == 0)
        {
            cout << "YES\n";
            cout << a << "\n";
            cout << b << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}