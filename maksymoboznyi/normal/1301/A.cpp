#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 3e5 + 5;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t) {
        t--;
        string a, b, c;
        cin >> a >> b >> c;
        bool was = 0;
        for (int i = 0; i < a.size(); i++) {
            if (c[i] != a[i] && c[i] != b[i])
                was = 1;
        }
        cout << (was ? "NO" : "YES") << "\n";
    }
    return 0;
}