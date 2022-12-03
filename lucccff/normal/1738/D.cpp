#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int P = 998244353;

int a[N], n, b[N], st[N];
vector <int> e[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            e[a[i]].push_back(i);
        }
        int x = 0, y = 0;
        int f;
        for(int i = 1; i <= n; i++) {
            if (a[i] == 0 || a[i] == n + 1) {
                if (a[i] == 0) f = 0;
                else f = 1;
                st[y++] = i;
            }
        }
        int k = 0;
        while (x < y) {
            if (f) {
                for(int i = x; i < y; i++) {
                    k = max(k, st[i]);
                }
            }
            f ^= 1;
            int z = y;
            for(int i = x; i < y - 1; i++) {
                if (e[st[i]].size()) {
                    swap(st[i], st[y - 1]);
                    break;
                }
            }
            for(int i = x; i < y; i++) {
                for(auto p : e[st[i]]) {
                    st[z++] = p;
                }
            }
            x = y;
            y = z;
        }
        cout << k << endl;
        for(int i = 0; i < n; i++) {
            cout << st[i] << " ";
        }
        cout << endl;
        for(int i = 0; i <= n + 1; i++) {
            e[i].clear();
        }
    }
    return 0;
}