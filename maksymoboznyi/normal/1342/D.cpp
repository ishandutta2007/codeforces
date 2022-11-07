#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

using namespace std;

const int N = 2e5 + 5;

int n, k, a[N], m, kol[N], c[N], k1[N];

vector<int> q[N];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], kol[a[i]]++;
    for (int i = 1; i <= k; i++)
        cin >> c[i];
    int lst = 0;
    vector<int> free, non_free;
    for (int i = k; i >= 1; i--) {
        while (free.size() > 0 && kol[i] > 0) {
            while (q[free.back()].size() < c[i + 1] && kol[i] > 0)
                kol[i]--, q[free.back()].pb(i);
            if (q[free.back()].size() == c[i + 1]) {
                non_free.pb(free.back());
                free.pop_back();
            }
        }
        if (c[i] > c[i + 1]) {
            for (int j = 1; j <= lst && kol[i] > 0; j++)
                while (q[j].size() < c[i] && kol[i] > 0)
                    kol[i]--, q[j].pb(i);
        }
        while (kol[i] > 0) {
            lst++;
            while (q[lst].size() < c[i] && kol[i] > 0)
                q[lst].pb(i), kol[i]--;
            if (q[lst].size() < c[i])
                free.pb(lst);
            else
                non_free.pb(lst);
        }
        if (c[i] > c[i + 1]) {
            vector<int> non;
            for (auto j : non_free)
                if (q[j].size() < c[i])
                    free.pb(j);
                else
                    non.pb(j);
            non_free = non;
        }

    }
    cout << lst << "\n";
    for (int i = 1; i <= lst; i++) {
        cout << q[i].size() << ' ';
        for (auto j: q[i])
            cout << j << ' ';
        cout << "\n";
    }
    return 0;
}