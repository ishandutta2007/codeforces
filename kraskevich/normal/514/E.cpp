#include <bits/stdc++.h>

using namespace std;

const int N = 100;

const int MOD = 1000 * 1000 * 1000 + 7;

struct Matrix {
    int a[N][N];
    
    Matrix() {
    for (int i = 0; i < N; i++)
        fill(a[i], a[i] + N, 0);
    }
    
    Matrix& operator=(const Matrix& m) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        a[i][j] = m.a[i][j];
    return *this;
    }
    
    Matrix(const Matrix& m) {
    *this = m;
    }
    
    Matrix operator*(const Matrix &m) const {
    Matrix res;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
        for (int k = 0; k < N; k++)
            res.a[i][j] = (res.a[i][j] + a[i][k] * 1ll * m.a[k][j]) % MOD;
    return res;
    }
    
    Matrix operator+(const Matrix &m) const {
    Matrix res;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        res.a[i][j] = (a[i][j] + m.a[i][j]) % MOD;
     return res;
    }
};

Matrix identity() {
    Matrix res;
    for (int i = 0; i < N; i++)
    res.a[i][i] = 1;
    return res;
}

pair<Matrix, Matrix> seriesSum(const Matrix &m, int n) {
    if (n == 0)
    return make_pair(identity(), identity());
    if (n % 2 == 1) {
    auto res = seriesSum(m, n / 2);
    res.first = res.first + res.first * res.second * m;
    res.second = res.second * res.second * m;
    return res;
    }
    auto res = seriesSum(m, n - 1);
    res.second = res.second * m;
    res.first = res.first + res.second;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    Matrix res;
    for (int i = 1; i < N; i++)
    res.a[i][i - 1] = 1;
    for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    res.a[0][a - 1]++;
    }
    res = seriesSum(res, x).first;
    cout << res.a[0][0] << endl;
    return 0;
}