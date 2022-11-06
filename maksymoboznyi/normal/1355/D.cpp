#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
using namespace std;

const int N = 2e5 + 5;

int n, a[N], ans = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s;
    cin >> n >> s;
    if (s <= 2 * n - 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i < n; i++)
        cout << "1 ";
    cout << s - n + 1 << "\n";
    cout << n;
    return 0;
}