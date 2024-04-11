#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int maxN = 2 * (int)1e5 + 100;
int p[maxN], id[maxN];
int n;
int l[maxN], r[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    vector < int > f;
    cin >> n;
    p[0] = n + 1;
    p[n + 1] = n + 1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        id[p[i]] = i;
    }
    f.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (p[f.back()] < p[i]) f.pop_back();
        l[i] = f.back() + 1;
        f.push_back(i);
    }
    f.clear();
    f.push_back(n + 1);
    for (int i = n; i >= 1; i--) {
        while (p[f.back()] < p[i]) f.pop_back();
        r[i] = f.back() - 1;
        f.push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int le = l[i];
        int ri = r[i];
        if (i - le <= ri - i) {
            for (int j = i - 1; j >= le; j--) {
                int where = id[p[i] - p[j]];
                if (where >= i && where <= ri) ans++;
            }
        }
        else {
            for (int j = i + 1; j <= ri; j++) {
                int where = id[p[i] - p[j]];
                if (i >= where && where >= le) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}