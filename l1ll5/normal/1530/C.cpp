#include<bits/stdc++.h>
using namespace std;
const int N = 300000 + 5;
constexpr int mod = 998244353;
using LL = long long;
int n;
int a[N], b[N];
bool ck(int add) {
    int k = n + add;
    k = k - k / 4;
    LL my = 0;
    LL he = 0;

    for (int i = 1; i <= k; i += 1) {
        if (i <= add) my += 100;
        else my += a[i - add];
    }
    for (int i = 1; i <= k; i += 1) {
        if (i <= n) he += b[i];
        else he += 0;
    }
    return (my >= he);
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i += 1)
            cin >> a[i];
        for (int i = 1; i <= n; i += 1)
            cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        reverse(a + 1, a + n + 1);
        reverse(b + 1, b + n + 1);
        int l = 0, r = 200000, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ck(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
}
/*

*/