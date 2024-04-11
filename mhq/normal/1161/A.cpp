#pragma optimize "-O3"
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = (int)1e5 + 100;
int x[maxN];
int ans = 0;
int frst[maxN];
int lst[maxN];
void solve(int a, int b) {
    if (frst[a] == 0 || frst[b] == 0) {
        ans++;
        return ;
    }
    if (lst[b] < frst[a]) {
        ans++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> x[i];
        lst[x[i]] = i;
    }
    for (int i = k; i >= 1; i--) {
        frst[x[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        solve(i, i);
        if (i + 1 <= n) {
            solve(i, i + 1);
            solve(i + 1, i);
        }
    }
    cout << ans;
    return 0;
}