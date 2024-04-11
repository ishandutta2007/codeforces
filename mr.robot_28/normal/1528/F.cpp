#include<bits/stdc++.h>
using namespace std;
#define X first
#define int long long
#define Y second
#define ll long long
#define sz(a) a.size()
const int mod = 998244353;
const int xm = 18;
const int N = 3e5 + 100;
const int N1 = (1 << 18);
int C[N + 100], A[N1 + 100], B[N1 + 100], p[N1 + 100];
int W[N1+ 100];
int R[N1 + 100];
int w[N1 + 100];
int fact[N], ifact[N];
int n, k;
int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b % 2 == 0)
    {
        int t= power(a, b / 2);
        return t * t % mod;
    }
    return a * power(a, b - 1) % mod;
}
int FFTINIT(int n)
{
    W[0] = 1;
    W[1] = power(3, (mod - 1) / N1);
    for(int i = 2; i <= N1; i++)
    {
        W[i] = W[i - 1] * W[1] % mod;
    }
    int L = 1;
    while(L <= n)
    {
        L *= 2;
    }
    for(int i = 0; i < L; i++)
    {
        R[i] = (R[i >> 1] >> 1) | ((i & 1) ? (L >> 1) : 0);
      //  cout << R[i] << " ";
    }
   // cout << "\n";
    return L;
}
void DFT(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        p[R[i]] = A[i];
    }
    for(int d = 1; d < n; d <<= 1)
    {
        int len = N1 / (d << 1);
        for(int i = 0, j = 0; i < d; i++, j += len)
        {
            w[i] = W[j];
        }
        for(int l = 0; l < n; l += (d << 1))
        {
            for(int i = 0; i < d; i++)
            {
                int x = p[i + l];
                int y = p[i + l + d] * w[i] % mod;
                p[i + l] = (x + y) % mod;
                p[i + d + l] = (x - y + mod) % mod;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        A[i] = p[i];
    }
}
void IDFT(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        p[R[i]] = A[i];
    }
    for(int d = 1; d < n; d <<= 1)
    {
        int len = N1 / (d << 1);
        for(int i = 0, j = N1; i < d; i++, j -= len)
        {
            w[i] = W[j];
        }
        for(int l = 0; l < n; l += (d << 1))
        {
            for(int i = 0;i < d; i++)
            {
                int x = p[i + l];
                int y = p[i + d + l] * w[i] % mod;
                p[i + l + d] = (x - y + mod) % mod;
                p[i + l] = (x + y) % mod;
            }
        }
    }
    int inv = power(n, mod - 2);
    for(int i = 0; i < n; i++)
    {
        A[i] = p[i] * inv % mod;
    }
}
signed main()
{
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);
    cin >> n >> k;
    C[0] = fact[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        C[i] = C[i - 1] * (n - i + 1) % mod * power(i, mod - 2) % mod;
        fact[i] = fact[i - 1] * i % mod;
    }
    ifact[N] = power(fact[N], mod - 2);
    for(int i = N - 1; i >= 0; i--)
    {
        ifact[i] = ifact[i + 1] * (i + 1) % mod;
    }
    for(int i = 0; i <= k; i++)
    {
        A[i] = 1LL * power(i, k) * ifact[i] % mod;
        B[i] = ifact[i];
        if(i % 2)
        {
            B[i] = (mod - B[i]) % mod;
        }
     //   cout << power(i, k) << " " << ifact[i] << "\n";
       // cout << A[i] << " " << B[i] << "\n";
    }
    int sz = FFTINIT(2 * (k + 1));
    DFT(A, sz);
    DFT(B, sz);
    for(int i = 0; i < sz; i++)
    {
        A[i] = A[i] * B[i] % mod;
     //   cout << A[i] << "\n";
    }
    IDFT(A, sz);
    int ans = 0;
    for(int i = 1; i <= k; i++)
    {
        if(i > n)
        {
            break;
        }
      //  cout << A[i] << " " << C[i] << " " << fact[i] << " " << power(n + 1, n - i) << "\n";
        ans = (ans + 1LL * A[i] * C[i] % mod * power(n + 1, n - i) % mod * fact[i] % mod) % mod;
    }
    cout << ans;
    return 0;
}