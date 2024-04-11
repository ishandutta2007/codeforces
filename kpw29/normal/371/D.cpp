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
int n, m, k, a, b, c;
int f[maxn];
ll cap[maxn];
ll jest[maxn];

int find(int a)
{
    if (f[a] == a) return a;
    f[a] = find(f[a]);
    return f[a];
}

void process(int x)
{
    if (jest[x] <= cap[x] || x == n + 1) return;
    //jest wiecej niz moze byc
    ll roz = jest[x] - cap[x];
    jest[x] = cap[x];
    int fx = find(x + 1);
    f[x] = fx;
    jest[fx] += roz;
    process(fx);
}
int main()
{
    boost;
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> cap[i], f[i] = i;
    f[n + 1] = n + 1;
    cap[n + 1] = INF;
    int zap;
    cin >> zap;
    while (zap--)
    {
        int type;
        cin >> type >> a;
        if (type == 2) cout << jest[a] << '\n';
        else
        {
            cin >> b;
            jest[a] += b;
            process(a);
        }
    }
}