#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
string s;
int wyn[maxn];
int tab[1010][1010];
int main()
{
    int x, y, n, m;
    cin >> n >> m >> x >> y;
    tab[x][y] = 1;
    cin >> s;
    int way = 0;
    printf("1 ");
    int move = 0;
    for (int i=0; i<s.size(); ++i)
    {
        char zn = s[i];
        if (zn == 'U')
        {
            if (x == 1) wyn[i] = 0;
            else x--, move = 1;
        }
        if (zn == 'D')
        {
            if (x == n) wyn[i] = 0;
            else x++, move = 1;
        }
        if (zn == 'R')
        {
            if (y == m) wyn[i] = 0;
            else y++, move = 1;
        }
        if (zn == 'L')
        {
            if (y == 1) wyn[i] = 0;
            else y--, move = 1;
        }
        if (tab[x][y] == 0) ++wyn[i];
        tab[x][y] = 1;
        if (i != s.size()-1) printf("%d ", wyn[i]);
    }
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j)
      way += tab[i][j];
    if (tab[x][y] == 0) --way;
    printf("%d ", n * m - way + wyn[s.size() - 1]);
}