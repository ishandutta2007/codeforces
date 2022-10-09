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
int n, m, k, a, b, c, p, q, T, steps;
#define maxn 1000100
char s[maxn], temp[maxn];

int main()
{
    scanf("%s", s +1);
    int n = 1;
    while (s[n]) ++n; --n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &a, &b, &k);
        int dl = b - a + 1;
        for (int i=a; i<=b; ++i) temp[i] = s[i];
        for (int i=a; i<=b; ++i) s[(i - a + k) % dl + a] = temp[i];
    }
    for (int i=1; i<=n; ++i) printf("%c", s[i]);
}