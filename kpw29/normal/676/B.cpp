#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
//#define FOR(i, a, b) for ((int)(i) = (a); i <= (b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000010

int main()
{
    int n,t;
    cin>>n>>t;
    double a[15][15];
    memset(a,0,sizeof(a));
    a[1][1]=t;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(a[i][j]>=1)
            {
                a[i][j]-=1;
                a[i+1][j]+=a[i][j]/2;
                a[i+1][j+1]+=a[i][j]/2;
                ans++;
            }
        }
    }
    cout<<ans<<endl;

}