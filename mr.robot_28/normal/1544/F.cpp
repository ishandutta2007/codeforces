#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
using namespace std;
const int mod = 31607;
const int N = 22;
int power(int a, int b)
{
    int res = 1;
    while(b > 0)
    {
        if(b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
void add(int &a, int b)
{
    a += b;
    if(a >= mod)
    {
        a -= mod;
    }
}
const int K  = 1 << 23;
void and_convolution(int* v)
{
    for(int step = K; step > 1; step /= 2)
    {
        for(int start = 0; start < K; start += step)
        {
            for(int w = 0; w < step / 2; w++)
            {
                add(v[w + start], v[start + w + step / 2]);
            }
        }
    }
}
void inverse_and_convolution(int *v)
{
    for(int step = K; step > 1; step /= 2)
    {
        for(int start = 0; start < K; start += step)
        {
            for(int w = 0; w < step / 2; w++)
            {
                add(v[start + w], mod - v[start + w + step / 2]);
            }
        }
    }
}
int a[N][N], b[N][N], inv_a[N][N], inv_b[N][N];
int to[1 << 21];
int mass[1 << 21];
int mask[1 << 23];
int cur[1 << 23];
int n;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i =0; i < 21; i++)
    {
        to[1 << i] = i;
    }
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            a[i][j] = a[i][j] * power(10000, mod - 2) % mod;
            b[i][j] = (mod + 1 - a[i][j]) % mod;
            inv_a[i][j] = power(a[i][j], mod - 2);
            inv_b[i][j] = power(b[i][j], mod - 2);
        }
    }
    mask[(1 << (n + 2)) - 1] = 1;
    and_convolution(mask);
    for(int i = 0; i < n; i++)
    {
        fill(cur, cur + (1 << 23), 0);
        for(int m = 0; m < (1 << n) - 1; m++)
        {
            int now = m;
            if(m == 0)
            {
                mass[0] = 1;
                for(int j = 0; j < n; j++)
                {
                    mass[0] = mass[0] * b[i][j] % mod;
                }
            }
            else
            {
                int v = to[m & -m];
                mass[m] = mass[m ^ (1 << v)];
                mass[m] =  mass[m] * inv_b[i][v] % mod;
                mass[m] =  mass[m] * a[i][v] % mod;
            }
            now ^= ((m >> i) & 1) << n;
            now ^= ((m >> (n - i - 1)) & 1) << (n + 1);
            cur[now] += mass[m];
            if(cur[now] >= mod)
            {
                cur[now] -= mod;
            }
        }
        and_convolution(cur);
        for(int msk = 0; msk < K; msk++)
        {
            mask[msk] = mask[msk] * cur[msk] % mod;
        }
    }
    inverse_and_convolution(mask);
    int res = mask[0];
    res = (1 - res + mod) % mod;
    cout << res;
    return 0;
}