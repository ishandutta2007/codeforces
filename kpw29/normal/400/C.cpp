#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define OUT(x) { cout << x; return 0; }
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
int n,m,x,y,z, i, j, N, M;
void RROTATE(int &i, int &j)
{
    int x = i, y = j;
    i = y;
    j = N - x + 1;
    swap(N, M);
}
void HROTATE(int &i, int &j)
{
    j = M - j + 1;
}
int main()
{
    int T;
    scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &T);
    x = x % 4;
    z = z % 4;
    y = y & 1;
    while (T--)
    {
        N = n; M = m;
        scanf("%d%d", &i, &j);
        for (int help = 0; help < x; ++help) RROTATE(i, j);
        if (y) HROTATE(i, j);
        for (int help = 0; help < (4 - z); ++help) RROTATE(i, j);
        printf("%d %d\n", i, j);
    }
}