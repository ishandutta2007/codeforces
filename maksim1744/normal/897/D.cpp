/*
    05.11.2018 16:54:23
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n, m, c;
    cin >> n >> m >> c;
    vector< int > a(n, -1);
    int t = 0;
    while (t < m) {
        ++t;
        int p;
        cin >> p;
        --p;
        //  (0, 0) - (c - 1, n - 1)
        //  y / x = (n - 1) / (c - 1)
        int ind = 0;
        if (c != 1) {
            ind = p * (n - 1) / (c - 1);
        }
        // int ind = min(n - 1, (p - 1) * ((n + c - 1) / c) + (p - 1) * ((n + c - 1) / c) / c);
        // int ind = (p - 1) * n / c;
        // cout << "ind = " << ind << '\n';
        if (c == 2 && p == 2) {
            ind = n - 1;
        }
        if (a[ind] == -1) {
            cout << ind + 1 << endl;
            a[ind] = p;
        } else {
            int cl = 0, cr = 0;
            for (int i = 0; i < ind; ++i) {
                if (a[i] == -1) {
                    ++cl;
                }
            }
            for (int i = ind + 1; i < n; ++i) {
                if (a[i] == -1) {
                    ++cr;
                }
            }
            // cout << "cl, cr = " << cl << ", " << cr << endl;
            if (cl > cr) {
                while (ind >= 0 && (a[ind] >= p)) {
                    --ind;
                }
                if (ind == -1) {
                    ind = 0;
                }
            } else {
                while (ind < n && (a[ind] <= p) && a[ind] != -1) {
                    ++ind;
                }
                if (ind == n) {
                    --ind;
                }
            }
            a[ind] = p;
            cout << ind + 1 << endl;
        }

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] == -1) {
                ok = false;
                break;
            }
            if (i != 0 && a[i - 1] > a[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    return 0;
}