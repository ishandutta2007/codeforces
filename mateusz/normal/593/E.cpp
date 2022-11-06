#include <bits/stdc++.h>

using namespace std;

const int N = 20, M = 1000000007;

const int dx[5] = {0, 0, 0, 1, -1};
const int dy[5] = {0, 1, -1, 0, 0};

int n, m, k, q, type, x, y, t;

struct Matrix {
    int A[N + 5][N + 5];
};

inline int cell(int x, int y) {
    return x * m + y;
}

Matrix initMatrix() {
    Matrix ret;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            ret.A[i][j] = 0;
        }
    }
    for (int i = 0; i < k; i++) {
        ret.A[i][i] = 1;
    }
    return ret;
}

Matrix initEdgeMatrix() {
    Matrix ret;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            ret.A[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 5; k++) {
                int xx = i + dx[k];
                int yy = j + dy[k];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                    ret.A[cell(i, j)][cell(xx, yy)] = true;
                }
            }
        }
    }
    return ret;
}

inline void add(int &w, int u) {
    w += u;
    if (w >= M) {
        w -= M;
    }
}

Matrix mul(Matrix a, Matrix b) {
    Matrix ret;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            ret.A[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < k; l++) {
                ret.A[i][j] = (ret.A[i][j] + (long long)a.A[i][l] * b.A[l][j]) % M;
            }
        }
    }

    return ret;
}

Matrix power(Matrix a, int l) {
    Matrix ret = initMatrix();
    while (l >= 1) {
        if (l % 2 == 1) {
            ret = mul(ret, a);
        }
        a = mul(a, a);
        l /= 2;
    }
    return ret;
}

void setCat(Matrix &a, int x, int y, int value) {
    for (int i = 0; i < 5; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
            a.A[cell(xx, yy)][cell(x, y)] = value;
        }
    }
}

int main() {

    scanf("%d %d %d", &n, &m, &q);
    k = n * m;
    Matrix curResult = initMatrix();
    Matrix edgeMatrix = initEdgeMatrix();

    int lastCat = 1;
    for (int i = 1; i <= q; i++) {
        scanf("%d %d %d %d", &type, &x, &y, &t);
        x--;
        y--;
        t--;
        if (type == 1) {
            curResult = mul(curResult, power(edgeMatrix, t - lastCat + 1));
            printf("%d\n", curResult.A[0][cell(x, y)]);
            lastCat = t + 1;
        } else {
            if (type == 3) {
                t++;
            }
            curResult = mul(curResult, power(edgeMatrix, t - lastCat));
            lastCat = t;
            setCat(edgeMatrix, x, y, (type - 1) / 2);
        }
    }

    return 0;
}