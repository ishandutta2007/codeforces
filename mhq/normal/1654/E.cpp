#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int a[maxN];
int n;
int cnt[maxN];
const int BUBEN = (int)sqrt(maxN);
const int maxP = 5e7;
int cnt_calc[maxP];
vector<pair<int,int>> uni[maxN];

int best = 0;
int p[maxN];
int sz[maxN];
int get(int x) {
    if (x == p[x]) return p[x];
    return p[x] = get(p[x]);
}
void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    best = max(best, sz[a]);
    p[b] = a;
}
int solve() {
    best = 0;
    for (int i = 1; i <= BUBEN; i++) {
        for (int j = 1; j <= n; j++) {
            cnt_calc[j * i - a[j] + maxN]++;
            best = max(best, cnt_calc[j * i - a[j] + maxN]);
        }
        for (int j = 1; j <= n; j++) {
            cnt_calc[j * i - a[j] + maxN]--;
        }
    }
//    cout << best << endl;
//    int at_most_sz = maxN / BUBEN + 5;
//    for (int c = 1; c <= n; c += at_most_sz) {
//        int from = c;
//        int to = min(n, c + 2 * at_most_sz - 1);
//        for (int x = from; x <= to; x++) {
//            for (int y = x + 1; y <= to; y++) {
//
//            }
//        }
//    }
    for (int i = 1; i < maxN; i++) uni[i].clear();
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if ((j - i) * BUBEN > maxN) break;
            int his_d = (a[j] - a[i]) / (j - i);
            if (his_d * (j - i) != (a[j] - a[i])) continue;
            if (his_d <= 0) continue;
            uni[his_d].emplace_back(i, j);
        }
    }
//    cout << best << endl;
    for (int i = 1; i <= n; i++) {
        sz[i] = 1;
        p[i] = i;
    }
    for (int z = BUBEN + 1; z < maxN; z++) {
        for (auto& it : uni[z]) {
            unite(it.first, it.second);
        }
        for (auto& it : uni[z]) {
            sz[it.first] = 1;
            p[it.first] = it.first;
            sz[it.second] = 1;
            p[it.second] = it.second;
        }
    }
//    cout << best << " ? " << endl;
    return best;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, cnt[a[i]]);
    }
    ans = max(ans, solve());
    reverse(a + 1, a + n + 1);
    ans = max(ans, solve());
//    cout << ans << endl;

    cout << n - ans << '\n';
    return 0;
}