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
int n, m, k, a, b, c;
int t[maxn], stable[maxn];
int l[maxn], r[maxn];
int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &a);
        t[i] = a;
        if (i == 1) stable[i] = 2;
        else if (t[i] == t[i-1]) {
            stable[i] = 1;
            stable[i-1] = 1;
        }
        if (i == n && stable[i] == 0) stable[i] = 2;
    }
    int lmax = 0, akt = 0;
    for (int i=1; i<=n; ++i) {
        if (!stable[i]) ++akt;
        else akt = 0;
        l[i] = akt;
        lmax = max(lmax, akt);
    }
    akt = 0;
    for (int i=n; i>0; --i) {
        if (!stable[i]) ++akt;
        else akt = 0;
        r[i] = akt;
    }
    stable[0] = stable[n + 1] = 1;
    for (int i=1; i<=n; ++i)
      if (stable[i] > 0) {
          int j = i + 1;
          while (stable[j] == 0 && l[j] <= r[j]) stable[j] = 1, t[j] = t[i], ++j;
          j = i - 1;
          while (stable[j] == 0 && l[j] > r[j]) stable[j] = 1, t[j] = t[i], --j;
      }
    printf("%d\n", (lmax + 1) / 2);
    for (int i=1; i<=n; ++i) printf("%d ", t[i]);
}