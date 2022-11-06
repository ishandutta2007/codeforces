#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n;
int kol[N];
multiset<int> q;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int q;
        cin >> q;
        kol[q]++;
    }
    for (int i = 1; i <= 100'000; i++)
        if (kol[i] != 0)
            q.insert({-kol[i]});
    int m;
    cin >> m;
    while (m--) {
        char c;
        int x;
        cin >> c >> x;
        if (q.find(-kol[x]) != q.end())
            q.erase(q.find(-kol[x]));
        if (c == '+')
            kol[x]++;
        else
            kol[x]--;
        if (kol[x] != 0)
            q.insert(-kol[x]);
        if (q.size() == 0) {
            cout << "NO\n";
            continue;
        }
        auto it = q.begin();
        int k = 0;
        if (-*it < 4) {
            cout << "NO\n";
            continue;
        }
        k += (-*it - 4) / 2;
        it++;
        while (it != q.end() && *it != -1 && k < 2) {
            k += (-*it) / 2;
            it++;
        }
        if (k < 2)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}