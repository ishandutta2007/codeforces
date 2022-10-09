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
#define maxn 1010
int t[maxn];
bool zuzyte[maxn];
int h1[maxn], h2[maxn];
int main() {
    vector <int> wyn;
    wyn.clear();
    cin >> n;
    int kw = n * n;
    for (int i=1; i<=kw; ++i)
    {
        cin >> a >> b;
        if (h1[a] == false && h2[b] == false)
        {
            h1[a] = true;
            h2[b] = true;
            wyn.pb(i);
        }
    }
    for (int i=0; i<wyn.size(); ++i) cout << wyn[i] << ' ';
}