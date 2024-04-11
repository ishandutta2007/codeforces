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
const ll mod = 1e9 +7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int k, a, b, c;

ll n, m;
vector <ll> pr;
ll f(ll a)
{
    ll ret = 0;
    if (a <= 0) return 0;
    for (int i=1; i<pr.size(); ++i)
      if (pr[i] <= a && pr[i] != pr[i-1]) {
          //cout << pr[i] << endl;
          ++ret;
      }
      return ret;
}

int main()
{
    cin >> n >> m;
    pr.clear();
    for (ll i = 0; i<=60; ++i)
    {
      ll abs = ((1LL << (i + 1) )- 1);
      for (ll j=0; j<i; ++j) pr.push_back(abs - (1LL << j));
    }
    pr.pb(pr[0]);
    pr[0] = -inf;
    sort(pr.begin(), pr.end());
    
    cout << f(m) - f(n - 1);
}