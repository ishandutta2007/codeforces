#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 5;

int n, k, pref[N];
char s[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> s[i], pref[i] = pref[i - 1] + (s[i] == 'L');
    int kol_moves = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == 'L')
            kol_moves += (i - 1) - pref[i - 1];
    if (kol_moves < k) {
        cout << -1;
        return 0;
    }
    vector<vector<int> > ans;
    while (kol_moves > 0) {
        vector<int> pos;
        for (int i = 1; i < n; i++)
            if (s[i] == 'R' && s[i + 1] == 'L')
                kol_moves--, pos.pb(i);
        ans.pb(pos);
        for (auto p: pos)
            swap(s[p], s[p + 1]);
    }
    if (ans.size() > k) {
        cout << -1;
        return 0;
    }
    vector<vector<int> > a;
    while (ans.size() > 0) {
        if (a.size() + ans.size() == k) {
            a.pb(ans.back());
            ans.pop_back();
        } else {
            vector<int> q;
            q.pb(ans.back().back());
            ans.back().pop_back();
            a.pb(q);
        }
        if (ans.back().size() == 0)
            ans.pop_back();
    }
    if (a.size() != k) {
        cout << -1;
        return 0;
    }
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i].size() << " ";
        for (auto p: a[i])
            cout << p << ' ';
        cout << "\n";
    }
    return 0;
}