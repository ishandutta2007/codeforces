#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 63;
const int M = 998244353;

int conv(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    if (c >= 'A' && c <= 'Z')
        return 26 + c - 'A' + 1;
    if (c >= '0' && c <= '9')
        return 52 + c - '0' + 1;
}

int ans = 0;
int n;
int kol[N][N], f[N][N][N];
vector<string> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++)
        cin >> s[i], s.pb(s[i]), reverse(all(s[i]));
    sort(all(s));
    s.resize(unique(all(s)) - s.begin());
    for (int sz = 3; sz <= 10; sz++) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    kol[i][j] = 0, f[i][j][k] = 0;

        for (int i = 0; i < s.size(); i++)
            if (s[i].size() == sz)
                kol[conv(s[i][0])][conv(s[i].back())]++;
        for (int a1 = 0; a1 < N; a1++)
            for (int a2 = a1; a2 < N; a2++)
                for (int a3 = a2; a3 < N; a3++) {
                    long long q = 0;
                    for (int c = 0; c < N; c++)
                        q += 1ll * kol[a1][c] * kol[a2][c] * kol[a3][c];

                    f[a1][a2][a3] = f[a1][a3][a2] = f[a2][a1][a3] = f[a2][a3][a1] = f[a3][a1][a2] = f[a3][a2][a1] = q % M;
                }
        for (int a1 = 0; a1 < N; a1++)
            for (int a2 = 0; a2 < N; a2++)
                for (int a3 = 0; a3 < N; a3++) {
                    unsigned long long sum = 0;
                    for (int a4 = 0; a4 < 18; a4++)
                        sum += 1ll * f[a1][a2][a4] * f[a2][a3][a4] % M * f[a1][a3][a4];
                    sum %= M;
                    for (int a4 = 18; a4 < 36; a4++)
                        sum += 1ll * f[a1][a2][a4] * f[a2][a3][a4] % M * f[a1][a3][a4];
                    sum %= M;
                    for (int a4 = 36; a4 < 54; a4++)
                        sum += 1ll * f[a1][a2][a4] * f[a2][a3][a4] % M * f[a1][a3][a4];
                    sum %= M;
                    for (int a4 = 54; a4 < N; a4++)
                        sum += 1ll * f[a1][a2][a4] * f[a2][a3][a4] % M * f[a1][a3][a4];
                   
                    ans = (1ll * ans + f[a1][a2][a3] * sum) % M;
                }
    }
    cout << ans;
    return 0;
}