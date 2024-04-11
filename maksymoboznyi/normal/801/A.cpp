#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
using namespace std;

int main()
{
    string s;
    int ans = 0;
    bool r = false;
    cin >> s;
    for (int i = 0; i < int(s.size()-1); i++)
        if (s[i] == 'V')
        {
            //cout << i << endl;
            if (s[i+1] == 'K')
              {
                 // cout <<"stojkg"<<endl;
                ans++;}
            else
                if (!r && (i == s.size()-2 || s[i+2] == 'V'))
                {
                   //cout << "sdgg"<<endl;
                    r = true;
                    s[i+1] == 'K';
                    ans++;
                }
        }else
        {
            if ((i == 0 || s[i-1] != 'V')&& !r && s[i+1] != 'V')
            {
                s[i] == 'V';
                r = true;
                ans++;
            }
        }
    cout << ans << endl;
    return 0;
}