#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 3e5 + 5;

int n, m;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t) {
        t--;
        cin >> n >> m;
        int k = (n - m) / (m + 1);
        int del = n - m - k * (m + 1);
        //cout << k << ' ' << del << endl;
        int norm = m + 1 - del, nenorm = del;
        //cout << norm << ' ' << nenorm << endl;
        int ans = n * (n + 1) / 2 - norm * k * (k + 1) / 2 - nenorm * (k + 1) * (k + 2) / 2;
        cout << ans << "\n";
    }

    return 0;
}