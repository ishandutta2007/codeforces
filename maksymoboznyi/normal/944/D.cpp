#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long

using namespace std;

const int N = 1e5+5;
const ll inf = 2e18;

string s;
vector<string> start[30];
int pos[26];
int can[N];
signed main()
{
    cin >> s;
    int n = s.size();
    if (n == 1)
    {
        cout << 1.00000000000;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        start[s[0]-'a'].pb(s);
        char t = s[0];
        for (int i = 0; i < int(s.size())-1; i++)
            s[i] = s[i+1];
        s[s.size()-1] = t;
    }
    for (int st = 0; st < 26; st++)
    if (start[st].size() != 0)
    {
        can[st] = 0;
        for (int num = 1; num < int(s.size()); num++)
        {
            int an = 0;
            for (int i = 0; i < 26; i++)
                    pos[i] = 0;
            for (int j = 0; j < int(start[st].size()); j++)
                pos[start[st][j][num] - 'a']++;
            int c = 0;
            for (int i = 0; i < 26; i++)
                if (pos[i] == 1)
                    c++;//cout << i << endl;
           can[st] = max(can[st] , c);
        }
        //cout << can[st] << ' ' << st  << endl;
    }
    double ans = 0;
    for (int st = 0; st < 26; st++)
        if (start[st].size()!=0)
        ans += start[st].size()*1.0/n*can[st]*1.0/start[st].size();
    cout << fixed << setprecision(6) << ans;
    return 0;
}