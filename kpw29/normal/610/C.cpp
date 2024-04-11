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
const int mod = 1e8;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 2000100
int n, m, k,  b, c, pot ,last;
int tab[2050][2050];

int main()
{
    cin >> n;
    tab[1][1] = 1; tab[1][2] = 1;
    tab[2][1] = 1; tab[2][2] = -1;
    for (int h=2; h<=n; ++h)
    {
        int bok = (1 << (h-1));
        for (int i=1; i<=bok; ++i)
          for (int j=1; j<=bok; ++j) tab[i + bok][j] = tab[i][j + bok] = tab[i][j];
        for (int i=1; i<=bok; ++i)
          for (int j=1; j<=bok; ++j) tab[i  + bok][j + bok] = - tab[i][j];
    }
    int wyn = (1 << n);
    for (int i=1; i<=wyn; ++i)
    {
      for (int j=1; j<=wyn; ++j)
      {
          if (tab[i][j] == 1) cout << "+";
          else cout << "*";
     }
     cout << '\n';
 }
      
}