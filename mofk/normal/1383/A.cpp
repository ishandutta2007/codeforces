#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        int bad = 0;
        for (int i = 0; i < n; ++i) if (a[i] > b[i]) bad = 1;
        if (bad) {
            cout << -1 << endl;
            continue;
        }
        vector<bitset<20>> adj(20, 0);
        for (int i = 0; i < n; ++i) {
            int x = a[i] - 'a', y = b[i] - 'a';
            if (x != y) adj[x].set(y);
        }
        int ans = 0;
        for (int i = 0; i < 20; ++i) {
            int j = i + 1; while (j < 20 && !adj[i].test(j)) ++j;
            if (j == 20) continue;
            ++ans;
            for (int k = j + 1; k < 20; ++k) if (adj[i].test(k)) adj[j].set(k);
        }
        cout << ans << endl;
    }
    return 0;
}