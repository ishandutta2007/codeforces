/*
    08.03.2019 12:07:06
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

const int mxn = 1005;
array< array< int, mxn >, mxn > r;
array< array< int, mxn >, mxn > c;
array< int, mxn > rm, cm;

array< int, mxn > vs;
int ivs;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> r[i][j];
            c[i][j] = r[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        set< int > s;
        for (int j = 0; j < m; ++j) {
            s.insert(r[i][j]);
        }
        ivs = -1;
        // show(s);
        for (auto item : s) {
            vs[++ivs] = item;
        }
        rm[i] = ivs + 1;
        // show(vs);
        for (int j = 0; j < m; ++j) {
            r[i][j] = distance(vs.begin(), lower_bound(vs.begin(), vs.begin() + ivs + 1, r[i][j]));
        }
    }
    for (int i = 0; i < m; ++i) {
        set< int > s;
        for (int j = 0; j < n; ++j) {
            s.insert(c[j][i]);
        }
        ivs = -1;
        for (auto item : s) {
            vs[++ivs] = item;
        }
        cm[i] = ivs + 1;
        for (int j = 0; j < n; ++j) {
            c[j][i] = distance(vs.begin(), lower_bound(vs.begin(), vs.begin() + ivs + 1, c[j][i]));
        }
    }
    // show(r);
    // show(c);
    // show(rm);
    // show(cm);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (r[i][j] <= c[i][j]) {
                cout << max(rm[i] + c[i][j] - r[i][j], cm[j]) << ' ';
            } else {
                cout << max(rm[i], cm[j] + r[i][j] - c[i][j]) << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}