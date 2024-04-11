#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string s, t, ans;
int z_t[100005], maxi[100005], f[100005], i, j, n, m;
bool chk_t[100005], chk_s[100005];

void Z_Func(const string &S, int *Z, const int &n)
{
    int L = 0, R = 0;
    Z[0] = n;
    for (int i = 1; i < n; i++)
        if (i > R)
        {
            L = R = i;
            while (R < n && S[R] == S[R - L]) R++;
            Z[i] = R - L; R--;
        }
        else
        {
            int k = i - L;
            if (Z[k] < R - i + 1) Z[i] = Z[k];
            else
            {
                L = i;
                while (R < n && S[R] == S[R - L]) R++;
                Z[i] = R - L; R--;
            }
        }
    for (int i = n; i >= 1; i--)
        Z[i] = Z[i - 1];
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie();
    cin >> s >> t;
    ans = s; n = s.size(); m = t.size();
    Z_Func(t, z_t, m);
    for (i = 1; i <= m; i++)
        chk_t[i] = (z_t[i] == m - i + 1);
    for (i = m; i <= n; i++)
    {
        chk_s[i] = 1;
        for (j = 0; j < m; j++)
            if (s[i - m + j] != '?' && s[i - m + j] != t[j])
            {
                chk_s[i] = 0;
                break;
            }
    }
    f[0] = 0;
    maxi[0] = 0;
    for (i = 1; i <= n; i++)
    {
        if (chk_s[i])
        {
            f[i] = maxi[i - m];
            for (j = 1; j < m; j++)
                if (f[i - m + j] > f[i] && chk_t[m + 1 - j])
                    f[i] = f[i - m + j];
            f[i]++;
        }
        maxi[i] = max(f[i], maxi[i - 1]);
    }
    printf("%d", maxi[n]);
}