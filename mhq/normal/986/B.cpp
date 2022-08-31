#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e6 + 5;
pair < int, int > a[maxN];
int f[maxN];
int n;
void upd(int i, int d) {
    for ( ; i <= n; i = (i | (i - 1)) + 1) f[i] += d;
}
int sum(int r) {
    int p = 0;
    for ( ; r >= 1; r = r & (r - 1)) p += f[r];
    return p;
}
int get(int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    a[n + 1].first = -1;
    sort(a + 1, a + n + 1);
    int i = 1;
    long long ans = 0;
    while (i <= n) {
        int j = i;
        vector < int > all;
        while (a[j].first == a[i].first) {
            all.push_back(a[j].second);
            j++;
        }
        j--;
        for (int k = 0; k < all.size(); k++) {
            ans += get(all[k] + 1, n);
        }
        for (int k = 0; k < all.size(); k++) {
            upd(all[k], 1);
        }
        i = j + 1;
    }
    if (ans % 2 == (3 * n) % 2) cout << "Petr";
    else cout << "Um_nik";
    return 0;
}