#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;
const long long M = 1e9 + 7;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int ans = 0, l = -1, r = -1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '[')
        {
            if (l == -1)
                l = i;
        } else if (s[i] == ']')
            r = i;
    if (l == -1 || r == -1 || r < l) {
        cout << -1;
        return 0;
    }
    int l1 = -1, r1 = -1;
    for (int i = l + 1; i < r; i++)
        if (s[i] == ':')
        {
            r1 = i;
            if (l1 == -1)
                l1 = i;
        }
    if (l1 == r1) {
        cout << -1;
        return 0;
    }
    ans = l + l1 - l - 1 + r - r1 - 1 + s.size() - r - 1;

    for (int i = l1 + 1; i < r1; i++)
        if (s[i] != '|')
            ans++;
    cout << s.size() - ans;
    return 0;
}