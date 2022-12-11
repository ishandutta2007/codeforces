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
#define MAXN (ll)(3e2+5)

int a[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        bool ok=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin >> a[i][j];
                int ma=0;
                if(i)
                    ma++;
                if(j)
                    ma++;
                if(i<n-1)
                    ma++;
                if(j<m-1)
                    ma++;
                ok&=(ma>=a[i][j]);
                a[i][j]=ma;
            }

        if(ok)
        {
            db("YES")
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                    cout << a[i][j] << ' ';
                cout << '\n';
            }
        }
        else
            db("NO")
    }

    return 0;
}