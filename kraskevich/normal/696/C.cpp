#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000 * 1000 * 1000 + 7;

struct Matrix {
    int a[4];
    
    Matrix() {
        fill(a, a + 4, 0);
    }

    Matrix operator*(const Matrix& m) const {
        Matrix res;
        res.a[0] = (a[0] * 1ll * m.a[0] + a[1] * 1ll * m.a[2]) % MOD;
        res.a[1] = (a[0] * 1ll * m.a[1] + a[1] * 1ll * m.a[3]) % MOD; 
        res.a[2] = (a[2] * 1ll * m.a[0] + a[3] * 1ll * m.a[2]) % MOD;
        res.a[3] = (a[2] * 1ll * m.a[1] + a[3] * 1ll * m.a[3]) % MOD;
        return res;
    }
};

long long binPow(long long x, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n % 2)
            res = x * res % MOD;
        x = x * x % MOD;
        n /= 2;
    }
    return res;
}

Matrix binPow(Matrix x, long long n) {
    Matrix res;
    res.a[0] = 1;
    res.a[3] = 1;
    while (n > 0) {
        if (n % 2)
            res = res * x;
        x = x * x;
        n /= 2;
    }
    return res;
}

int main() {
    int k;
    scanf("%d", &k);
    vector<long long> a(k);
    bool any = false;
    for (int i = 0; i < k; i++) {
        scanf("%I64d", &a[i]);
        if (a[i] != 1)
            any = true;
    }
    if (!any) {
        cout << "0/1" << endl;
        return 0;
    }
    Matrix m;  
    m.a[0] = m.a[2] = 1;
    m.a[1] = 2;
    Matrix cur;
    cur.a[0] = cur.a[3] = 1;
    long long curPow = 2;
    for (int i = 0; i < k; i++) {
        cur = binPow(cur, a[i]);
        cur = cur * binPow(m, a[i] - 1);
        curPow = binPow(curPow, a[i]);
    }
    printf("%d/%I64d\n", cur.a[2], (curPow * (MOD + 1) / 2) % MOD);                        
    return 0;
}