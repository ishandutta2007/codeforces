#include <bits/stdc++.h>
using namespace std; 

const int D = 10; 
const int X = 100 + 1;

const int mod = 1e9 + 7; 

inline int sum(int a, int b) { 
    int c = a + b; 
    if (c >= mod)
        c -= mod; 
    return c;
}

// sum(a, mod - b) | a + mod - b < 2 * mod -> 0 <= c < mod

inline int mul(int a, int b) { 
    return 1ll * a * b % mod; 
}

int bpow(int a, int b) { 
    int r = 1;
    for( ; b ; b /= 2) { 
        if (b & 1) 
            r = mul(r, a);
        a = mul(a, a);
    }
    return a;
}



int cnt[D]; 

typedef int Mat[X][X];

int n, k, b, x;


void mul(Mat a, Mat b, Mat c) { 
    for(int i = 0; i < x; i++) 
        for(int j = 0; j < x; j++) 
            c[i][j] = 0; 
    for(int i = 0; i < x; i++)
        for(int j = 0; j < x; j++) 
            for(int k = 0; k < x; k++) 
                c[i][k] = sum(c[i][k], mul(a[i][j], b[j][k]));
}

Mat A, R, T;

int main() { 
    cin >> n >> b >> k >> x; 

    for(int i = 0; i < n; i++) {
        int d;
        cin >> d;
        cnt[d]++;
    }

    for(int i = 0; i < x; i++) 
        for(int d = 0; d < 10; d++) 
            A[i][(i*10+d) % x] += cnt[d];

    for(int i = 0; i < x; i++) 
        R[i][i] = 1;

    // R = 1
    // A = ..

    for( ; b ; b /= 2) { 
        if( b & 1 ) {
            // r = r * a
            mul(R, A, T);
            swap(R, T);
        }
        mul(A, A, T);
        swap(A, T);
    }

    cout << R[0][k] << endl;
}