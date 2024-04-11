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
#define maxn 4010
int n, m, a, b, c;
ll wyn[maxn];
int t[4];
int main()
{
    wyn[0] = 1;
    cin >> n >> t[0] >> t[1] >> t[2];
    for (int i=1; i<=n; ++i)
    {
        for (int j=0; j<3; ++j)
          if (t[j] <= i && wyn[i - t[j]] > 0) wyn[i] = max(wyn[i], wyn[i - t[j]] + 1);
    }
    cout << wyn[n] - 1;
    //for (int i=1; i<=n; ++i) cout << wyn[i]-1 << ' ';
}