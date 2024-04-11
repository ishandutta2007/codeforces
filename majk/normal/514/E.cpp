#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
constexpr int MOD = 1000000007;
constexpr int M = 101;
int a[M][M];
int p[M][M];
int e[M][M];

void mult(int x[][M], int y[][M], int z[][M]) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            e[i][j] = 0;
            for (int k = 0; k < M; ++k) {
                e[i][j] = (ll(x[i][k]) * y[k][j] + e[i][j]) % MOD;
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            z[i][j] = e[i][j];
        }
    }
}

void print(int a[][M]) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int N, X; cin >> N >> X;
    vector<int> D(M, 0);
    for (int i = 0; i < N; ++i) {
        int d; cin >> d;
        D[d-1]++;
    }
    D[M-1] = 1;

    for (int i = 0; i < M; ++i) {
        p[i][i] = 1;
        a[i][0] = D[i];
        if (i != 0 && i != M-1) a[i-1][i] = 1;
    }
    a[M-1][M-1] = 1;


    while (X) {
        if (X&1) mult(p, a, p);
        mult(a, a, a);
        X /= 2;
    }

    cout << (p[0][0] + p[M-1][0])%MOD << endl;
}