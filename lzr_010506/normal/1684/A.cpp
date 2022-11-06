#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int T;
    cin >> T;
    while(T --)
    {
        cin >> s;
        int ans = 9;
        if(s.size() == 2) cout << s[1] << "\n";
        else 
        {
            for(int i = 0; i < s.size(); i ++)
                ans = min(ans, s[i] - '0');
            cout << ans << "\n";
        }
    }

}