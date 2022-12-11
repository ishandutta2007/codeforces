#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        ld l;
        cin >>n >> l;
        vector<ld> a(n+2);
        a[0]=0;
        a[n+1]=l;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            a[i+1]=x;
        }
        ld v1=1;
        ld v2=1;
        ld t1=0;
        ld t2=0;
        int p1=1;
        int p2=n;
        while(p1<=p2)
        {
            if(t1+(a[p1]-a[p1-1])/v1<=t2+(a[p2+1]-a[p2])/v2)
            {
                t1+=(a[p1]-a[p1-1])/v1;
                v1+=1;
                p1++;
            }
            else
            {
                t2+=(a[p2+1]-a[p2])/v2;
                v2+=1;
                p2--;
            }
        }

        ld d=a[p1]-a[p2];
        if(t1<t2)
            d-=(t2-t1)*v1;
        else
            d-=(t1-t2)*v2;
        prec(15);
        db(max(t1,t2)+d/(v1+v2))
    }

    return 0;
}