#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e6+5)

int dp[20][(1<<19)];
int mask[20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    int t;
//    cin >> t;
//    while(t--)
//    {
//        int n;
//        cin >> n;
//        string a,b;
//        cin >> a >> b;
//        for(int i=0;i<20;i++)
//        {
//            mask[i]=0;
//            for(int j=0;j<(1<<19);j+=(1<<i))
//                dp[i][j]=oo;
//        }
//        bool ok=1;
//        for(int i=0;i<n;i++)
//        {
//            if(a[i]>b[i])
//            {
//                ok=0;
//                break;
//            }
//            if(a[i]==b[i])
//                continue;
//            mask[a[i]-'a']|=(1<<(b[i]-1-'a'));
//        }
//        if(!ok)
//        {
//            db(-1)
//            continue;
//        }
//
//        dp[0][0]=0;
//        for(int i=0;i<19;i++)
//            for(int j=0;j<(1<<19);j+=(1<<i))
//            {
//                int m=mask[i]|j;
//                dp[i+1][0]=min(dp[i+1][0],dp[i][j]+__builtin_popcount(m));
//                if(mask[i+1] || (m&(1<<i)))
//                {
//                    if(m&(1<<i))
//                        m^=(1<<i);
//                    dp[i+1][m]=min(dp[i+1][m],dp[i][j]+1);
//                }
//                else
//                    dp[i+1][m]=min(dp[i+1][m],dp[i][j]);
//            }
//        db(dp[19][0])
//    }

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a;
        vector<int> fs(30);
        for(int i=0;i<n;i++)
        {
            cin >> a;
            for(int j=0;j<30;j++)
                if(a&(1<<j))
                    fs[j]++;
        }

        int cant=-1;
        for(int i=29;i>=0;i--)
            if((fs[i]&1) && cant==-1)
                cant=fs[i];
        if(cant==-1)
            db("DRAW")
        else if(cant%4==3)
        {
            if(n&1)
                db("LOSE")
            else
                db("WIN")
        }
        else
            db("WIN")
    }

    return 0;
}
/**
5 3 aab bcc 4 cabc abcb 3 abc tsr 4 aabd cccd 5 abcbd bcdda
1
4
aceg
ijkl
**/