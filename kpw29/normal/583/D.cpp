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
int n, m, k, a, b, c, p, q;
ll N, M, A, B, C, P, Q;
#define maxn 101010
int T;
int t[maxn], dp[maxn];
int licz[maxn];
int dr[1337];

void add(int p, int v) {
    for (; p < 1300; p += p & (-p)) dr[p] = max(dr[p], v);
}
int get(int p) {
    int s = 0;
    for (; p>0; p -= p & (-p)) s = max(s, dr[p]);
    return s;
}

int main() {
    boost;
    cin >> n >> T;
    for (int i=1; i<=n; ++i) cin >> t[i], licz[t[i]]++;
    int reszta = T - n;
    if (T > n) T = n;
    {
        for (int i=1; i<=n; ++i) 
          for (int j=1; j<T; ++j) t[i + j * n] = t[i];
    }
    int all = T * n;
    for (int i=1; i<=all; ++i)
    {
        int help = get(t[i]) + 1;
        dp[i] = help;
        add(t[i], help);
    }
    //for (int i=1; i<=all; ++i) printf("%d ", dp[i]);
    int WYN = 0;
    for (int i=1; i<=all; ++i) WYN = max(WYN, dp[i]);
    int maxlicz = 0;
    for (int i=0; i<400; ++i) maxlicz = max(licz[i], maxlicz);
    if (reszta > 0) WYN += maxlicz * reszta;
    cout << WYN;
}