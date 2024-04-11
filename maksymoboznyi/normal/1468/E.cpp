#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 101;
int t;
int a[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        sort(a, a + 4);
        cout << 1ll * a[0] * a[2] << "\n";
    }

    return 0;
}