
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
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1010100
long long A, n, m, f1, f2;
PII it = mp(-1, -1);
PLL t[maxn];
ll cost[maxn], rcost[maxn];
ll podniesc[maxn];
ll LAST = -1;
int main()
{
    cin >> n >> A >> f1 >> f2 >> m;

    for (int i=1; i<=n; ++i) cin >> t[i].e1, t[i].e2 = i;
    for (int i=1; i<=n; ++i) podniesc[i] = t[i].e1;
    sort(t + 1, t + n + 1);
    ll sum = 0;
    //SPECIAL CASE DO ZAIFOWANIA JESZCZE!!!!!!!!!
    for (ll i=1; i<=n; ++i)
    {
        sum += t[i].e1;
        ll MIN = t[i].e1;
        cost[i] = MIN * (ll)i - sum;
    }
    sum = 0;
    for (ll i=n; i>0; --i)
    {
        sum += (A - t[i].e1);
        rcost[i] = sum;
    }
    
    ll i = n;
    ll WYN = -1;
    t[n + 1].e1 = INF;
    for (ll j=n+1; j>0; --j) //bierzemy dokladnie (n, j) itemek
    {
        while ((cost[i] + rcost[j] > m && i > 0 )|| i >= j) --i;
        if (cost[i] + rcost[j] > m) continue;
        ll reszta = m - (cost[i] + rcost[j]);
        ll AKT;
        if (i == 0) AKT = 0;
        else AKT = min(A, t[i].e1 + (reszta / i));
        ll tmp = AKT * f2 + f1*(ll)(n - j + 1);
        
        if (tmp > WYN) {
            //cout << i << ' ' << j << endl;
            WYN = tmp;
            it = mp(i, j);
            LAST = AKT;
        }
    }
    for (i = it.e2; i <= n; ++i) podniesc[t[i].e2] = A;
    for (i=1; i<=it.e1; ++i) podniesc[t[i].e2] = LAST;
    WYN = 0; ll MIN = INF;
    for (int i=1; i<=n; ++i) {
      if (podniesc[i] == A) WYN += f1;
      MIN = min(MIN, podniesc[i]);
  }
  WYN += MIN * f2;
  cout << WYN << endl;
for (i=1; i<=n; ++i) cout << podniesc[i] << ' ';
    
}