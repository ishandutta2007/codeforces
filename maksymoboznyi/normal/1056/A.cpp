#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;

int kol[N], n;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int r;
        cin >> r;
        for (int j = 0; j < r; j++) {
            int x;
            cin >> x;
            kol[x] ++;
        }
    }
    for (int i = 1; i <= 100; i++)
        if (kol[i] == n)
            cout << i << ' ';
    return 0;
}