#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 2e5 + 5;

int n, a[N];
map<pair<int, int> , int> b;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> n;
        cin >> s;
        s = '1' + s;
        b.clear();
        int b1 = 0, b2 = 0;
        int ans = 1e9, l, r;
        b[{0, 0,}] = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'L')
                b1++;
            if (s[i] == 'R')
                b1--;
            if (s[i] == 'U')
                b2++;
            if (s[i] == 'D')
                b2--;
            if (b1 == 0 && b2 == 0 && i < ans)
                ans = i, l = 0, r = i;

            if (b[{b1, b2}] != 0 && (i - b[{b1, b2}]) < ans)
                ans = i - b[{b1, b2}], l = b[{b1, b2}], r = i;
            b[{b1, b2}] = i;
        }
        if (ans == 1e9)
            cout << "-1\n";
        else
            cout << l + 1 << ' ' << r << "\n";
    }
    return 0;
}