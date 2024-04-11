#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define OUT(x) { cout << x; exit(0);}
typedef pair <int, int> PII;
typedef unsigned int ui;
typedef unsigned long long int ull;
typedef long long int ll;
typedef double ld;
typedef pair <int, ll> PIL;
typedef pair <ll, int> PLI;
typedef pair <ll, ll> PLL;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = ll(1e18) + 3;
int n,a,b,c,m,k;
ll N,M,A,B,C;
#define maxn 1000100
set <int> seg;
void ustal(int x)
{
    if (x < 10) cout << "0";
}

inline int readint()
{
    int x = 0; char zn;
    while (1)
    {
        zn = getchar();
        if (isspace(zn)) return x;
        x = (x << 1) + (x << 3) + zn - '0';
    }
}
int t[maxn];
bool wyrz[maxn];
PII tab[maxn];
int dr[maxn + 100];
void add(int p, int v)
{
    for (; p <= maxn; p += p & (-p)) dr[p] += v;
}
int get(int p)
{
    int s = 0;
    for (; p > 0; p -= p & (-p)) s += dr[p];
    return s;
}
int rem(int x, int y)
{
    return get(y) - get(x - 1);
}
int main()
{
    n = readint();
    k = readint();
    for (int i=1; i<=n; ++i) 
    {
        t[i] = readint();
        tab[i] = mp(t[i], i);
    }
    for (int i=1; i<=k; ++i)
    {
        a = readint();
        wyrz[a] = true;
    }
    sort(tab+1, tab + n + 1);
    seg.insert(0);
    seg.insert(n + 1);
    ll wyn = 0;
    for (int i=1; i<=n; ++i)
    {
        int num = tab[i].e2;
        int right = *seg.upper_bound(num);
        set <int> ::iterator it = seg.lower_bound(num);
        --it; int left = *it;
        if (wyrz[tab[i].e1] == false)
        {
            wyn += right - left - 1 - rem(left + 1, right - 1);
            add(num, 1);
        }
        else seg.insert(num);
    //  cout << i << " " << wyn << endl;
    }
    cout << wyn;
}