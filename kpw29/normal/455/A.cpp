#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
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
#define maxn 1000100
int n, m, a;
ll wyn[maxn], t[maxn];
int main()
{
    scanf("%d", &m);
    for (int i=1; i<=m; ++i) 
    {
        scanf("%d", &a);
        t[a]++;
    }
    for (int i=1; i<maxn; ++i)
    {
        wyn[i] = wyn[i-1];
        if (t[i] > 0) wyn[i] = max(wyn[i], wyn[i-2] + t[i] * i);
    }
    cout << wyn[maxn-1];
    
}