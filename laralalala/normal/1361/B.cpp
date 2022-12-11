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
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod ((ll)(1e9+7))

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,p;
        cin >> n >> p;
        vector<ll> es(n);
        for(int i=0;i<n;i++)
            cin >> es[i];
        if(p==1)
        {
            db(n&1)
            continue;
        }

        sort(allr(es));

        ll tar=-1;
        map<int,int> ms;
        for(auto y : es)
        {
            if(tar==-1)
                tar=y;
            else
            {
                ms[y]++;
                while(ms[y]>=p)
                {
                    ms[y+1]++;
                    ms[y]-=p;
                    y++;
                }
                if(ms[tar]==1)
                {
                    tar=-1;
                    ms.clear();
                }
            }
        }
        if(tar==-1)
            db(0)
        else
        {
//            db("")
//            cout << tar << '\n';
//            for(auto y : ms)
//                cout << y.first << ' ' << y.second << '\n';
            ll d=qp(p,tar);
            for(auto y : ms)
                d=(d-(y.second*qp(p,y.first))%mod+mod)%mod;
            db(d)
        }
    }

    return 0;
}
/**
4
5 2
2 3 4 4 3
3 1
2 10 1000
4 5
0 1 1 100
1 8
89
**/