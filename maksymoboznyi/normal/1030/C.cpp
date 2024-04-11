#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;

int n, a[N];

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
        {
            char x;
            cin >> x;
            a[i] = x - '0';
        }
    int sum = 0;
    for (int len = 1; len < n; len++)
    {
        sum += a[len - 1];
        int cur_s = 0, r = 0;
        for (int j = len; j < n; j++)
        {
            cur_s += a[j];
            if (cur_s == sum)
                r = 1, cur_s = 0;
        }
        if (cur_s == 0 && r == 1)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}