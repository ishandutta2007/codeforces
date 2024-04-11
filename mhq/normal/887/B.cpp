#include <bits/stdc++.h>
using namespace std;
int n;
bool a[10][3];
vector < int > k(10, 0);
bool c[1000];
bool check(int x) {
    if (x >= k[n]) return false;
    if (x < k[n - 1]) {
        for (int i = 0; i < 10; i++) {
            if (check((10 * x + i))) return true;
        }
        return false;
    }
    vector < int > t;
    while (x > 0) {
        t.push_back(x % 10);
        x = x / 10;
    }
    int m[5] = {0, 1, 2, 3, 4};
        bool mar = true;
        for (int i = 0; i < n; i++) {
            if (!a[t[i]][m[i]]) mar = false;
        }
    if (mar) return true;
    while (next_permutation(m, m + n)) {
        bool mark = true;
        for (int i = 0; i < n; i++) {
            if (!a[t[i]][m[i]]) mark = false;
        }
        if (mark) return true;
    }
    return false;
}
int main() {
    cin >> n;
    int t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> t;
            a[t][i] = true;
        }
    }
    k[0] = 1; k[1] = 10; k[2] = 100; k[3] = 1000;
    for (int i = 1; ;i++) {
        if (!check(i)) {
            cout << i - 1;
            return 0;
        }
    }
    return 0;
}