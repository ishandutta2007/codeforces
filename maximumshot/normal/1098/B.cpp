#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

vector< vector< int > > transpose(const vector< vector< int > > &a) {
    int n = (int)a.size();
    int m = (int)a[0].size();
    vector< vector< int > > b(m, vector< int >(n));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            b[j][i] = a[i][j];
        }
    }
    return b;
}

int get_diff(const vector< vector< int > > &a, const vector< vector< int > > &b) {
    int res = 0;
    for(int i = 0;i < (int)a.size();i++) {
        for(int j = 0;j < (int)a[i].size();j++) {
            res += a[i][j] != b[i][j];
        }
    }
    return res;
}

vector< vector< int > > get_best(const vector< vector< int > > &a) {
    int n = (int)a.size();
    int m = (int)a[0].size();

    vector< vector< int > > result_mat;
    int best_diff = inf;

    for(int mask = 0;mask < (1 << 4);mask++) {
        if(__builtin_popcount(mask) != 2) continue;
        vector< int > ar[2];
        for(int i = 0;i < 4;i++) {
            ar[(mask >> i) & 1].push_back(i);
        }

        vector< vector< int > > tmp_mat;

        for(int i = 0;i < n;i++) {

            int mn_diff = inf;
            int mn_iter = -1;

            for(int iter = 0;iter < 2;iter++, swap( ar[i & 1][0], ar[i & 1][1] )) {
                int tmp_diff = 0;
                for(int j = 0;j < m;j++) {
                    int x = a[i][j];
                    int y = ar[i & 1][j & 1];
                    tmp_diff += x != y;
                }
                if(tmp_diff < mn_diff) {
                    mn_diff = tmp_diff;
                    mn_iter = iter;
                }
            }

            vector< int > row;

            for(int j = 0;j < m;j++, mn_iter ^= 1) {
                row.push_back(ar[i & 1][mn_iter]);
            }

            tmp_mat.push_back(row);
        }

        int tmp_diff = get_diff(tmp_mat, a);

        if(tmp_diff < best_diff) {
            best_diff = tmp_diff;
            result_mat = tmp_mat;
        }
    }

    return result_mat;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    string alph = "ACGT";
    map< char, int > pos_in_alph;
    for(int i = 0;i < 4;i++) pos_in_alph[ alph[i] ] = i;
    vector< vector< int > > a(n, vector< int >(m));

    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        for(int j = 0;j < m;j++) {
            a[i][j] = pos_in_alph[ s[j] ];
        }
    }

    vector< vector< int > > a2 = transpose(a);

    vector< vector< int > > b = get_best(a);
    vector< vector< int > > b2 = get_best(a2);

    if(get_diff(a, b) > get_diff(a2, b2)) {
        b = transpose(b2);
    }

//    cout << "diff = " << get_diff(a, b) << "\n";

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            printf("%c", alph[b[i][j]]);
        }
        printf("\n");
    }

    return 0;
}