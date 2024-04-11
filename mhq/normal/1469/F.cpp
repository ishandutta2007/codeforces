#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 6e5 + 10;
int n, k;
int l[maxN];
int delta[maxN];
void addSegm(int l, int r) {
    delta[l]++;
    delta[r + 1]--;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    sort(l + 1, l + n + 1);
    reverse(l + 1, l + n + 1);
    ll tot_v = 1;
    int where = -1;
    for (int i = 1; i <= n; i++) {
        tot_v += l[i];
        tot_v -= 2;
        if (tot_v >= k) {
            where = i;
            break;
        }
    }
    if (where == -1) {
        cout << -1;
        return 0;
    }
    int cnt = 0;
    int pos = -1;
    delta[0]++;
    delta[1]--;
    int already = 0;
    for (int i = 1; i <= n; i++) {
        while (cnt == 0) {
            pos++;
            if (pos > 0) delta[pos] += delta[pos - 1];
            cnt += delta[pos];
            already += delta[pos];
        }
        if (already + delta[pos + 1] + delta[pos] >= k) {
            cout << (already >= k ? pos : (pos + 1)) << '\n';
            return 0;
        }
        cnt--;
        already--;
        delta[pos]--;
        delta[pos + 1]++;
        if (l[i] % 2 == 1) {
            addSegm(pos + 2, pos + 2 + (l[i] - 1) / 2 - 1);
            addSegm(pos + 2, pos + 2 + (l[i] - 1) / 2 - 1);
        }
        else {
            addSegm(pos + 2, pos + 2 + (l[i] - 1) / 2 - 1);
            addSegm(pos + 2, pos + 2 + (l[i]) / 2 - 1);
        }
    }
    while (pos + 1 < maxN) {
        pos++;
        delta[pos] += delta[pos - 1];
    }
    ll need = 0;
    for (int i = 0; i < maxN; i++) {
        need += delta[i];
        if (need >= k) {
            cout << i << '\n';
            return 0;
        }
    }
    assert(false);
    return 0;
}