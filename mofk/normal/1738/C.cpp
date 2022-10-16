#include<bits/stdc++.h>

using namespace std;

int f[105][105][2][2];
int g[105][105][2][2];

int cal(int a, int b, int s, int t) {
    int &res = f[a][b][s][t];
    if (g[a][b][s][t]) return res;
    g[a][b][s][t] = 1;
    if (a == 0 && b == 0) {
        if (t == 0) return res = (s == 0);
        return res = (s != 0);
    }
    if (!t) {
        res = 0;
        if (a && !cal(a - 1, b, s, t ^ 1)) res = 1;
        if (b && !cal(a, b - 1, s ^ 1, t ^ 1)) res = 1;
    }
    else {
        res = 0;
        if (a && !cal(a - 1, b, s, t ^ 1)) res = 1;
        if (b && !cal(a, b - 1, s, t ^ 1)) res = 1;
    }
    return res;
}

int main(void) {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        int a = 0, b = 0, x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x % 2 == 0) ++a; else ++b;
        }
        cout << (cal(a, b, 0, 0) ? "Alice" : "Bob") << endl;
    }
    return 0;
}