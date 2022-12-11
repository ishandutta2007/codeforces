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
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        string ss="abacaba";
        bool kk=1;
        for(int i=0;i+6<n;i++)
        {
            string g=s;
            for(int j=0;j<i;j++)
                if(g[j]=='?')
                    g[j]='x';
            for(int j=i;j<=i+6;j++)
                if(g[j]=='?')
                    g[j]=ss[j-i];
            for(int j=i+7;j<n;j++)
                if(g[j]=='?')
                    g[j]='x';
            int cant=0;
            for(int j=0;j+6<n;j++)
            {
                int ok=1;
                for(int k=0;k<7;k++)
                    ok&=(g[j+k]==ss[k]);
                cant+=ok;
            }
            if(cant==1)
            {
                db("Yes")
                db(g)
                kk=0;
                break;
            }
        }
        if(kk)
            db("No")
    }

    return 0;
}