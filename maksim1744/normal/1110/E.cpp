/*
    07.02.2019 17:50:46
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#include "C:/C++ libs/print.h"
#define show(x) cout << "     " << #x << " = " << to_string(x) << endl;
#else
#define show(x) 42;
#define print(x) 42;
#define printTree(x) 42;
#define printMatrix(x) 42;
#endif

int main() {
    int n;
    cin >> n;
    vector< int > a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    if (a[0] != b[0] || a.back() != b.back()) {
        cout << "No\n";
        return 0;
    }
    vector< int > da(n - 1), db(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        da[i] = a[i + 1] - a[i];
        db[i] = b[i + 1] - b[i];
    }
    sort(da.begin(), da.end());
    sort(db.begin(), db.end());
    for (int i = 0; i < n - 1; ++i) {
        if (da[i] != db[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}