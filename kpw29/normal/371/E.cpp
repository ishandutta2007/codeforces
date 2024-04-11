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
const ll mod = 1e9 - 401;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, k, a, b, c;

ull pref[maxn], m;
PLL t[maxn];
ull suma = 0;

ll sum(int a, int b) {
    return pref[b] - pref[a-1];
}

int main()
{
    boost;
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> t[i].e1; 
        t[i].e2 = i;
    }
    sort(t + 1, t + n + 1);
    for (int i=1; i<=n; ++i) pref[i] = pref[i-1] + t[i].e1;
    cin >> m;
    if (m == 1) OUT(0);
    ull res = INF * 17LL;
    for (ull i=2; i<=m; ++i) suma += t[i].e1 * (i - 1) - sum(1, i - 1);
    res = min(res, suma);
    int R = 1;

    for (ull i = m + 1; i<=n; ++i)
    {
        suma += t[i].e1 * (m - 1) - sum(i - m + 1, i - 1);
        suma -= (sum(i - m + 1, i - 1) - t[i - m].e1 * (m - 1));
        assert(suma >= 0);
        if (suma < res)
        {
            res = suma;
            R = i - m + 1;
        }
    }
    
    //cout << res;
    for (int i=R; i<R+m; ++i) cout << t[i].e2 << ' ';
}