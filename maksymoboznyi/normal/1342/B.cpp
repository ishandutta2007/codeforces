#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>

using namespace std;

const int N = 1e5 + 5;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int o;
    cin >> o;
    while (o--) {
        string s = "", t;
        cin >> t;
        bool is[2];
        is[0] = is[1] = 0;
        for (int i = 0; i < t.size(); i++)
            is[t[i] - '0'] = 1;
        if (!is[0] || !is[1])
            cout << t << "\n";
        else {
            int cur = 0, kc = t[0] - '0';
            while (cur != t.size()) {
                s += char(kc + 48);
                if (s.back() == t[cur])
                    cur++;
                kc = !kc;
            }
            cout << s << "\n";
        }
    }
    return 0;
}