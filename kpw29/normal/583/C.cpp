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

int t[maxn * maxn];
vector <int> v;
map <int, int> mapa;
int main() {
    cin >> n;
    for (int i=1; i<=n*n; ++i) cin >> t[i];int kw = n * n;
    sort(t + 1, t + kw + 1);
    
    for (int i=kw; i>0; --i)
    {
        if (mapa[t[i]] == 0) {
            for (int j=0; j<v.size(); ++j) mapa[__gcd(t[i], v[j])]+=2;
            v.push_back(t[i]);
        }
        else mapa[t[i]]--;
    }
    for (int j=0; j<v.size(); ++j) printf("%d ", v[j]);
}