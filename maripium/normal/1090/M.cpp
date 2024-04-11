#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[100005], f[100005];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] != a[i - 1]) f[i] =f[i - 1] + 1;
        else f[i] = 1;
        ans = max(ans, f[i]);
    }
    cout << ans;
}