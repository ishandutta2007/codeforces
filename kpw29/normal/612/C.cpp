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
const int mod = 1e8;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, k, a, b, c, p, q;
ll wyn = 0;
int tab[maxn], DL = 0;
char s[maxn];
map <char, int> znak;
int main()
{
    scanf("%s", s +1);
    znak['<'] = 1;
    znak['>'] = -1;
    znak['('] = 2;
    znak[')'] = -2;
    znak['['] = 3;
    znak[']'] = -3;
    znak['{'] = 4;
    znak['}'] = -4;
    n = 1;
    while (s[n])++n; --n;
    if (n % 2 == 1) OUT("Impossible");
    for (int i=1; i<=n; ++i)
    {
        if (znak[s[i]] > 0) tab[++DL] = znak[s[i]];
        else 
        {
            int el = znak[s[i]];
            if (DL <= 0) OUT("Impossible");
            if (tab[DL] != -el) ++wyn;
            --DL;
        }
    }
    if (DL != 0) OUT("Impossible");
    cout << wyn;
      
}