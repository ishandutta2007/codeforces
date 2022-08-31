#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 5005;
const int maxK = (int)1e6 + 100;
int a[maxN];
vector < int > pr[maxK];
bool is_p[maxK];
const int maxT = 4;
int sz[maxK];
int f[maxK][maxT];
void add(int where, int x) {
    if (sz[where] > k) return;
    for (int u = 0; u < sz[where]; u++) {
        if (f[where][u] == x) return;
    }
    sz[where]++;
    if (sz[where] > k) return;
    f[where][sz[where] - 1] = x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            add(a[j] - a[i], j);
        }
    }
    for (int i = 2; i < maxK; i++) {
        if (!is_p[i]) {
            for (int j = i; j < maxK; j += i) {
                pr[j].push_back(i);
                is_p[j] = true;
            }
        }
    }
    for (int i = maxK - 1; i >= 1; i--) {
        for (int p : pr[i]) {
            for (int u = 0; u < sz[i]; u++) {
                add(i / p, f[i][u]);
            }
        }
    }
    // (5 * 4) / 2
    for (int i = 1; i < maxK; i++) {
        if (sz[i] > k) continue;
        cout << i;
        return 0;
    }
    assert(false);
    return 0;
}