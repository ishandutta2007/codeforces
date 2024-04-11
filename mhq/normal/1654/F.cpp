#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (1 << 18) + 10;
char s[maxN];
int f[maxN];
int p[maxN];
int pn[maxN];
int cn[maxN];
int c[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<pair<int,int>> d;
    for (int i = 0; i < (1 << n); i++) {
        cin >> s[i];
        d.emplace_back(s[i], i);
    }
    sort(d.begin(), d.end());
    int cls = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (i == 0 || d[i].first != d[i - 1].first) {
            cls++;
        }
        c[d[i].second] = cls;
        p[i] = d[i].second;
    }
    for (int h = 0; h < n; h++) {
        //h -> h + 1
        for (int i = 0; i <= cls; i++) {
            f[i] = 0;
        }
        for (int i = 0; i < (1 << n); i++) {
            int x = p[i] ^ (1 << h);
            pn[i] = x;
            f[c[x]]++;
        }
        for (int i = 1; i <= cls; i++) {
            f[i] += f[i - 1];
        }
        for (int i = (1 << n) - 1; i >= 0; i--) {
            p[f[c[pn[i]]] - 1] = pn[i];
            f[c[pn[i]]]--;
        }
        cls = 1;
        cn[p[0]] = 1;
        for (int i = 0; i + 1 < (1 << n); i++) {
            auto m1 = make_pair(c[p[i]], c[p[i] ^ (1 << h)]);
            auto m2 = make_pair(c[p[i + 1]], c[p[i + 1] ^ (1 << h)]);
            if (m1 != m2) {
                cls++;
            }
            cn[p[i + 1]] = cls;
        }
        for (int i = 0; i < (1 << n); i++) {
            c[i] = cn[i];
        }
    }
    int x = p[0];
    for (int z = 0; z < (1 << n); z++) {
        cout << s[z ^ x];
    }

    return 0;
}