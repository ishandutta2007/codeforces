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
#define maxn 2000100
int n, m, k, a, b, c;
int dziel[10][2];
int t[3];
int main()
{
    cin >> t[1] >> t[2];
    a = t[1], b = t[2];
    for (int j=1; j<=2; ++j)
    for (int i=2; i<=5; ++i)
    {
        while (t[j] % i == 0)
        {
            t[j] /= i;
            dziel[i][j]++;
        }
    }
    if (t[1] != t[2]) OUT("-1");
    int ans = 0;
    for (int i=2; i<=5; ++i) ans += abs(dziel[i][1] - dziel[i][2]);
    cout << ans;
}