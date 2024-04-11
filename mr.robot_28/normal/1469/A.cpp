#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int bal = 0;
        int cnt = 0;
        int n = s.size();
        for(int i =0 ; i < n; i++)
        {
            if(s[i] == '(')
            {
                bal++;
            }
            else if(s[i] == ')')
            {
                bal--;
            }
            else
            {
                cnt++;
            }
        }
        int cnt1 = 0, cnt2 = 0;
        if(bal - cnt > 0 || bal + cnt < 0)
        {
            cout << "NO\n";
            continue;
        }
        if(bal < 0)
        {
            cnt1 += abs(bal);
        }
        else
        {
            cnt2 += bal;
        }
        cnt -= (cnt1 + cnt2);
        if(cnt % 2 != 0)
        {
            cout << "NO\n";
            continue;
        }
        bool fl = 1;
        cnt1 += cnt / 2;
        cnt2 += cnt / 2;
        bal = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '?')
            {
                if(cnt1 > 0)
                {
                    cnt1--;
                    s[i] = '(';
                }
                else
                {
                    s[i] = ')';
                }
            }
            if(s[i] == '(')
            {
                bal++;
            }
            else
            {
                bal--;
            }
            if(bal < 0)
            {
                fl = 0;
            }
        }
        if(!fl)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}