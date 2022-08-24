#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
bool ok[maxN];
set < int > by_p[maxN];
int lp[maxN];
int n, m;
void init() {
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = 2 * i; j < maxN; j += i) {
                lp[j] = i;
            }
        }
    }
}
vector < int > get_pr(int x) {
    vector < int > pp;
    while (x > 1) {
        int p = lp[x];
        while (x % p == 0) {
            x /= p;
        }
        pp.push_back(p);
    }
    return pp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    init();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        char tp;
        int x;
        cin >> tp >> x;
        if (tp == '-') {
            if (!ok[x]) cout << "Already off" << '\n';
            else {
                cout << "Success" << '\n';
                for (int p : get_pr(x)) by_p[p].erase(x);
            }
            ok[x] = false;
        }
        else {
            if (ok[x]) {
                cout << "Already on" << '\n';
            }
            else {
                int who = -1;
                for (int p : get_pr(x)) {
                    if (!by_p[p].empty()) {
                        who = *by_p[p].begin();
                        break;
                    }
                }
                if (who == -1) {
                    cout << "Success" << '\n';
                    ok[x] = true;
                    for (int p : get_pr(x)) {
                        by_p[p].insert(x);
                    }
                }
                else {
                    cout << "Conflict with " << who << '\n';
                }
            }
        }
    }
    return 0;
}