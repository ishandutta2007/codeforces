#include <bits/stdc++.h>
#define pb push_back
#define ll long long


using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18;

bool is[N];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < 26; i++)
            is[i] = 0;
        for (int i = 0; i < s.size(); i++)
            is[s[i] - 'a'] = 1;
        bool r = 0;
        for (int i = 0; i < t.size(); i++)
            if (is[t[i] - 'a'])
                r = 1;
        if (r) {
            cout << "YES\n";
        } else
            cout << "NO\n";
    }
    return 0;
}