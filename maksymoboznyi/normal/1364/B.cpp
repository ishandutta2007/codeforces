#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define pi pair<int, int>
#define int long long
using namespace std;

const int N = 3e5 + 5;

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
        vector<int> ans;
        while (cur <= n) {

            ans.pb(a[cur]);
            int lst = cur;
            cur++;
            int c;
            if (a[cur] > a[cur - 1])
                c = 1;
            else
                c = 0;
            while (cur <= n && ((c == 1 && a[cur] > a[cur - 1]) || (c == 0 && a[cur] < a[cur - 1])))
                cur++;
            if (cur == n + 1) {
                if (lst != n)
                    ans.pb(a[n]);
                break;
            }
            cur--;
        }
        cout << ans.size() << "\n";
        for (auto x: ans)
            cout << x << ' ';
        cout << "\n";
    }
    return 0;
}