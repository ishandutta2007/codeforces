#include <bits/stdc++.h>

using namespace std;

int a[10][10], b[10][10], c[10][10];

bool ok (int n) {
    bool f = 1;
    for (int i = 0; f && i < n; ++i)
        for (int j = 0; f && j < n; ++j)
            if (a[i][j] != b[i][j])
                f = 0;
    return f;
}

void rot (int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            c[j][n - i - 1] = a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = c[i][j];
}

void fliph (int n) {
    for (int i = 0; i < (n / 2); ++i)
        for (int j = 0; j < n; ++j)
            swap(a[j][i], a[j][n - i - 1]);
}

void flipv (int n) {
    for (int i = 0; i < (n / 2); ++i)
        for (int j = 0; j < n; ++j)
            swap(a[i][j], a[n - i - 1][j]);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j)
            a[i][j] = s[j];
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j)
            b[i][j] = s[j];
    }
    for (int i = 0; i < 4; ++i) {
        if (ok(n)) {
            cout << "Yes" << endl;
            return 0;
        }
        fliph(n);
        if (ok(n)) {
            cout << "Yes" << endl;
            return 0;
        }
        fliph(n);
        flipv(n);
        if (ok(n)) {
            cout << "Yes" << endl;
            return 0;
        }
        flipv(n);
        rot(n);
    }
    cout << "No" << endl;
    return 0;
}