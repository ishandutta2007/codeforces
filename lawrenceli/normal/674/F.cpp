#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;

struct Mat {
    ui a[135][135];
    int p;

    Mat (int _p) : p(_p) { memset(a, 0, sizeof(a)); }
    Mat (int _p, bool id) : p(_p) {
        memset(a, 0, sizeof(a));
        if (id) for (int i = 0; i <= p; i++) a[i][i] = 1;
    }
    
    Mat operator * (Mat m) {
        Mat ret = Mat(p);
        for (int i = 0; i <= p; i++)
            for (int j = 0; j <= p; j++)
                for (int k = 0; k <= p; k++)
                    ret.a[i][k] += a[i][j] * m.a[j][k];
        return ret;
    }
};

const int maxp = 135;
const int maxq = 2000005;
const int block = 16000;

int n, p, q;
ui C[maxp][maxp];
ui dp[block][maxp];

ui gcd(ui a, ui b) {
    if (!b) return a;
    return gcd(b, a % b);
}

ui calcC(ui a, ui b) {
    if (a < b) return 0;
    vector<ui> v (b);
    for (ui i = 0; i < b; i++) v[i] = a - i;

    for (ui i = 1; i <= b; i++) {
        ui x = i;
        for (int j = 0; j < b; j++) {
            ui g = gcd(x, v[j]);
            x /= g;
            v[j] /= g;
        }

        assert(x == 1);
    }

    ui ret = 1;
    for (int i = 0; i < b; i++) ret *= v[i];
    return ret;
}

Mat exp(Mat b, int e) {
    Mat ret = Mat(b.p, 1);
    for (int i = 20; i >= 0; i--) {
        ret = ret * ret;
        if (e & 1<<i) ret = ret * b;
    }
    return ret;
}

int main() {
    cin >> n >> p >> q;
    p = min(p, n - 1);

    for (int i = 0; i <= p; i++)
        for (int j = 0; j <= p; j++)
            C[i][j] = calcC(n - p + i, j);

    //calc dp
    for (int j = 0; j <= p; j++) dp[0][j] = 1;
    for (int i = 1; i < block; i++)
        for (int j = 0; j <= p; j++)
            for (int k = 0; k <= j; k++)
                dp[i][j] += dp[i - 1][k] * C[j][j - k];

    //calc mat
    Mat base = Mat(p);
    for (int i = 0; i <= p; i++)
        for (int j = 0; j <= i; j++)
            base.a[i][j] = C[i][i - j];

    base = exp(base, block);

    Mat cur = Mat(p, 1);
    ui ans = 0;
    for (ui i = 1; i <= q; i++) {
        if (i % block == 0) cur = cur * base;
        int imod = i % block;
        ui val = 0;
        for (int j = 0; j <= p; j++)
            val += cur.a[p][j] * dp[imod][j];
        ans ^= val * i;
    }

    cout << ans << '\n';
}