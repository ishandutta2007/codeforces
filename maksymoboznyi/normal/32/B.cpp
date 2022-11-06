#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;


int main()
{
    vector<int> ans;
    ans.clear();
    string s;
    cin >> s;
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == '.')
        {
            ans.pb(0);
            i++;
        }else
            if (s[i] == '-')
            {
                if (s[i+1] == '.')
                    ans.pb(1);
                else
                    ans.pb(2);
                i+=2;
            }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
    return 0;
}