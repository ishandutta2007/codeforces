#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (int)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e3+5)

int dp[MAXN][MAXN];
int ini[MAXN*20];
int mamod[MAXN][7];
int mp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n+1);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(!ini[a[i]])
            ini[a[i]]=i;
        for(int j=0;j<i;j++)
        {
            int m=max(mamod[j][a[i]%7],mp[j][ini[a[i]]]);
            if(ini[a[i]+1])
                m=max(m,mp[j][ini[a[i]+1]]);
            if(ini[a[i]-1])
                m=max(m,mp[j][ini[a[i]-1]]);
            m=max(m,dp[0][j]);
            dp[i][j]=dp[j][i]=m+1;
            res=max(res,dp[i][j]);
            mamod[i][a[j]%7]=max(mamod[i][a[j]%7],dp[i][j]);
            mp[i][ini[a[j]]]=max(mp[i][ini[a[j]]],dp[i][j]);
            mamod[j][a[i]%7]=max(mamod[j][a[i]%7],dp[i][j]);
            mp[j][ini[a[i]]]=max(mp[j][ini[a[i]]],dp[i][j]);
        }
    }

//    for(int i=0;i<=n;i++,cout << '\n')
//        for(int j=0;j<=n;j++)
//            cout << dp[i][j] << ' ';

    db(res)

    return 0;
}
/**
4
1 2 4 5
6
62 22 60 61 48 49
**/