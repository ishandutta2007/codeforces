#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}
const int nax = 5e5 + 10;
int fac[nax];
int n;
int deg[nax];

namespace FFT {
    long long modpow(long long a, long long b){
        long long ans = 1;
        while (b > 0){
            if (b % 2 == 1){
                ans *= a;
                ans %= MOD;
            }
            a *= a;
            a %= MOD;
            b /= 2;
        }
        return ans;
    }
    long long modinv(long long a){
        return modpow(a, MOD - 2);
    }
    vector<long long> ntt(vector<long long> A, bool inv){
        int N = A.size();
        long long r = 3;
        if (inv){
            r = modinv(r);
        }
        vector<long long> B(N);
        for (int i = N / 2; i > 0; i /= 2){
            long long z = modpow(r, (MOD - 1) / (N / i));
            long long z2 = 1;
            for (int j = 0; j < N; j += i * 2){
                for (int k = 0; k < i; k++){
                    A[i + j + k] *= z2;
                    A[i + j + k] %= MOD;
                    B[j / 2 + k] = (A[j + k] + A[i + j + k]) % MOD;
                    B[N / 2 + j / 2 + k] = (A[j + k] - A[i + j + k] + MOD) % MOD;
                }
                z2 = z2 * z % MOD;
            }
            swap(A, B);
        }
        if (inv){
            int Ninv = modinv(N);
            for (int i = 0; i < N; i++){
                A[i] = A[i] * Ninv % MOD;
            }
        }
        return A;
    }
    vector<long long> convolution(vector<long long> A, vector<long long> B){
        int deg = A.size() + B.size() - 1;
        int N = 1;
        while (N < deg){
            N *= 2;
        }
        A.resize(N);
        B.resize(N);
        A = ntt(A, false);
        B = ntt(B, false);
        vector<long long> ans(N);
        for (int i = 0; i < N; i++){
            ans[i] = A[i] * B[i] % MOD;
        }
        ans = ntt(ans, true);
        return ans;
    }
    vector<long long> operator +(vector<long long> A, vector<long long> B){
      int N = A.size();
      for (int i = 0; i < N; i++){
        A[i] += B[i];
        if (A[i] >= MOD){
          A[i] %= MOD;
        }
      }
      return A;
    }
}
/**
    well, maybe I just have to copy fft from somewhere?
    Or just use same old observation no more than sqrt distinct number of d

*/


struct Poly {
    vector <long long> poly;
    bool operator <(const Poly &other) const {
        return poly.size() > other.poly.size();
    }
    Poly(vector <long long> &other) {
        poly.swap(other);
    }
};
int topQ;
int cnt_deg[nax];
int inv_fac[nax];

int C(int n, int r) {
    if (r > n) return 0;
    return 1LL * fac[n] * inv_fac[n - r] % MOD * inv_fac[r] % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    fac[0] = 1;
    for (int i = 1 ; i <= n ; ++ i)
        fac[i] = mul(fac[i - 1], i);
    inv_fac[n] = power(fac[n], MOD - 2);
    for (int i = n - 1 ; i >= 0 ; -- i)
        inv_fac[i] = mul(inv_fac[i + 1], i + 1);

    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        deg[u] += 1;
        deg[v] += 1;
    }
    for (int i = 2 ; i <= n ; ++ i) {
        deg[i] -= 1;
        cnt_deg[deg[i]] ++;
    }
    cnt_deg[deg[1]]++;
    priority_queue<Poly> pq;
    int deg_0 = cnt_deg[0];

    for (int i = 1 ; i <= n ; ++ i) {
        if (cnt_deg[i]) {
            int d = sub(0, i),  m = cnt_deg[i];
            /// (x - d) ^ m
            vector <long long> bar(m + 1);
            int cur_d = 1;
            for (int i = m ; i >= 0 ; -- i) {
                bar[i] = mul(C(m, i), cur_d);
                cur_d = mul(cur_d, d);
            }
            //bar[m] = 1;

            pq.push(Poly(bar));
        }
    }


    while (pq.size() > 1) {
        auto A = pq.top().poly;
        pq.pop();
        auto B = pq.top().poly;
        pq.pop();
        auto result = FFT::convolution(A, B);
        pq.push(Poly(result));
    }

    vector <long long> p = pq.top().poly;

    int ans = 0;
    for (int i = 0 ; i < int(p.size()) ; ++ i) {
        plusle(ans, mul(fac[i + deg_0], p[i]));
    }
    cout << ans << '\n';
}