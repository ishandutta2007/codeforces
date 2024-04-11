#include <bits/stdc++.h>

using namespace std;

constexpr int N = 3e5 + 1;

int a[N];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n, t, r;
    cin >> n;
    r = n;
    cout << 1;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        a[t] = 1;
        while (r && a[r])
            --r;
        cout << ' ' << i - n + r + 2;
    }
    return 0;
}