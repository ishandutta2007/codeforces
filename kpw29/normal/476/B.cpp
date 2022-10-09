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
#define maxn 1000100
int n, m, a, b, c, jest, ocz, zap;
string s;
double tab[200], nowe[200];
const int pol = 100;
int main()
{
    cout.precision(15);
    cout.fixed;
    cin >> s;
    for (int i=0; i<s.size(); ++i)
      if (s[i] == '+') ++ocz;
      else --ocz;
    cin >> s;
    for (int i=0; i<s.size(); ++i)
      if (s[i] == '+') ++jest;
      else if (s[i] == '-') --jest;
      else ++zap;

    tab[jest + pol] = 1.0;
    for (int z=1; z<=zap; ++z)
    {
        for (int i=-50; i<=50; ++i) nowe[i+pol] = 0;
        for (int i=-50; i<=50; ++i)
        {
          nowe[i + 1 + pol] += 0.5*tab[i+pol];
          nowe[i - 1 + pol] += 0.5*tab[i+pol];
        }
        for (int i=-50; i<=50; ++i) tab[i+pol] = nowe[i+pol];           
    }
    cout << tab[ocz + pol];
    //for (int i=-10; i<=10; ++i) cout << tab[i+pol] << endl;
}