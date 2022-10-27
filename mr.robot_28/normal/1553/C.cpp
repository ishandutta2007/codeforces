#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long
using namespace std;
int funct(string a)
{
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < sz(a); i++)
    {
        if(i % 2 == 0)
        {
            if(a[i] == '1')
            {
                cnt1++;
            }
            if(cnt2 + (sz(a) - i) / 2 < cnt1)
            {
                return i + 1;
            }
            if(cnt1 + (sz(a) - i - 1) / 2 < cnt2)
            {
                return i + 1;
            }
        }
        else
        {
            if(a[i] == '1')
            {
                cnt2++;
            }
            if(cnt1 + (sz(a) -  i) / 2 < cnt2)
            {
                return i + 1;
            }
            if(cnt2 + (sz(a) - i) / 2 < cnt1)
            {
                return i + 1;
            }
        }
    }
    return sz(a);
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        string s1 = "", s2 = "";
        for(int i = 0; i < sz(s); i++)
        {
            if(s[i] == '?')
            {
                if(i & 1)
                {
                    s1 += '1';
                    s2 += '0';
                }
                else
                {
                    s1 += '0';
                    s2 += '1';
                }
            }
            else
            {
                s1 += s[i];
                s2 += s[i];
            }
        }
        cout << min(funct(s1), funct(s2)) << "\n";
    }
    return 0;
}