#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int n, q, pos[N], b[N], cnt[2][N];
char a[N];
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    cin >> (a + 1);
    int tot = 0;
    for(int i = 2; i <= n; i++) if(a[i] == a[i - 1]) {
        pos[++tot] = i, b[tot] = a[i] - '0';
    }
    for(int i = 1; i <= tot; i++) {
        cnt[0][i] = cnt[0][i - 1], cnt[1][i] = cnt[1][i - 1];
        cnt[b[i]][i]++;
    }
    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        int L = lower_bound(pos + 1, pos + tot + 1, l + 1) - pos;
        int R = lower_bound(pos + 1, pos + tot + 1, r + 1) - pos;
        R--;
        if(L > R) cout << "1\n";
        else {
            int c0 = cnt[0][R] - cnt[0][L - 1];
            int c1 = cnt[1][R] - cnt[1][L - 1];
            cout << c0 + c1 - min(c0, c1) + 1 << "\n";
        }
    }
    return 0;
}