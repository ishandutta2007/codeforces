#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int MOD = 998244353 ;
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if (a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}


namespace FFT {

    int modinv(int a){
        return power(a, MOD - 2);
    }

    const int R = 3;
    const int INV_R = power(R, MOD - 2);

    vector<int> ntt(vector<int> A, bool inv){
        int N = A.size();
        int r = R;
        if (inv){
            r = INV_R;
        }
        vector<int> B(N);
        for (int i = N / 2; i > 0; i /= 2){
            int z = power(r, (MOD - 1) / (N / i));
            int z2 = 1;
            for (int j = 0; j < N; j += i * 2){
                for (int k = 0; k < i; k++){
                    A[i + j + k] = 1ll * A[i + j + k] * z2 % MOD;
                    B[j / 2 + k] = add(A[j + k], A[i + j + k]);
                    B[N / 2 + j / 2 + k] = sub(A[j + k], A[i + j + k]);
                }
                z2 = 1ll * z2 * z % MOD;
            }
            A.swap(B);
        }
        if (inv){
            int Ninv = modinv(N);
            for (int i = 0; i < N; i++){
                A[i] = 1ll * A[i] * Ninv % MOD;
            }
        }
        return A;
    }
    vector<int> convolution(vector<int> A, vector<int> B){
        int deg = A.size() + B.size() - 1;
        int N = 1;
        while (N < deg){
            N *= 2;
        }
        A.resize(N);
        B.resize(N);
        A = ntt(A, false);
        B = ntt(B, false);
        vector<int> ans(N);
        for (int i = 0; i < N; i++){
            A[i] = 1ll * A[i] * B[i] % MOD;
        }
        A = ntt(A, true);
        return A;
    }
}

int n, k, f;


vector <int> solve(int d) {
    if (d == 0) {
        vector <int> x(k + 1, 1);
        return x;
    }

    vector <int> x = solve(d - 1);
    x = FFT::convolution(x, x);

    int sum_all = 0;
    for (int i : x) {
        plusle(sum_all, i);
    }

    vector <int> f(k + 1, 0);

    int sum = 0;

    for (int i = 0 ; i <= k ; ++ i) {
        f[i] = sub(sum_all, sum);
        f[i] = add(f[i], mul(k - i, x[i]));
        plusle(sum, x[i]);
    }
    /**
        so the main mistake is maximum push if <= 2 * k
        so the convolution should take up to 2*k
        and summation of f(1..k) is not enough to cover whole thing
    */

    return f;
}

int main() {
    cin >> n >> k >> f;

    vector <int> ans = solve(n - 1);


    ans.resize(f + k + 1);
    int res = 0;
    for (int i = 0 ; i <= f ; ++ i) {
        plusle(res, mul(ans[i], ans[f - i]));
    }


    cout << res << '\n';
}