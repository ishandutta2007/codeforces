#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;

int n, x, a[N], b[N], used[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (used[b[i]] == 1) {
            cout << 0 << endl;
        } else {
            int ans = 0;
            while (a[cur] != b[i])
                used[a[cur]] = 1, cur++, ans++;
            used[a[cur]] = 1, cur++, ans++;
            cout << ans << endl;
        }
    }
    return 0;
}