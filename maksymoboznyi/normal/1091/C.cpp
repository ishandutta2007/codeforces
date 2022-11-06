#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define x first
#define y second
#define int long long
using namespace std;


int n;
vector<int> ans;

void get(int d) {
    int res = 0;
    int kol = n / d;
    res = 1ll*(kol)*(kol - 1) * d / 2;
    ans.pb(res + kol);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i*i <= n; i++)
    if (n % i == 0) {
        get(i);
        if (i * i != n)
            get(n/i);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}