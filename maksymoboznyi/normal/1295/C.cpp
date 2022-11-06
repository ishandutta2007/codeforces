#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;
const long long inf = 1e18;

int nxt[N][30], lst[30];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T > 0) {
        T--;
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < 26; j++)
                nxt[i][j] = -1, lst[j] = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++)
                nxt[i][j] = lst[j];
            lst[s[i] - 'a'] = i;
        }
        int ans = 1;
        int cur_pos = lst[t[0] - 'a'];
        if (cur_pos == -1) {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i < t.size(); i++)
            if (nxt[cur_pos][t[i] - 'a'] != -1)
                cur_pos = nxt[cur_pos][t[i] - 'a'];
            else
                if (lst[t[i] - 'a'] == -1) {
                    ans = -1;
                    break;
                } else {
                    cur_pos = lst[t[i] - 'a'];
                    ans++;
                }
        cout << ans << "\n";
    }
    return 0;
}