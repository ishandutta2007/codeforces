#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
using namespace std;

const int N = 2e5 + 5;

int f(int x) {
    int bx = x;
    int mx = 0, mn = 9;
    while (x > 0)
        mx = max(mx, x % 10), mn = min(mn, x % 10), x /= 10;
    return bx + mn * mx;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, k;
        cin >> a >> k;
        for (int i = 1; i < k; i++) {
            a = f(a);
            if (f(a) == a)
                break;
        }
        cout << a << "\n";
    }
    return 0;
}