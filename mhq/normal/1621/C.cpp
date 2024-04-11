#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e4 + 10;
int ask(int i) {
    cout << "? " << i << endl;
    int resp;
    cin >> resp;
    return resp;
}
int p[maxN];
bool used[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            used[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                vector<int> cycle;
                while (true) {
                    int c = ask(i);
                    cycle.push_back(c);
                    if (used[c]) break;
                    used[c] = true;
                }
                int pos = -1;
                for (int z = 0; z < cycle.size(); z++) {
                    if (cycle[z] == i) {
                        pos = z;
                        break;
                    }
                }
                assert(pos != -1);
                cycle.pop_back();
                for (int z = 0; z < cycle.size(); z++) {
                    p[cycle[z]] = cycle[(z + 1) % cycle.size()];
                }
            }
        }
        cout << "! ";
        for (int i = 1; i <= n; i++) cout << p[i] << " ";
        cout << endl;
    }
    return 0;
}