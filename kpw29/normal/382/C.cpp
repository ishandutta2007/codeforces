#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) { cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(0)
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <PII, PII> PP;
typedef pair <ll, ll> PLL;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18 + 3;
int n, n1, n2, m, a, b, c;
#define maxn 1000100
int t[maxn];
vector <ll> wyn;

ll TMP[maxn];
void C(int x) {
    
    int help = inf;
    sort(t + 1, t + n + 1);
    for (int i=2; i<=n; ++i)
      if (t[i] - t[i-1] != x) {
          if (t[i]-t[i-1] == x + x) {
              if (help != inf) return;
              else help = t[i-1] + x;
          }
          else return;
      }
    if (help != inf) wyn.pb(help);
}

int main()
{
    boost;
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> t[i];
    sort(t + 1, t+n+1);
    if (n == 1) OUT(-1);
    vector <ll> w;
    w.clear();
    w.pb(t[2] - t[1]);
    if ((t[2] - t[1]) % 2 == 0) w.pb((t[2] - t[1]) / 2);
    for (int i=0; i<w.size(); ++i) C(w[i]);
    
    bool check = true;
    ll R = t[2] - t[1];
    for (int i=2; i<=n; ++i)
      if (t[i] - t[i-1] != R) check = false;
    if (check) wyn.pb(t[1] - R), wyn.pb(t[n] + R);
    sort(wyn.begin(), wyn.end());
    int size = (wyn.size() == 0)?0:1;
    for (int i=1; i<wyn.size(); ++i)
      if (wyn[i] != wyn[i-1]) ++size;
      cout << size << endl;
    for (int i=0; i<wyn.size(); ++i) 
      if (i == 0 || wyn[i] != wyn[i-1]) cout << wyn[i] << ' ';
}