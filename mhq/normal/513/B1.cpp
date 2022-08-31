#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld  ;
const int maxN = 55;
int ans[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll x;
    cin >> x;
    int l = 1;
    int r = n;
    for (int i = 1; i <= n - 1; i++) {
        if (x > (1LL << (n - i - 1))) {
            ans[r] = i;
            r--;
            x -= (1LL << (n - i - 1));
        }
        else {
            ans[l] = i;
            l++;
        }
    }
    ans[l] = n;
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}