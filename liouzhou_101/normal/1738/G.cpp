#include <bits/stdc++.h>

using namespace std;

int n, k;

pair<int, int> cell(int diag, int pos)
{
    int st_x = 0; int st_y = 0;
    if (diag <= n - 1) st_y = (n - 1) - diag;
    if (diag >= n - 1) st_x = diag - (n - 1);

    return pair<int, int>(st_x + pos, st_y + pos);
}

void solve()
{
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    string full; for (int i = 0; i < n; i++) full += '1';
    vector<string> t(n, full);

    vector<int> last_del(2 * n - 1, -1);

    int m = n - k + 1;

    for (int iter = 0; iter <= 2 * (m - 1); iter++)
    {
        vector<pair<int, int>> updates;
        for (int diag = 0; diag <= 2 * (n - 1); diag++) if (abs(diag - (n - 1)) <= min(iter, 2 * (m - 1) - iter) && abs(diag - (n - 1)) % 2 == iter % 2)
        {
            int nxt = last_del[diag] + 1;
            //diag-1
            if (diag - 1 < n - 1) nxt = max(nxt, last_del[diag - 1] + 1);
            else nxt = max(nxt, last_del[diag - 1]);

            //diag+1
            if (diag + 1 > n - 1) nxt = max(nxt, last_del[diag + 1] + 1);
            else nxt = max(nxt, last_del[diag + 1]);

            while (true)
            {
                auto cur = cell(diag, nxt);
                if (cur.first >= n || cur.second >= n) { cout << "NO" << '\n'; return; }

                if (s[cur.first][cur.second] == '0') nxt++;
                else
                {
                    t[cur.first][cur.second] = '0';
                    break;
                }
            }
            updates.push_back(pair<int, int>(diag, nxt));
        }
        for (auto it : updates) last_del[it.first] = it.second;
    }

    cout << "YES" << '\n';
    for (auto it : t) cout << it << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

}