#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 1e5 + 5;

int n, a[N], pos[N];

bool is_cons(int l, int r) {
    int val = a[l];
    for (int i = l + 1; i <= r; i++)
        if (a[i] == val + 1)
            val++;
        else
            return 0;
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int p1 = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        int cur = 1, R = n, can = 1;
        while (cur < n) {
            int l = pos[cur];
            if (!is_cons(l, R)) {
                cout << "No\n";
                can = 0;
                break;
            }
            int c = cur;
            cur = cur + (R - l + 1);
            R = pos[c] - 1;
        }
        if (can)
            cout << "Yes\n";
    }
    return 0;
}