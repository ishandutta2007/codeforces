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
#define maxn 2000100
int n, m, k,  b, c;
ll tab[maxn], p[maxn], a;
inline int nast(int x)
{
    if (x == n) return 1;
    return x + 1;
}

int main()
{
    boost;
    cin >> n;
    a = inf;
    for (int i=1; i<=n; ++i)
    {
        cin >> tab[i];
        a = min(a, tab[i]);
    }
    ll wyn = (ll)n * (ll)a;
    for (int i=1; i<=n; ++i) tab[i] -= a;
    for (int i=1; i<=n; ++i) tab[n + i] = tab[i];
    ll w = 0;
    for (int i=n+n; i>0; --i)
    {
      if (tab[i] < 1) p[i] = 0;
      else p[i] = p[i+1] + 1;
      w = max(w, p[i]);
  }
      
    cout << wyn + w;
    
}