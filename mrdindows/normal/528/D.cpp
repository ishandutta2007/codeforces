#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#pragma GCC target("avx2")
#pragma GCC target("fma")
#include <bits/stdc++.h>
namespace {
const bool TEST_GEN = 0;
const int K = 19, N = 1 << K;
const double pi = std::acos(-1.0);
struct Complex {
    double x, y;
    Complex(double x_ = 0, double y_ = 0) : x(x_), y(y_) { }
    Complex operator+(Complex rhs) const { return Complex(x+rhs.x,y+rhs.y); }
    Complex operator-(Complex rhs) const { return Complex(x-rhs.x,y-rhs.y); }
    Complex operator*(Complex rhs) const { return Complex(x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x); }
    Complex conj() const { return Complex(x, -y); }
    Complex& operator+=(Complex rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
};
alignas(64) Complex root[N];
alignas(64) int rev[N];
void init() {
    for (int j = 0; j < N; j++) {
        int res = 0;
        for (int bit = 0; bit < K; ++bit) {
            res = res * 2 + ((j >> bit) & 1);
        }
        rev[j] = res;
    }
    for (int k = 1; k < N; k *= 2) {
        Complex tmp = {std::cos(pi/k), std::sin(pi/k)};
        root[k] = 1;
        for (int i = 1; i < k; i++) {
            root[k + i] = ((i % 2) ? tmp : 1) * root[(k+i)/2];
        }
    }
}
 
template<int low, int high, typename T>
void FFT(T* __restrict f) {
    for (int begin = 0; begin < N; begin += high) {
        for (int k = low; k < high; k *= 2) {
            for (int i = begin; i < begin + high; i += 2 * k) {
                #pragma GCC ivdep
                for (int j = 0; j < k; j++) {
                    auto tmp = root[k+j] * f[i+j+k];
                    f[i+j+k] = f[i+j] - tmp;
                    f[i+j] += tmp;
                }
            }
        }
    }
}
 
template<typename T>
void FFT(T* __restrict f) {
    FFT<1, 512>(f); //dfd
    FFT<512, 512*32>(f);
    FFT<512*32, N>(f);
}
 
alignas(64) Complex fa[N], fc[N];
template<bool ifft, typename T>
void mult(const T * __restrict a, const T * __restrict b, T * __restrict c) {
    for (int i = 0; i < N; i++) { fa[rev[i]] = Complex(a[i], b[i]); }
    FFT(fa);
    for (int i = 0; i < N; i++) {
        auto fa_i = Complex( 0.5,  0.0) * (fa[i] + (fa[(N-i) % N]).conj());
        auto fb_i = Complex( 0.0, -0.5) * (fa[i] - (fa[(N-i) % N]).conj());
        fc[i] += fa_i * fb_i;
    }
    if (!ifft) return;
    for (int i = 0; i < N; i++) { fa[rev[i]] = fc[i]; }
    FFT(fa);
    std::reverse(fa+1, fa+N);
    for (int i = 0; i < N; i++) c[i] = (int)((fa[i]).x / N + 0.5);
    //std::fill(fc,fc+N,Complex(0,0));
}
 
alignas(64) int a[N], b[N];
 
template<char ch, bool ifft>
void solve(
    char * __restrict A, const int n,
    char * __restrict B, const int m,
    const int k, int * __restrict res)
{
    std::memset(a,0,sizeof a);
    for (int i = 0; i < n; i++) {
        if (A[i] == ch) {
            a[std::max(i-k,0)]++;
            a[std::min(i+k+1,n)]--;
        }
    }
    for (int i = 0, bal = 0; i < N; i++) a[i] = (bal += a[i]) > 0;
    for (int i = 0; i < m; i++) b[i] = (B[i] == ch);
    mult<ifft>(a,b,res);
}
 
}
char A[N], B[N];
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    init();
    int n, m, k;
    if (!TEST_GEN) { // kuke
        scanf("%d%d%d\n", &n, &m, &k);
        gets(A);
        gets(B);
    }
    // ------- test gen -------
    if (TEST_GEN) {
        n = (int)2e5; 
        m = (int)1e5;
        k = 100;
        for (int i = 0; i < n; i++) A[i] = "ACGT"[std::rand() & 3];
        for (int i = 0; i < m; i++) B[i] = "ACGT"[std::rand() & 3];
    }
    // ------- solution -------
    alignas(64) static int answer[N];
    std::reverse(B, B + m);
    solve<'A',0>(A,n,B,m,k,answer);
    solve<'C',0>(A,n,B,m,k,answer);
    solve<'G',0>(A,n,B,m,k,answer);
    solve<'T',1>(A,n,B,m,k,answer);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (answer[i] >= m);
    }
    std::cout << ans << std::endl;
    return 0;
}