#include<bits/stdc++.h>

using namespace std;

int ask(int u) {
    cout << "? " << u << endl;
    int v;
    cin >> v;
    return v;
}

int main(void) {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> d(n + 1, 0);
        for (int i = 1; i <= n; ++i) cin >> d[i];
        vector<int> color(n + 1, 0);
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 1);
        sort(ord.begin(), ord.end(), [&](int x, int y) { return d[x] > d[y]; });
        int ncolor = 1;
        for (auto u: ord) {
            if (color[u]) continue;
            if (d[u] == 0) {
                color[u] = ncolor++;
                continue;
            }
            vector<int> comp;
            comp.push_back(u);
            bool found = false;
            for (int i = 0; i < d[u]; ++i) {
                int v = ask(u);
                if (color[v]) {
                    for (auto x: comp) color[x] = color[v];
                    found = true;
                    break;
                }
                else {
                    comp.push_back(v);
                }
            }
            if (!found) {
                for (auto x: comp) color[x] = ncolor;
                ++ncolor;
            }
        }
        cout << "!";
        for (int i = 1; i <= n; ++i) cout << ' ' << color[i];
        cout << endl;
    }
    return 0;
}