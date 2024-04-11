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
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const ll P = 31;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
bool zle = false;
int n;
#define maxn 100010
bool odw[maxn];
vector <int> v[maxn];
int type[maxn], lisc[maxn];
//1 - potrzebuje 1 linie
//2 - potrzebuje 2 linie
//3 - potrzebuje 1 linie, ale jesli dodamy cos jeszcze to juz bedzie potrzebowal dwie
//jesli wierzcholek ma wiecej niz 2 nierobialne poddrzewa to wgl sie nie da.
int TYPE, start = 1;
void dfs(int x)
{
    lisc[x] = 0;
    odw[x] = true;
    int jed = 0, dwa = 0, trzy = 0;
    for (ui i=0; i<v[x].size(); ++i) 
    if (!odw[v[x][i]]) 
    {
        int u = v[x][i];
        dfs(u);
        lisc[x]++;
        if (type[u] == 1) jed++;
        if (type[u] == 2) dwa++;
        if (type[u] == 3) ++trzy;
        if (dwa > 2) OUT("No");
        if (dwa == 2 && x != start) 
        {
            if (TYPE) 
            {
                OUT("No");
            }
            else
            {
                ++TYPE;
                for (int i=1; i<=n; ++i) type[i] = 0, odw[i] = 0, lisc[i] = 0;
                start = x;
                dfs(x);
            }
        }
    }
    if (lisc[x] == 0) type[x] = 1;
    else if (lisc[x] == 1 && jed == 1) type[x] = 1;
    else if (jed > 2 || dwa > 0 || trzy > 0) type[x] = 2;
    else type[x] = 3;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<n; ++i)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1);
    //for (int i=1; i<=n; ++i) printf("%d ", type[i]);
    if (zle) puts("No");
    else puts("Yes");
}
 
/*
 
 */