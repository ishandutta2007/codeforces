#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const long long M = 1e9 + 7;
const int N = 2e5 + 5;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n;
    cin >> q;
    string s;
    for (int o = 0; o < q; o++) {
        cin >> n >> s;
        if (s.size() == 1) {
            cout << "NO\n";
            continue;
        }
        if (s.size() == 2) {
            if (s[0] < s[1])
                cout << "YES\n2\n" << s[0] << ' '<< s[1] << "\n";
            else
                cout << "NO\n";
            continue;
        }
        cout << "YES\n2\n";
        cout << s[0] << ' ';
        for (int i = 1; i < n; i++)
            cout << s[i];
        cout << "\n";
    }
    return 0;
}