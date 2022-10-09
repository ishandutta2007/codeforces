#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define maxn 1000100
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
int n,a[maxn],d[2];
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i) scanf("%d",a + i);
    int ans=0;
    for (int L = 1; L<=n; ++L)
    {
        int R=L-1; 
        ans++;
        d[0]=d[1]=0;
        while (!d[1] && R<n)
        {
            ++R;
            if (a[R] != -1) d[d[0]>0]=R;
        }
        if (!d[1]) break;
        int pocz = d[1], kon = d[0];
        ll change=a[pocz]-a[kon];
        if (change % (pocz - kon) != 0) R= pocz -1;
        else
        {
            change /= (pocz - kon);
            bool ok = 1;
            if (L != kon)
            {
                ll fi=a[kon]-(kon-L)*change;
                if (fi <= 0) R= pocz -1, ok = false;
            }
            while (ok)
            {
                ll nv=a[d[1]]+(R+1-d[1])*change;
                if (nv>0 && (nv == a[R+1] || a[R+1] == -1)) R++;
                else break;
            }
        }

        L=R;
    }
    printf("%d ", max(ans, 1));
}