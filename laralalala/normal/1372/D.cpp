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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

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
//        int cant=0;
//        int mi=oo,ma=0;
//        for(int i=0;i<n;i++)
//        {
//            int x;
//            cin >> x;
//            if(x==i+1)
//            {
//                cant++;
//                if(mi==oo)
//                    mi=i;
//                ma=i;
//            }
//        }
//        if(cant==n)
//            db(0)
//        else if(cant)
//        {
//            if(mi==n-cant || ma==cant-1)
//                db(1)
//            else
//                db(2)
//        }
//        else
//            db(1)
//    }

    int n;
    cin >> n;
    vector<ll> aci(n);
    vector<ll> acp(n);
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(i&1)
            acp[(i/2)+1]=acp[i/2]+x;
        else
            aci[(i/2)+1]=aci[i/2]+x;
        sum+=x;
    }

    int cant=n/2;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        int faltan=min((n-i+1)/2,cant);
        int ff=cant-faltan;
        int pos=i/2;
        if(!(i&1))
        {
            ll sp=aci[pos+faltan]-aci[pos];
            ll sx=acp[ff];
//            cout << sp << ' ' << sx << '\n';
            res=max(res,sum-sp-sx);
        }
        else
        {
            ll sp=acp[pos+faltan]-acp[pos];
            ll sx=aci[ff];
//            cout << sp << ' ' << sx << '\n';
            res=max(res,sum-sp-sx);
        }
    }
    db(res)

    return 0;
}
/**
3
7 10 2
1
4
**/