#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define big 9999999999
#define small -big
using namespace std;

int main()
{
    string s;
    int k;
    cin >>s >> k;
    int y = 0, ans = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0')
            y++;
    if (y < k)
    {
        if (y == 0)
            cout << s.size();
        else
            cout << s.size()-1;
    }
    else
    {
        int p = 0;
        for (int i = s.size()-1; i >= 0; i--)
        {
            if (s[i] == '0')
                p++;
            else ans++;
            if (p==k)
            {
                cout << ans;
                return 0;
            }
        }
    }
    return 0;
}