#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    int gcd = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        gcd = __gcd(gcd, abs(a[i + 1] - a[i]));
    }
    for(int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        cout << __gcd(gcd, a[0] + b) << " ";
    }
    return 0;
}