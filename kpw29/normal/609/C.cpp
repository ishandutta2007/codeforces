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
#define maxn 2001000
int a, b, c, n, m, k;
ll suma;
int t[maxn];
ll dol, gora;

ll odl(ll a, ll b) {
    return max(b-a, a-b);
}

int main()
{
    boost;
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> t[i], suma += t[i];
    ll ile = suma / (ll)n;
    ll i2 = ile;
    if (ile * (ll)n != suma) i2++;
    ll gora = 0, dol = 0;
    for (int i=1; i<=n; ++i)
    {
        if (t[i] > i2) gora += t[i] - i2;
        if (t[i] < ile) dol += ile - t[i];
    }

    cout << max(gora, dol);
}