#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
int p[maxN];
int f[maxN];
int g[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i= 1; i <= n; i++) {
        cin >> p[i];
    }
    f[n] = n;
    g[n] = n;
    set<pair<int,int>> sf, sg;
    f[n - 1] = n;
    g[n - 1] = n;
    bool clg = false;
    bool clf = false;
    int f1 = n;
    int f2 = n;
    for (int i = n - 2; i >= 1; i--) {
        f[i] = i + 1;
        g[i] = i + 1;
        if (p[i + 1] < p[i + 2]) {
            sg.clear();
            clg = true;
            f2 = i + 1;
        }
        //{p[i + 2], g[i + 2]}
        while (true) {
            auto it = sg.lower_bound({p[i + 2], -1});
            if  (it == sg.begin()) break;
            it--;
            if  (it -> second <= g[i + 1]) {
                sg.erase(it);
            }
            else {
                break;
            }
        }
        {
            auto it = sg.lower_bound({p[i + 2], -1});
            if (it == sg.end() || (it->second) < g[i + 1]) {
                sg.insert({p[i + 2], g[i + 1]});
            }
        }
        if (p[i + 1] > p[i + 2]) {
            sf.clear();
            clf = true;
            f1 = i + 1;
        }
        //{p[i + 2], g[i + 2]}
        while (true) {
            auto it = sf.lower_bound({p[i + 2], -1});
            if  (it == sf.end()) break;
            if  (it -> second <= f[i + 1]) {
                sf.erase(it);
            }
            else {
                break;
            }
        }
        {
            auto it = sf.lower_bound({p[i + 2], -1});
            if (it == sf.begin() || (((--it)->second) < f[i + 1])) {
                sf.insert({p[i + 2], f[i + 1]});
            }
        }
//        cout << " HI " << endl;
        //f[i]
        {
            auto it = sg.lower_bound({p[i], -1});
            if (it != sg.end()) {
                f[i] = max(f[i], (it->second));
            }
        }
        {
            auto it = sf.lower_bound({p[i], -1});
             if (it != sf.begin()) {
                --it;
                g[i] = max(g[i], (it->second));
            }
        }
        f[i] = max(f[i], f2);
        g[i] = max(g[i], f1);
        if (!clg){
            f[i] = n;
        }
        if (!clf) {
            g[i] = n;
        }
       /* int cur = i + 1;
        for (int j = i + 1; j <= n; j++) {
            if (j > (i + 1) && p[j] > p[j - 1]) break;
            if (j == n || p[j + 1] > p[i]) cur = max(cur, g[j]);
            cur = max(cur, j);
        }

        assert(cur == f[i]);
        cur = i  +1;
        for (int j = i + 1; j <= n; j++) {
            if (j > (i + 1) && p[j] < p[j - 1]) break;
            if (j == n || p[j + 1] < p[i]) cur = max(cur, f[j]);
        }

        assert(cur == g[i]);*/
        //a[i] < a[i + 1]
    }
    ll ans = 1;
    int mx_up = n;
    int mx_down = n;
    for (int i = n - 1; i >= 1; i--) {
        if (p[i] < p[i + 1]) {
            mx_up = max(mx_up, f[i]);
            mx_down = g[i];
        }
        else {
            mx_up = f[i];
            mx_down = max(mx_down, g[i]);
        }
//        cout << i << " " << mx_up << " " << mx_down << endl;
        ans += (max(mx_up, mx_down) - i + 1);
    }
    cout << ans << '\n';
    return 0;
}