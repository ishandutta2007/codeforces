#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 1e5+5;
const long long inf = 2e18;

string s;
bool pal(string t)
{
    int n = t.size();
    for (int i = 0; i < n; i++)
        if (t[i] != t[n-1-i])
            return 0;
    return 1;
}

signed main()
{
    cin >> s;
    int ans = 0;
    for (int l = 0; l < s.size(); l++)
        for (int r = l; r < s.size(); r++)
        {
            string s1 = "";
            for (int i = l; i <= r; i++)
                s1 += s[i];
            if (!pal(s1))
                ans = max(ans, int(s1.size()));
        }
    cout << ans;
    return 0;
}