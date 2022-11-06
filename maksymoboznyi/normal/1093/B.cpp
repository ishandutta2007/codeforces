#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;

bool is_pal(string s) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] != s[s.size() -i - 1])
            return 0;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        if (!is_pal(s))
            cout << s;
        else {
            for (int i = 1; i < s.size(); i++)
            if (s[i] != s[0]) {
                swap(s[i], s[0]);
                break;
            }
            if (is_pal(s))
                cout << "-1";
            else
                cout << s;
        }
        cout << "\n";
    }
    return 0;
}