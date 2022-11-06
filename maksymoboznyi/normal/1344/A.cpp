#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 2e5 + 5;

int n, a[N];
map<int, int> kol;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        kol.clear();
        bool can = 1;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (kol[(a[i] + i + n * 1000000000) % n] != 0)
                can = 0;
            else
                kol[(a[i] + i + n * 1000000000) % n] = 1;
        }
        if (can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}