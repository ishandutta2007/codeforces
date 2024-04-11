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
ll t[maxn];
int cnt[maxn];
int main()
{
    cin >> n >> k;
    for (int i=0; i<n; ++i) 
    {
        cin >> t[i];
        if (t[i] == 2) cnt[i % k]++;
    }
    int dziel = n/k, moves = 0;
    for (int i=0; i<k; ++i)
      moves += min(cnt[i], dziel - cnt[i]);
    cout << moves;
}