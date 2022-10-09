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

int main() {
    boost;
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> t[i];
    int hajs = 0;
    ll change = 0;
    int poz = 1;
    while (hajs < n) {
        if (poz == 1) {
            for (int i=1; i<=n; ++i) 
              if (zuzyte[i] == false && hajs >= t[i]) ++hajs, zuzyte[i] = true;
            poz = 0;
        }
        else
        {
            for (int i=n; i>0; --i)
              if (zuzyte[i] == false && hajs >= t[i]) ++hajs, zuzyte[i] = true;
            poz = 1;
        }
        if (hajs < n) change++;
    }
    cout << change;
        
    
}