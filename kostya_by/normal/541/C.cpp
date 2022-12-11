#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 222;

int n;
int f[MAXN];
int cycle_id[MAXN], h = 0;
bool is_in_cycle[MAXN];
int cnt[MAXN];

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (a != 0) {
        return gcd(b % a, a);
    }
    return b;
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    for (int i = 1; i <= n; i++) {
        if (cycle_id[i] ) {
            continue;
        }
        int v = i;
        while (true) {
            cycle_id[v] = -1;

            if (cycle_id[f[v] ] == 0) {
                v = f[v];
                continue;
            }

            if (cycle_id[f[v] ] == -1) {
                int u = f[v];
                h += 1;
                while (true) {
                    cycle_id[u] = h;
                    is_in_cycle[u] = true;
                    u = f[u];
                    if (cycle_id[u] == h) {
                        break;
                    }
                }
            }
            int color = cycle_id[f[v] ];
            v = i;
            while (true) {
                cycle_id[v] = color;
                v = f[v];
                if (cycle_id[v] == color) {
                    break;
                }
            }
            break;
        }
    }

    int d = 0;
    for (int i = 1; i <= n; i++) {
        int v = i;
        int count = 0;
        while (!is_in_cycle[v] ) {
            count += 1;
            v = f[v];
        }
        d = max(d, count);
    }

    for (int i = 1; i <= n; i++) {
        cnt[ cycle_id[i] ] += is_in_cycle[i];
    }

    unsigned long long l = 1;
    for (int i = 1; i <= h; i++) {
        l = lcm(l, cnt[i] );
    }

    if (d == 0) {
        cout << l << "\n";
    } else {
        unsigned long long m = d / l + min(1ull, d % l);
        cout << l * m << "\n";
    }

}

int main() {
    int cases; cases = 1;
    for (int i = 1; i <= cases; i++) {
        solve();
    }
    return 0;
}