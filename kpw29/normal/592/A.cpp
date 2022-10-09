 #include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define scanf(...) scanf(__VA_ARGS__)?:0
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
ll wyn;
int t[maxn];

char s[10][10];
int main()
{
    n = 8;
    int WA = 10, WB = 10;
    for (int i=1; i<=n; ++i) scanf("%s", s[i]+1);
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=n; ++j) {
          if (s[i][j] == 'W') {
              int tmp = 0, x = i;
              while (x > 1) {
                  --x;
                  ++tmp;
                  if (s[x][j] == 'B') tmp = 1338;
              }
              WA = min(WA, tmp);
          }
          if (s[i][j] == 'B') {
              int tmp = 0, x = i;
              while (x < n) {
                  ++x;
                  ++tmp;
                  if (s[x][j] == 'W') tmp = 1338;
              }
              WB = min(WB, tmp);
          }
      }
   if (WA <= WB) puts("A");
   else puts("B");
}