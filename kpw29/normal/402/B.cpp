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
const int MOD = 1e9+7;
const int inf = 1e9+9;
const ll mod = 1e9+696969;

int n,m,k,a,b,c;
ll N,M,K,A,B,C;

int t[1010];
int main()
{
    boost;
    cin >> n >> k;
    for (int i=1; i<=n; ++i) cin >> t[i];
    int WYN = inf, skad = -1;
    for (int i=1; i<=1000; ++i)
    {
        int tmp = 0;
        for (int j=1; j<=n; ++j) 
        {
            int ile = (j-1) * k + i;
            if (t[j] != ile) ++tmp;
        }
        if (tmp < WYN) skad = i, WYN = tmp;
    }
    cout << WYN << endl;
    for (int j=1; j<=n; ++j)
    {
        int ile = (j-1) * k + skad;
        if (t[j] != ile)
        {
            
            if (ile < t[j]) cout << "- ";
            else cout << "+ ";
            cout << j << ' ';
            cout << abs(t[j] - ile) << endl;
        }
    }
}