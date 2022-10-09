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
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, k, a, b, c, p, q;
PII tab[2 * maxn];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d%d", &a, &b);
        tab[2 * i - 1] = mp(a, 1);
        tab[2 * i] = mp(b + 1, -1);
    }
    int dwa = 2 * n;
    sort(tab + 1, tab + dwa + 1);
    int seg = 0, last = 0;
    vector <PII> ans;
    int pocz = 1;
    tab[0] = mp(-inf, -inf);
    for (int i=1; i<=dwa; ++i)
    {
        if (tab[i].e2 == 1) seg++;
        else --seg;
        if (last < k && seg >= k)
        {
            pocz = tab[i].e1;
        }
        if (last >= k && seg < k)
        {
            ans.pb(mp(pocz, tab[i].e1 - 1)); //skoro teraz juz nie ma to wtedy bylo
        }
        last = seg;
    }
    if (ans.size() == 0) OUT(0);
    
    int first = ans[0].e1;
    vector <PII> nowy;
    for (int i=1; i<ans.size(); ++i)
    {
        if (ans[i].e1 > ans[i-1].e2)
        {
            nowy.pb(mp(first, ans[i-1].e2));
            first = ans[i].e1;
        }
    }
    nowy.pb(mp(first, ans[ans.size() - 1].e2));
    
    cout << nowy.size() << endl;
    for (int i=0; i<nowy.size(); ++i) printf("%d %d\n", nowy[i].e1, nowy[i].e2);
}