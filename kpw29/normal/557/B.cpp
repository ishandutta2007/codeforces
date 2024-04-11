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
int n,m,a,b,c,k, w;

int wyk[4];
int t[1000100];
int main()
{
    boost;
    cin >> n >> w;
    int dwa = 2 * n;
    for (int i=1; i<=dwa; ++i) cin >> t[i];
    sort(t+1, t + dwa + 1);
   ld MIN = t[1];
    ld MIN2 = t[n + 1];
    //cout << MIN << ' ' << MIN2 << endl;
  ld X = MIN;
    X = min(MIN2 * 0.5, X);
    printf("%.9lf", min(3 * n * X, (ld)w));
    return 0;
}