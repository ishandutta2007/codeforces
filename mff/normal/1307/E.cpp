#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <random>
#include <string>

#define endl '\n'

using namespace std;

const int mod = 1000000007;

void add(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> s(n);
    vector<int> ts(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        s[i]--;
        ts[s[i]]++;
    }

    vector<vector<int>> a(n, vector<int>(n + 1));

    for (int i = 0; i < m; ++i) {
        int f, h; cin >> f >> h;
        f--;
        a[f][h]++;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] += a[i][j - 1];
        }
    }

    int answer = 0;
    int best = 0;

    vector<int> cs(n);

    for (int i = 0; i < n; ++i) {
        int si = s[i];
        cs[si]++;

        int cur = 1;
        int total = 0;

        auto mul = [&](int f) {
            cur = 1LL * cur * f % mod;
        };

        int csi = cs[si];
        int tsi = ts[si];

        // cout << "step: " << i << endl;

        if (a[si][csi] > a[si][csi - 1]) { // cow here
            total++;

            if (a[si][tsi - csi] - (2 * csi <= tsi)) {
                total++;
                mul(a[si][tsi - csi] - (2 * csi <= tsi));
            }

            for (int j = 0; j < n; ++j) {
                if (j == s[i]) continue;

                int A = a[j][cs[j]];
                int b = a[j][ts[j] - cs[j]];

                if (A > b) swap(A, b);

                if (b == 0) {

                } else if (A == 0) {
                    total++;
                    mul(b);
                } else if (b == 1) {
                    total++;
                    mul(2);
                } else {
                    total += 2;
                    mul(A);
                    mul(b - 1);
                }
            }
        }

        if (total > best) {
            best = total;
            answer = 0;
        }

        if (total == best) {
            add(answer, cur);
        }

        // cout << total << " " << cur << endl;
        // cout << best << " " << answer << endl;
    }

    int total = 0;
    int cur = 1;

    for (int i = 0; i < n; ++i) {
        if (a[i][ts[i]]) {
            total++;
            cur = 1LL * cur * a[i][ts[i]] % mod;
        }
    }

    if (total > best) {
        best = total;
        answer = 0;
    }

    if (total == best) {
        add(answer, cur);
    }

    if (best == 0) answer = 1;

    cout << best << " " << answer << endl;

    return 0;
}