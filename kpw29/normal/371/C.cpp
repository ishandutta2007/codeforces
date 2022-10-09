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
#define maxn 1000100
int n, m, k, a, b, c;

ll wyn = 0;
string s;

int tab[4];
ll needed[4], has[4];
ll price[4], money;

bool can(ll ile)
{
    ll cost = 0;
    for (int i=1; i<=3; ++i)
     cost += max(0LL, ile * needed[i] - has[i]) * price[i];
    return (cost <= money);
}
int main()
{
    cin >> s;
    for (int i=0; i<s.size(); ++i)
      if (s[i] == 'B') needed[1]++;
      else if (s[i] == 'S') needed[2]++;
        else needed[3]++;
    for (int i=1; i<=3; ++i) cin >> has[i];
    for (int i=1; i<=3; ++i) cin >> price[i];
    cin >> money;
    ll x = 0, y = 1000000000000000LL;
    while (x < y)
    {
        ll sr = (x + y ) / 2 + 1;
        if (can(sr) == false) y = --sr;
        else x = sr;
    }
    cout << x;
    
}