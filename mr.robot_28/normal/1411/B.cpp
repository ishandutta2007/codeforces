#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;

void update(string &s)
{
    int j = s.size() - 1;
    while(j >= 0 && s[j] == '9')
    {
        s[j] = '0';
        j--;
    }
    if(j == -1)
    {
        s.insert(s.begin(), '1');
    }
    else
    {
        s[j]++;
    }
}
bool divide(string s, int a)
{
    int sum = 0;
    for(int j = 0; j < s.size(); j++)
    {
        sum = (sum * 10 + s[j] - '0');
        sum = sum % a;
    }
    return sum == 0;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        while(true)
        {
            vector <bool> used(10);
            for(int j = 0; j < s.size(); j++)
            {
                used[s[j] - '0'] = 1;
            }
            bool fl = 1;
            for(int j = 1; j < 10; j++)
            {
                if(used[j] && !divide(s, j))
                {
                    fl = 0;
                    break;
                }
            }
            if(fl)
            {
                cout << s << "\n";
                break;
            }
            update(s);
        }
    }
    return 0;
}