#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
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
        bool is0 = 1;
        for (int i = 1; i < n; i++)
            if (a[i] > a[i + 1])
                is0 = 0;
        if (is0) {
            cout << "0\n";
            continue;
        }
        bool is1 = 1;
        int l = 1, r = n;
        while (l <= n && a[l] == l)
            l++;
        while (r > 0 && a[r] == r)
            r--;
        for (int i = l; i <= r; i++)
            if (a[i] == i)
                is1 = 0;
        if (is1) {
            cout << "1\n";
            continue;
        }
        cout << "2\n";
    }
    return 0;
}