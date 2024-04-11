#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e6 + 10;
int ans[maxN];
int pw[25];
void solve(int n) {
    if (n < 0) return ;
    if (n == 0) {
        ans[0] = 0;
        return ;
    }
    if (n == 1) {
        ans[0] = 1;
        ans[1] = 0;
        return ;
    }
    int ind = -1;
    for (int i = 0; i < 25; i++) {
        if (pw[i] > n) {
            ind = i - 1;
            break;
        }
    }
    for (int i = 0; i <= n - pw[ind]; i++) {
        ans[pw[ind] + i] = pw[ind] - 1 - i;
        ans[pw[ind] - 1 - i] = pw[ind] + i;
    }
    solve(2 * pw[ind] - n - 2);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    pw[0] = 1;
    for (int i = 1; i <= 25; i++) {
        pw[i] = 2 * pw[i - 1];
    }
    solve(n);
    long long cur = 0;
    for (int i = 0; i <= n; i++) {
        cur += i ^ ans[i];
    }
    cout << cur << '\n';
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << " ";
    }
}