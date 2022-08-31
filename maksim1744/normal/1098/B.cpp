/*
    17.03.2019 15:50:41
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

vector< pair< char, char > > pairs({{'A', 'C'}, {'A', 'G'}, {'A', 'T'}, {'C', 'T'}, {'C', 'G'}, {'G', 'T'}});
vector< int > op({5, 3, 4, 1, 2, 0});

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector< string > table(n);
    for (int i = 0; i < n; ++i) {
        cin >> table[i];
    }
    int ans = n * m + 1;
    vector< string > best;
    bool tr = false;
    for (int iii = 0; iii < 2; ++iii) {
        vector< vector< int > > cnt(6, vector< int >(n));
        vector< vector< bool > > pick(6, vector< bool >(n));
        int ind = 0;
        for (auto [c1, c2] : pairs) {
            for (int i = 0; i < n; ++i) {
                int k1 = 0, k2 = 0;
                for (int j = 0; j < m; ++j) {
                    if (j % 2 == 0) {
                        if (table[i][j] != c1) ++k1;
                        if (table[i][j] != c2) ++k2;
                    } else {
                        if (table[i][j] != c1) ++k2;
                        if (table[i][j] != c2) ++k1;
                    }
                }
                // show(k1, k2);
                if (k1 < k2) pick[ind][i] = true;
                else pick[ind][i] = false;
                cnt[ind][i] = min(k1, k2);
            }
            show(ind, cnt[ind]);
            ++ind;
        }
        vector< int > sm(6, 0);
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j % 2 == 0)
                    sm[i] += cnt[i][j];
                else
                    sm[i] += cnt[op[i]][j];
            }
        }
        show(sm);
        int ib = min_element(sm.begin(), sm.end()) - sm.begin();
        show(ib);
        if (ans > sm[ib]) {
            tr = iii == 1;
            ans = sm[ib];
            best = table;
            for (int i = 0; i < n; ++i) {
                int ii = ib;
                if (i % 2 == 1) ii = op[ib];
                for (int j = 0; j < m; ++j) {
                    if (pick[ii][i] == (j % 2 == 0)) {
                        best[i][j] = pairs[ii].first;
                    } else {
                        best[i][j] = pairs[ii].second;
                    }
                }
            }
        }
        if (iii == 0) {
            vector< string > transpose(m, string(n, ' '));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    transpose[j][i] = table[i][j];
                }
            }
            swap(table, transpose);
            swap(m, n);
        }
    }
    if (tr) {
        vector< string > transpose(m, string(n, ' '));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                transpose[j][i] = best[i][j];
            }
        }
        swap(best, transpose);
        swap(m, n);
    }
    show(ans);
    for (auto& line : best) {
        cout << line << '\n';
    }
    return 0;
}