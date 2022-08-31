#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2005;
int par[maxN];
int p[maxN];
int n, m;
bool used[maxN];
int moves = 0;
void our();
void op() {
    moves++;
    if (moves == 2 * n + 1) exit(0);
    int x;
    cin >> x;
    used[x] = true;
    our();
}
void our() {
    moves++;
    if (moves == 2 * n + 1) exit(0);
    bool made = false;
    for (int i = 1; i <= 2 * n; i++) {
        if (used[i]) continue;
        if (par[i] != -1 && used[par[i]]) {
            used[i] = true;
            made = true;
            cout << i << endl;
            break;
        }
    }
    if (made) op();
    else {
        int ind = -1;
        for (int i = 1; i <= 2 * n; i++) {
            if ((par[i] != -1) && (!used[i]) && (p[par[i]] < p[i])) {
                ind = i;
                break;
            }
        }
        if (ind != -1) {
            used[ind] = true;
            cout << ind << endl;
            op();
        }
        else {
            int ind2 = -1;
            for (int i = 1; i <= 2 * n; i++) {
                if (used[i]) continue;
                if ((ind2 == -1) || (p[ind2] < p[i])) {
                    ind2 = i;
                }
            }
            if (ind2 != -1) {
                cout << ind2 << endl;
                used[ind2] = true;
                op();
            }
            else {
                exit(0);
            }
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> p[i];
    }
    memset(par, -1, sizeof par);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        par[a] = b;
        par[b] = a;
    }
    int t;
    cin >> t;
    if (t == 1) {
        our();
    }
    else {
        op();
    }
    return 0;
}