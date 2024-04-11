#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 2e5 + 5;

int n, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int cur = 1;
        sort(a + 1, a + n + 1);
        int ans = 1;
        while (cur <= n) {
            int pcur = cur - 1;
            while (cur <= n && a[cur] > ans + (cur - pcur) - 1)
                cur++;
            if (cur == n + 1)
                break;
            ans += cur - pcur;
            cur++;
        }
        cout << ans << "\n";
    }
    return 0;
}