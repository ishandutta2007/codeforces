#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long f[11][60][1024], c[11][60][1024], dig[11][60], l, r;
int q, b;
vector <int> s;

void init()
{
    for (int i = 2; i <= 10; i++)
    {
        f[i][0][0] = c[i][0][0] = 1; c[i][1][1] = -1;
        long long t = i;
        for (int j = 1; t <= 1e18; t *= i, dig[i][j] = dig[i][j - 1] + c[i][j][0], j++)
            for (int k = 0; k < (1 << i); k++)
                for (int l = 0; l < i; l++)
                {
                    f[i][j][k] += f[i][j - 1][k ^ (1 << l)];
                    c[i][j][k] += c[i][j - 1][k ^ (1 << l)];
                }
    }
}

long long solve(int b, long long x)
{
    long long ans;
    int mask = 0, i;
    do
    {
        s.push_back(x % b);
        x /= b;
    } while (x != 0);
    ans = dig[b][s.size() - 1] - f[b][s.size() - 1][1];
    while (!s.empty())
    {
        for (i = 0; i < s.back(); i++)
            ans += f[b][s.size() - 1][mask ^ (1 << i)];
        mask ^= (1 << s.back()); s.pop_back();
    }
    return ans + (mask == 0);
}

int main()
{
    init();
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%I64d%I64d", &b, &l, &r);
        printf("%I64d\n", solve(b, r) - solve(b, l - 1));
    }
}