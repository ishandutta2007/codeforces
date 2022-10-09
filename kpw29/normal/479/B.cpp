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
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, m, a, b, c, k;
ll A, B, C;
#define maxn 1000100
int t[maxn];
int main()
{
    scanf("%d%d", &n, &k);
    if (n == 1) 
    {
        printf("%d %d\n", 0, 0);
        exit(0);
    }
    for (int i=1; i<=n; ++i) scanf("%d", &t[i]);
    vector <PII> wyn;
    t[n + 1] = inf;
    int start = k;
    while (k--)
    {
        int MIN = n+1, MAX = 0;
        for (int i=1; i<=n; ++i)
        {
            if (t[i] < t[MIN]) MIN = i;
            if (t[i] > t[MAX]) MAX = i;
        }
        t[MAX]--;
        t[MIN]++;
        if (MIN != MAX)
        wyn.pb(mp(MAX, MIN));
    }
    int MIN = n + 1, MAX = 0;
    for (int i=1; i<=n; ++i)
    {
        if (t[i] < t[MIN]) MIN = i;
        if (t[i] > t[MAX]) MAX = i;
    }
    printf("%d %d\n", t[MAX] - t[MIN], wyn.size());
    for (int i=0; i<wyn.size(); ++i) printf("%d %d\n", wyn[i].e1, wyn[i].e2);
}