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
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
#define maxn 1000100
int n;
vector <int> v;
int f[maxn], t[maxn];
int size[maxn];

int main()
{
    scanf("%d", &n);
    int wyn = n;
    for (int i=1; i<=n; ++i) scanf("%d", &t[i]);
    sort(t+1, t + n + 1);
    for (int i=1; i<=n; ++i) f[i] = i, size[i] = 0;
    for (int i=1; i<=n; ++i)
      for (int j=1; j<i; ++j)
      {
            if (f[j] != j) continue;
            if (size[j] + 1 <= t[i])
            {
                size[i] = size[j] + 1;
                f[j] = i;
                --wyn;
                break;
            }
      }
    printf("%d", wyn);
    return 0;
}