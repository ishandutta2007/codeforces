#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 2e5 + 5;
const long long M = 1e9 + 7;

int n, k, a[N];

int get_kol(int pos, int del) {
    int p1 = lower_bound(a + 1, a + n + 1, pos - del) - a;
    int p2 = upper_bound(a + 1, a + n + 1, pos + del) - a - 1;
    return p2 - p1 + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int u = 0; u < t; u++) {
    cin >> n >> k;
    k++;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int pos = -1, ans = 1e9;
    for (int i = k; i <= n; i++) {
        int l = 0, r = a[i] + 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (get_kol(m, a[i] - m) >= k)
                l = m;
            else
                r = m;
        }
        if (ans > a[i] - l)
            pos = l, ans = a[i] - l;
    }
    for (int i = 1; i <= n - k + 1; i++) {
        int l = a[i] - 1, r = 1e9 + 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (get_kol(m, m - a[i]) >= k)
                r = m;
            else
                l = m;
        }
        if (ans > r - a[i])
            pos = r, ans = r - a[i];
    }
    cout << pos << "\n";
    }
    return 0;
}