/*
    21.10.2018 11:14:09
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector< int > a(n - 1), b(n - 1);
    for (auto& item : a) {
        cin >> item;
    }
    for (auto& item : b) {
        cin >> item;
    }
    vector< int > t(n, 0);
    for (int iii = 0; iii < 2; ++iii) {
        vector< int > t0(n, -1);
        for (int i = 0; i < n - 1; ++i) {
            // print(t0);
            if (a[i] % 2 == 0 && b[i] % 2 == 0) {
                if (t0[i] == 1) {
                    cout << "NO\n";
                    return 0;
                } else {
                    t0[i] = 0;
                    t0[i + 1] = 0;
                }
            } else if (a[i] % 2 == 1 && b[i] % 2 == 1) {
                if (t0[i] == 0) {
                    cout << "NO\n";
                    return 0;
                } else {
                    t0[i] = 1;
                    t0[i + 1] = 1;
                }
            }
            // print(t0);
        }
        int lastm1 = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] % 2 == 1 && b[i] % 2 == 0) {
                if (t0[i] == -1) {
                    lastm1 = i;
                    continue;
                }
                if (t0[i + 1] != 1 - t0[i] && t0[i + 1] != -1) {
                    cout << "NO\n";
                    return 0;
                }
                t0[i + 1] = 1 - t0[i];
            } else if (a[i] % 2 == 0 && b[i] % 2 == 1) {
                cout << "NO\n";
                return 0;
            }
        }
        if (lastm1 == n - 2) {
            if (t0[n - 1] == -1) {
                t0[n - 1] = 1;
            }
        }
        for (int i = lastm1; i >= 0; --i) {
            t0[i] = 1 - t0[i + 1];
        }
        for (int i = 0; i < n; ++i) {
            if (iii == 1) {
                t0[i] *= 2;
            }
            t[i] += t0[i];
            if (i + 1 < n) {
                a[i] /= 2;
                b[i] /= 2;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << t[i] << ' ';
    }
    cout << '\n';
    return 0;
}