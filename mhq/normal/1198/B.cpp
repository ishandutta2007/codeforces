#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2 * (int)1e5 + 100;
int a[maxN];
int q;
vector < pair < int, int > > all[maxN];
const int LG = 20;
int mx[LG][maxN];
int lg[maxN];
int getMx(int l, int r) {
    if (l > r) return 0;
    int k = lg[r - l + 1];
    return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    lg[1] = 0;
    for (int i = 2; i < maxN; i++) {
        lg[i] = lg[i - 1];
        if (!(i & (i - 1))) lg[i]++;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all[i].emplace_back(0, a[i]);
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        char tp;
        cin >> tp;
        if (tp == '1') {
            int who, x;
            cin >> who >> x;
            all[who].emplace_back(i, x);
        }
        else {
            int x;
            cin >> x;
            mx[0][i] = x;
           // cout << i << " " << x << "GGGWP" << endl;
        }
    }
    for (int i = 0; i + 1 < LG; i++) {
        for (int j = 1; j + (1 << (i + 1)) <= q + 1; j++) {
            mx[i + 1][j] = max(mx[i][j], mx[i][j + (1 << i)]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int cur = all[i].back().second;
        int l = all[i].back().first;
        //cout << l << " " << q << " GG" << endl;
        cur = max(cur, getMx(l + 1, q));
        cout << cur << " ";
    }
    return 0;
}