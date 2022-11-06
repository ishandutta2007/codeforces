#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n, ans[N], was = 0, l[N], r[N], p[N], ans1[N], ans2[N], ans3[N], ans4[N];
vector<int> a[N], b[N];
set<pair<int, int> > q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];

    for (int i = 1; i <= n; i++)
        a[l[i]].pb(i), b[r[i] + 1].pb(i);
    for (int i = 1; i <= n; i++) {
        for (auto pos: a[i])
            q.insert({r[pos] - l[pos] + 1 + i, pos});
        for (auto pos: b[i])
            q.erase({r[pos] - l[pos] + 1 + l[pos], pos});
        int pos = q.begin() -> second;
        ans[pos] = i;
        p[i] = pos;
        q.erase(q.begin());
    }
    for (int i = 1; i < n; i++)
        if (r[p[i]] > i && l[p[i + 1]] <= i) {
            cout << "NO\n";
            for (int i = 1; i <= n; i++)
                cout << ans[i] << ' ';
            cout << "\n";
            swap(ans[p[i]], ans[p[i + 1]]);
            for (int j = 1; j <= n; j++)
               cout << ans[j] << ' ';
            return 0;
        }

    q.clear();
    for (int i = 1; i <= n; i++)
        a[i].clear(), b[i].clear();
    for (int i = 1; i <= n; i++)
        a[l[i]].pb(i), b[r[i] + 1].pb(i);
    for (int i = 1; i <= n; i++) {
        for (auto pos: a[i])
            q.insert({r[pos] - l[pos] + 1 + i, pos});
        for (auto pos: b[i])
            q.erase({r[pos] - l[pos] + 1 + l[pos], pos});
        int pos = q.begin() -> second;
        ans1[pos] = i;
        q.erase(q.begin());
    }


    for (int i = 1; i <= n; i++) {
        for (auto pos: a[i])
            q.insert({r[pos] - l[pos] + 1 + i, -pos});
        for (auto pos: b[i])
            q.erase({r[pos] - l[pos] + 1 + l[pos], -pos});
        int pos = -q.begin() -> second;
        ans2[pos] = i;
        q.erase(q.begin());
    }

    q.clear();
    for (int i = 1; i <= n + 1; i++)
        a[i].clear(), b[i].clear();

    for (int i = 1; i <= n; i++)
        a[r[i]].pb(i), b[l[i] - 1].pb(i);
    for (int i = n; i > 0; i--) {
        for (auto pos: a[i])
            q.insert({r[pos] - l[pos] + 1 + n - i, pos});
        for (auto pos: b[i])
            q.erase({r[pos] - l[pos] + 1 + n - r[pos], pos});
        int pos = q.begin() -> second;
        ans3[pos] = i;
        q.erase(q.begin());
    }

    for (int i = n; i > 0; i--) {
        for (auto pos: a[i])
            q.insert({r[pos] - l[pos] + 1 + n - i, -pos});
        for (auto pos: b[i])
            q.erase({r[pos] - l[pos] + 1 + n - r[pos], -pos});
        int pos = -q.begin() -> second;
        ans4[pos] = i;
        q.erase(q.begin());
    }
    for (int i = 1; i <= n; i++)
        if (ans1[i] != ans2[i]) {
            cout << "NO\n";
            for (int i = 1; i <= n; i++)
                cout << ans1[i] << ' ';
            cout << "\n";
            for (int i = 1; i <= n; i++)
                cout << ans2[i] << ' ';
            return 0;
        } else if (ans1[i] != ans3[i]) {
                cout << "NO\n";
            for (int i = 1; i <= n; i++)
                cout << ans1[i] << ' ';
            cout << "\n";
            for (int i = 1; i <= n; i++)
                cout << ans3[i] << ' ';
            return 0;
        } else if (ans1[i] != ans4[i]) {
            cout << "NO\n";
            for (int i = 1; i <= n; i++)
                cout << ans1[i] << ' ';
            cout << "\n";
            for (int i = 1; i <= n; i++)
                cout << ans4[i] << ' ';
            return 0;
        }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << ans1[i] << ' ';
    return 0;
}