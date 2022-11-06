#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 5e5 + 5;

int n, a[N], pref[N];

bool check(int k) {
    for (int i = k; i <= n; i++)
        if (pref[i] - pref[i - k] <= 0)
            return 0;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= (n + 1) / 2; i++)
        cin >> a[i];
    int x;
    cin >> x;
    for (int i = (n + 1) / 2 + 1; i <= n; i++)
        a[i] = x;

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];
    if (pref[n] > 0) {
        cout << n;
        return 0;
    }
    ///UNCOMM
    if (x <= 0) {
        for (int i = (n + 1) / 2; i > 0; )
            if (pref[n] - pref[i - 1] > 0) {
                int k = n - i + 1;
                int can = 1;
                for (int r = n; r >= k; r--) {
                    if (pref[r] - pref[r - k] <= 0) {
                        i = r - k;
                        can = 0;
                        break;
                    }
                }
                if (can) {
                    cout << k;
                    return 0;
                }

            } else
                i--;
        cout << -1;
        return 0;
    }


    cout << -1;
    return 0;
}