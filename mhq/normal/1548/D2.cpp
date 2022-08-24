#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 6005;
int x[maxN], y[maxN];
ll get(ll x, int sz) {
    if (sz == 0) return 1;
    if (sz == 1) return x;
    if (sz == 2) return (x * (x - 1)) / 2;
    if (sz == 3) {
        return (x * (x - 1) * (x - 2)) / 6;
    }
    else {
        assert(false);
        return -228;
    }
}
int dist[maxN][maxN];
ll D[2][2];
ll solveEq(int p1, int p2) {
    memset(D, 0, sizeof D);
    for (int i = 1; i <= n; i++) {
        if (x[i] % 2 != p1) continue;
        if (y[i] % 2 != p2) continue;
        D[((x[i] - p1) / 2) % 2][((y[i] - p2) / 2) % 2]++;
    }
    ll ans = 0;
    for (int z1 = 0; z1 <= 3; z1++) {
        for (int z2 = 0; z2 + z1 <= 3; z2++) {
            for (int z3 = 0; z3 + z2 + z1 <= 3; z3++) {
                int z4 = 3 - z3 - z2 - z1;
                vector<pair<int,int>> ids;
                for (int x = 0; x < z1; x++) ids.emplace_back(0, 0);
                for (int x = 0; x < z2; x++) ids.emplace_back(0, 1);
                for (int x = 0; x < z3; x++) ids.emplace_back(1, 0);
                for (int x = 0; x < z4; x++) ids.emplace_back(1, 1);
                assert(ids.size() == 3);
                int cnt = 0;
                for (int A = 0; A < 3; A++) {
                    for (int B = A + 1; B < 3; B++) {
                        auto t1 = ids[A];
                        auto t2 = ids[B];
                        if (t1 != t2) cnt ^= 1;
                    }
                }
                if (cnt == 0) {
                    ll coef = 1;
                    coef *= get(D[0][0], z1);
                    coef *= get(D[0][1], z2);
                    coef *= get(D[1][0], z3);
                    coef *= get(D[1][1], z4);
                    ans += coef;
                }
            }
        }
    }
    return ans;
}
vector<int> by[4][4];
int F[4][4][4];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        by[x[i] % 4][y[i] % 4].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int gc = __gcd(abs(x[i] - x[j]), abs(y[i] - y[j]));
            dist[i][j] = dist[j][i] = gc % 4;
        }
    }
    ll ans = 0;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            ans += solveEq(a, b);
        }
    }
    for (int i = 1; i <= n; i++) {
        int t1 = x[i] % 2;
        int t2 = y[i] % 2;
        memset(F, 0, sizeof F);
        for (int A = 0; A < 4; A++) {
            for (int B = 0; B < 4; B++) {
                if (A % 2 == t1 && B % 2 == t2) continue;
                for (auto& it : by[A][B]) {
                    F[A][B][dist[i][it]]++;
                }
            }
        }
        for (int A = 0; A < 4; A++) {
            for (int B = 0; B < 4; B++) {
                for (int C = A; C < 4; C++) {
                    for (int D = (C == A ? B : 0); D < 4; D++) {
                        if (A % 2 != C % 2) continue;
                        if (B % 2 != D % 2) continue;
                        if (A % 2 == t1 && B % 2 == t2) continue;
                        bool eq = (A == C && B == D);
                        int add_value = 0;
                        add_value += A * D - B * C;
                        add_value += C * t2 - D * t1;
                        add_value -= (A * t2 - B * t1);
                        add_value %= 4;
                        if (A == C && B == D) {
                            add_value -= 0;
                        }
                        else {
                            add_value -= 2;
                        }
                        add_value %= 4;
                        if (add_value < 0) add_value += 4;
                        assert(add_value % 2 == 0);
                        for (int z = 1; z <= 3; z += 2) {
                            for (int t = (eq ? z : 1); t <= 3; t += 2) {
                                int fin = add_value - z - t;
                                if (fin % 4 == 0) {
                                    if (eq && z == t) {
                                        ans += (1LL * F[A][B][z] * (F[A][B][z] - 1)) / 2;
                                    }
                                    else {
                                        ans += (1LL * F[A][B][z] * F[C][D][t]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}