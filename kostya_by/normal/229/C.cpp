#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n, m;
long long deg[ 1111111 ], ans, nn;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    nn = n;
    ans = nn * (nn - 1) * (nn - 2) / 6;
    for ( int i = 0; i < m; i++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        deg[a]++;
        deg[b]++;
    }
    long long pp = 0;
    for ( int i = 0; i < n; i++ )
    {
        long long pls = deg[i] * (nn - deg[i] - 1);
        pp += pls;
    }
    pp /= 2;
    cout << ans - pp;
    return 0;
}