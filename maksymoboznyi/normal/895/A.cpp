#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 1e6+6;
int n, a[N], s[N];
signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
        s[0] = 0;
        for (int i = 1; i <= n; i++)
            s[i] = s[i-1] + a[i];
    int mi = 1000000000;
    for (int l = 1; l <= n; l++)
        for (int r = l; r <= n; r++)
        {
            if (abs(s[r] - s[l-1]-(s[n] - (s[r] - s[l-1]))) < mi)
                mi = abs(s[r] - s[l-1]-(s[n] - (s[r] - s[l-1])));
        }
    cout << mi;
    return 0;
}