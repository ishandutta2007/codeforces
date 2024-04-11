#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        vector <int> bal(n + 1);
        bal[0] = 0;
        for(int i = 0; i < n; i++)
        {
            bal[i + 1] = bal[i] + (s[i] == '1' ? 1 : -1);
        }
        int maxbal = 0;
        int minbal = n;
        for(int i = 0; i <= n; i++)
        {
            bal[i] += n;
            maxbal = max(maxbal ,bal[i]);
            minbal = min(minbal, bal[i]);
        }
        vector <int> cnt(2 * n + 1), cnt1(2 * n + 1);
        for(int i = 0; i <= n; i++)
        {
            cnt[bal[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            cnt1[min(bal[i], bal[i + 1])]++;
        }
        string ans = "";
        int st = bal[0];
        for(int i = 0; i < n; i++)
        {
            cnt[st]--;
            int up = st + 1 <= maxbal ? cnt[st + 1] : 0;
            int down = st - 1 >= minbal ? cnt[st - 1] : 0;
            if(!up || (down && cnt1[st - 1] >= 2))
            {
                cnt1[st - 1]--;
                ans += "0";
                st--;
            }
            else
            {
                cnt1[st]--;
                ans += "1";
                st++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}