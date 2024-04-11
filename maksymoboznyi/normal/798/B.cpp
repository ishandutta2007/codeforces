#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
void sdv(string &s)
{
    char c = s[0];
    for (int i = 0; i < s.size() -1; i++)
        s[i] = s[i+1];
    s[s.size()-1] = c;
}
int main()
{
    string s[51], ss[51];
    int n, ans = 1000000000, a = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        ss[i] = s[i];
    }
    for (int j =0; j < s[0].size(); j++)
    {
        a = 0;
        for (int i = 0; i < j; i++)
        {
            sdv(s[0]);
            a++;
        }
        bool r = false, rr = false;
        //cout << s[0] << endl;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[0])
            {
                continue;
            }
            for (int k = 0; k < s[0].size(); k++)
            {
                sdv(s[i]);
                a++;
                if (s[i] == s[0])
                {
                    //cout << s[0] << ' ' << s[i] << endl;
                    r = true;
                    break;
                }
            }
          //  cout <<s[i] << ' ' << r << ' ' ;
            if (!r)
            {
                rr = true;
                break;
            }
        }
        if (!rr)
            ans = min(ans, a);
        //cout <<ans << endl;
        for (int i = 0;i < n; i++)
        {
            //cout << s[i] << endl;
            s[i] = ss[i];
        }
    }
    if (ans == 1000000000)
        cout << -1;
    else
    cout << ans;
    return 0;
}