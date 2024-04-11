#include <bits/stdc++.h>
using namespace std;

const int N = 500005, MB[97] = {794421773, 399764759, 942938621, 400837919, 659771339, 196844909, 602673221, 574207727, 173980517, 484093327, 351518099, 889050007, 325836041, 150922769, 407670019, 512029009, 119092151, 643985989, 675100003, 181241393, 571155593, 109980473, 675039511, 703923953, 278076527, 914686141, 259342301, 106637017, 887610709, 694910851, 953009119, 591407501, 163179101, 192030067, 792381179, 638893391, 639023351, 537774511, 130881209, 787671737, 213589637, 653185111, 117890761, 171515153, 318185117, 303432197, 819958553, 147180277, 476754569, 319325621, 340312901, 171919661, 362561081, 923331589, 679341473, 830063599, 896529031, 654857309, 134253179, 632500343, 856230751, 695787643, 747339793, 699373111, 533028967, 901178137, 216733973, 492475927, 683812813, 445817279, 320791363, 344282429, 149168689, 592684123, 932861861, 769854577, 474653891, 696738373, 367456937, 642815153, 395886661, 392301223, 471619769, 486992123, 407952793, 263913073, 144284351, 492072619, 293737799, 448005487, 124160929, 701474461, 669668011, 861433589, 957110953, 524863957, 564080779};

int n, MOD[3];
char s[N], t[N];
long long pw[3][N];
long long hs[3][N], ht[3][N];

void build_hash(char s[N], long long hs[3][N]) {
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            hs[j][i] = (hs[j][i - 1] * 10 + (s[i] - '0')) % MOD[j];
        }
    }
}

tuple<long long, long long, long long> get_hash(long long hs[3][N], int l, int r) {
    long long a[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        a[i] = (hs[i][r] - hs[i][l - 1] * pw[i][r - l + 1] + 1LL * MOD[i] * MOD[i]) % MOD[i];
    }
    return {a[0], a[1], a[2]};
}

bool check(int l1, int r1, int l2, int r2, int x) {
    auto [u0, u1, u2] = get_hash(hs, l1, r1);
    auto [v0, v1, v2] = get_hash(hs, l2, r2);
    if ((u0 + v0) % MOD[0] != ht[0][x] || (u1 + v1) % MOD[1] != ht[1][x] || (u2 + v2) % MOD[2] != ht[2][x]) {
        return false;
    }
    int car = 0;
    for (int i = x; i >= 1; i--) {
        int u = (r1 >= l1 ? s[r1] - '0' : 0);
        int v = (r2 >= l2 ? s[r2] - '0' : 0);
        int d = t[i] - '0';
        if ((u + v + car) % 10 != d) {
            return false;
        }
        r1--;
        r2--;
        car = (u + v + car) / 10;
    }
    return car == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> uni(0, 95);
    for (int i = 0; i < 3; i++) {
        while (true) {
            bool ok = true;
            MOD[i] = MB[uni(rng)];
            for (int j = 0; j < i; j++) {
                if (MOD[i] == MOD[j]) {
                    ok = false;
                }
            }
            if (ok) {
                break;
            }
        }
    }
    cin >> (s + 1) >> (t + 1);
    int n = strlen(s + 1), x = strlen(t + 1);
    pw[0][0] = pw[1][0] = pw[2][0] = 1;
    for (int i = 1; i <= max(n, x); i++) {
        for (int j = 0; j < 3; j++) {
            pw[j][i] = pw[j][i - 1] * 10 % MOD[j];
        }
    }
    build_hash(s, hs);
    build_hash(t, ht);
    for (int i = 1; i <= n; i++) {
        for (int sl = max(1, x - 1); sl <= x; sl++) {
            for (int sr = max(1, x - 1); sr <= x; sr++) {
                if (i >= sl && i + sr <= n && check(i - sl + 1, i, i + 1, i + sr, x)) {
                    return cout << i - sl + 1 << " " << i << "\n"
                                << i + 1 << " " << i + sr << '\n',
                           0;
                }
            }
        }
    }
    for (int i = 1; i + x - 1 <= n; i++) {
        int le = 1, ri = x;
        while (le <= ri) {
            int mi = (le + ri) / 2;
            auto [u0, u1, u2] = get_hash(hs, i, i + mi - 1);
            if (ht[0][mi] != u0 || ht[1][mi] != u1 || ht[2][mi] != u2) {
                ri = mi - 1;
            } else {
                le = mi + 1;
            }
        }
        int sz = x - ri;
        for (int sl = max(1, sz - 1); sl <= sz; sl++) {
            if (i + x + sl - 1 <= n && check(i, i + x - 1, i + x, i + x + sl - 1, x)) {
                return cout << i << " " << i + x - 1 << "\n"
                            << i + x << " " << i + x + sl - 1 << '\n',
                       0;
            }
            if (i - sl >= 1 && check(i - sl, i - 1, i, i + x - 1, x)) {
                return cout << i - sl << " " << i - 1 << "\n"
                            << i << " " << i + x - 1 << '\n',
                       0;
            }
        }
    }
}