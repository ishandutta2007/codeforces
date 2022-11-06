#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 1e5 + 5;

int n, k, a[N], kol[N], num[N];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i <= k; i++)
            num[i] = 1;
        for (int i = 1; i <= n; i++)
            kol[i] = -1;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (kol[a[i]] == -1) {
                kol[a[i]] = cur;
                num[cur] = a[i];
                cur++;
            }
        }
        if (cur > k) {
            cout << "-1\n";
            continue;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            while (ans.size() % k != kol[a[i]])
                ans.pb(num[ans.size() % k]);
            ans.pb(a[i]);
        }
        cout << ans.size() << "\n";
        for (auto p: ans)
            cout << p << ' ';
        cout << "\n";
    }
    return 0;
}