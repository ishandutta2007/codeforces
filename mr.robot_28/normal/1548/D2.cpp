#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 3e6;
const int mod = 1e9 + 7;
int n, x[N], y[N];
int b[64], a[64][64];
int gcd(int x1, int y1)
{
    return y1 ? gcd(y1, x1 % y1) : x1; 
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 64; i++)
    {
        for(int j = 0; j < 64; j++)
        {
            int g1 = i >> 4;
            int x1 = (i >> 2) & 3;
            int y1 = i & 3;
            int g2 = j >> 4;
            int x2 = (j >> 2) & 3;
            int y2 = j & 3;
            if(x1 * y2 % 2 != x2 * y1 % 2)
            {
                a[i][j] = 0;
                continue;
            }
            if((x1 + x2) % 2  || (y1 + y2) % 2)
            {
                a[i][j] = 0;
                continue;
            }
            int ar = x1 * y2 - y1 * x2 + 16;
            int g3 = (x1 ^ x2) | (y1 ^ y2);
            if((g1 + g2 + g3) % 4 == ar % 4)
            {
                a[i][j] = ((g1 & 1) ? 3 : 1);
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {

        memset(b, 0, sizeof(b));
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                continue;
            }
            int dx = ((x[j] - x[i]) % 4 + 4) % 4;
            int dy = ((y[j] - y[i]) % 4 + 4) % 4;
            int g = gcd(abs(x[i] - x[j]), abs(y[i]- y[j])) & 3;
            ++b[(g << 4) | (dx << 2) | dy];
        }
        for(int j = 0; j < 64; j++)
        {
            ans += 1LL * b[j] * (b[j] - 1) / 2 * a[j][j];
            for(int k = j + 1; k < 64; k++)
            {
                ans += 1LL * b[j] * b[k] * a[j][k];
            }
        }
    }
    cout << ans / 3;
    return 0;
}