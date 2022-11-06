#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;

const int N = 2e5 + 5;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int cx = 1, cy = 1;
    cin >> n;
    vector<pair<int, int> > a;
    a.pb({0, 0});
    for (int i = 1; i <= n + 1; i++) {
        a.pb({cx - 1, cy});
        a.pb({cx, cy - 1});
        a.pb({cx, cy});
        cx++;
        cy++;
    }
    cout << a.size() << "\n";
    for (auto p: a)
        cout << p.first << ' ' << p.second << "\n";
    return 0;
}