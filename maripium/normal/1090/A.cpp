#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
int n, k;
int a[200005], maxn[200005];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int val = 0;
    FOR(i, 1, n) {
        cin >> a[i];
        FOR(j, 1, a[i]) {
            int x; cin >> x;
            maxn[i] = max(maxn[i], x);
        }
        val = max(val, maxn[i]);
    }
    int sum = 0;
    FOR(i, 1, n) sum += a[i] * (val - maxn[i]);
    cout << sum;
}