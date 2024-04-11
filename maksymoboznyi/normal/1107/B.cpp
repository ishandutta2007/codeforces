#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const long long M = 1e9 + 7;
const int N = 2e5 + 5;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> x;
        cout << 9*(k-1) + x << "\n";
    }
    return 0;
}