#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define OUT(x) { cout << x; return 0; }
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const ll P = 31;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
int t[1000100];
int n;
void divide(int &a)
{
    while (a % 2 == 0) a/=2;
    while (a % 3 == 0) a/=3;
}
int main()
{
    boost;
    cin >> n;
    int dziel = 0;
    for (int i=1; i<=n; ++i) 
    {
        cin >> t[i];
        divide(t[i]);
    }
    for (int i=1; i<=n; ++i) dziel = __gcd(dziel, t[i]);
    int wyn = 0;
    for (int i=1; i<=n; ++i) 
      if (t[i] != dziel) wyn = 1;
    if (wyn) puts("No");
    else puts("Yes");
    return 0;
}