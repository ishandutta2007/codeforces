#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (1 << 18) + 2;
int a[maxN];
ll ans = 0;
int p[maxN];
pair < int, int > best[maxN][2];
pair < int, int > largest[maxN];
int get(int a) {
    if (a == p[a]) return a;
    return p[a] = get(p[a]);
}
mt19937 rnd(228);
bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (rnd() & 1) swap(a, b);
    p[a] = b;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    //n = 2e5;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //a[i] = i;
        ans -= a[i];
        p[i] = i;
    }
    int cmp = n + 1;
    while (cmp > 1) {
        for (int i = 0; i < (1 << 18); i++) {
            best[i][0] = {-1, -1};
            best[i][1] = {-1, -1};
        }
        for (int j = 0; j <= n; j++) {
            pair < int, int > f = {a[j], get(j)};
            if (best[a[j]][0] < f) {
                if (best[j][0].second != f.second) best[a[j]][1] = best[a[j]][0];
                best[a[j]][0] = f;
            }
            else if (best[a[j]][1] < f && best[a[j]][0].second != f.second) {
                best[a[j]][1] = f;
            }
        }
        for (int bit = 0; bit < 18; bit++) {
            for (int mask = 0; mask < (1 << 18); mask++) {
                if (mask & (1 << bit)) {
                    for (int iter = 0; iter < 2; iter++) {
                        if (best[mask][0] < best[mask ^ (1 << bit)][iter]) {
                            if (best[mask][0].second != best[mask ^ (1 << bit)][iter].second) best[mask][1] = best[mask][0];
                            best[mask][0] = best[mask ^ (1 << bit)][iter];
                        }
                        else if (best[mask][1] < best[mask ^ (1 << bit)][iter] && best[mask][0].second != best[mask ^ (1 << bit)][iter].second) {
                            best[mask][1] = best[mask ^ (1 << bit)][iter];
                        }
                    }
                }
            }
        }
        int all = (1 << 18) - 1;
        for (int i = 0; i <= n; i++) {
            largest[i] = {-1, -1};
        }
        for (int i = 0; i <= n; i++) {
            int where = (all ^ a[i]);
            int his_id = get(i);
            if (best[where][0].second != -1 && best[where][0].second != his_id) {
                largest[his_id] = max(largest[his_id], make_pair(a[i] + best[where][0].first, best[where][0].second));
            }
            else if (best[where][1].second != -1 && best[where][1].second != his_id) {
                largest[his_id] = max(largest[his_id], make_pair(a[i] + best[where][1].first, best[where][1].second));
            }
        }
        for (int i = 0; i <= n; i++) {
            if (p[i] != i) continue;
            if (unite(i, largest[i].second)) {
                cmp--;
                ans += largest[i].first;
            }
        }
    }
    cout << ans;
    return 0;
}