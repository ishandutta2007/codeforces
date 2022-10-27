#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
#define int long long
using namespace std;

signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != '0')
            {
                continue;
            }
            int j = i;
            while(j < n && s[j] == '0')
            {
                j++;
            }
            if(j == n && i == 0)
            {
                break;
            }
            if(i == 0)
            {
                for(int t = 0; t < min(j, m); t++)
                {
                    s[j - t - 1] = '1';
                }
            }
            else if(j == n)
            {
                for(int t = 0; t < min(n - i, m); t++)
                {
                    s[t + i] = '1';
                }
            }
            else
            {
                for(int t = 0; t < min((j - i) / 2, m); t++)
                {
                    if(i + t == j - 1 - t)
                    {
                        break;
                    }
                    s[i + t] = s[j - 1 - t] = '1';
                }
            }
            i = j - 1;
        }
        cout << s << "\n";
    }
    return 0;
}