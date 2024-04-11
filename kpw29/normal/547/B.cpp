#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <BONG, BONG> DONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c;
#define maxn 500300
int t[maxn], f[maxn], ile[maxn];
BONG help[maxn];
bool odw[maxn];
int wynik[maxn];
int _find(int a)
{
    int fa = f[a];
    if (fa == a) return a;
    f[a] = _find(fa);
    return f[a];
}
bool _union(int a, int b)
{
    int fa = _find(a);
    int fb = _find(b);
    if (fb == fa) return true;
    if (ile[fa] <= ile[fb]) ile[fb] += ile[fa], f[fa] = fb, ile[fa] = 0;
    else ile[fa] += ile[fb], f[fb] = fa, ile[fb] = 0;
    return false;
}


int main()
{
    cin >> n;
    for (int i=1; i<=n; ++i) f[i] = i, ile[i] = 1;
    int maks = 0;
    for (int i=1; i<=n; ++i) 
    {
        cin >> t[i];
        maks = max(maks, t[i]);
        help[i] = mp(t[i], i);
    }
    sort(help+1, help+n+1);
    wynik[1] = maks;
    for (int i=n; i>0; --i)
    {
        int a = help[i].e1;
        int gdzie = help[i].e2;
        odw[gdzie] = true;
        if (odw[gdzie + 1]) 
        {
            _union(gdzie, gdzie+1);
            int fa = _find(gdzie);
            wynik[ile[fa]] = max(wynik[ile[fa]], a);
        }
        if (odw[gdzie - 1]) 
        {
            _union(gdzie, gdzie-1);
            int fa = _find(gdzie);
            wynik[ile[fa]] = max(wynik[ile[fa]], a);
        }
        /*printf("%d\n", a);
        for (int j=1; j<=n; ++j) printf("%d ", _find(j));
        puts("");
        for (int j=1; j<=n; ++j) printf("%d ", odw[j]);
        puts("");*/
    }
    
    for (int i=n; i > 0; --i)
      wynik[i] = max(wynik[i], wynik[i+1]);
    for (int i=1; i<=n; ++i) printf("%d ", wynik[i]);
}