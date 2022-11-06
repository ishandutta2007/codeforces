#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e18;

int kol[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        for (int i = 0; i < n; i++)
            if (i % a < b - 1)
                cout << char('a' + i % a);
            else
                cout << char('a' + b - 1);
        cout << "\n";
    }
    return 0;
}