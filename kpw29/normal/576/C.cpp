#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define OUT(x) { cout << x; exit(0); }
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
const ll INF = 1e18+3;
#define maxn 1000001
const int R = 1000;
PP tab[maxn];
int a,b, n;
int MR = (maxn / R )+ 2;

bool cmp(PP a, PP b)
{
    if (a.e1.e1 != b.e1.e1) return (a.e1.e1 < b.e1.e1);
    if( a.e1.e1 & 1) return (a.e1.e2 < b.e1.e2);
    return (a.e1.e2 > b.e1.e2); 
}
int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d%d", &a, &b);
        int a2 = (a / R);
        tab[i] = {mp(a2, b), mp(a, i)};
    }
    sort(tab + 1, tab + n + 1, cmp);
    for (int i=1; i<=n; ++i) printf("%d ", tab[i].e2.e2);
}