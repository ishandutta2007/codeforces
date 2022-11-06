#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;

const int N = 2e5 + 5;

int k;

bool check(int x) {
    int val = x / 10;
    int q = x % 10;
    int t = 1;
    for (int i = 1; i <= q; i++)
        t *= (val + 1);
    for (int i = 1; i <= 10 - q; i++)
        t *= val;
    return (t >= k);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    int l = 6, r = 40 * 10 + 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }
    int val = r / 10;
    int q = r % 10;
    string s = "codeforces";
    for (int i = 1; i <= q; i++) {
        for (int j = 1; j <= val + 1; j++)
            cout << s[i - 1];
    }
    for (int i = q + 1; i <= 10; i++)
        for (int j = 1; j <= val; j++)
            cout << s[i - 1];

    return 0;
}