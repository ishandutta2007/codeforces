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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> res;
    for(int i=0;i<n;i++)
    {
        res.push_back({1,(2*i)+1});
        res.push_back({1,(2*i)});
        res.push_back({0,(2*i)+1});
        res.push_back({2,(2*i)+1});
    }
    res.push_back(pii(1,2*n));

    if(n&1)
    {
        res.push_back(pii(1,-1));
        res.push_back(pii(2,-1));
        res.push_back(pii(3,-1));
        res.push_back(pii(3,0));
        res.push_back(pii(3,1));

        res.push_back(pii(-1,(2*n)-1));
        res.push_back(pii(-1,(2*n)));
        res.push_back(pii(-1,(2*n)+1));
        res.push_back(pii(0,(2*n)+1));
        res.push_back(pii(1,(2*n)+1));
        for(int i=0;i<n-1;i+=2)
        {
            res.push_back(pii(-1,(2*i)+1));
            res.push_back(pii(-1,(2*i)+2));
            res.push_back(pii(-1,(2*i)+3));
        }
        for(int i=1;i<n;i+=2)
        {
            res.push_back(pii(3,(2*i)+1));
            res.push_back(pii(3,(2*i)+2));
            res.push_back(pii(3,(2*i)+3));
        }
    }
    else
    {
        for(int i=0;i<n;i+=2)
        {
            res.push_back(pii(-1,(2*i)+1));
            res.push_back(pii(-1,(2*i)+2));
            res.push_back(pii(-1,(2*i)+3));
        }
        for(int i=0;i<n;i+=2)
        {
            res.push_back(pii(3,(2*i)+1));
            res.push_back(pii(3,(2*i)+2));
            res.push_back(pii(3,(2*i)+3));
        }

        res.push_back(pii(1,-1));
        res.push_back(pii(2,-1));
        res.push_back(pii(3,-1));
        res.push_back(pii(4,-1));
        res.push_back(pii(5,-1));

        res.push_back(pii(1,2*n+1));
        res.push_back(pii(2,2*n+1));
        res.push_back(pii(3,2*n+1));
        res.push_back(pii(4,2*n+1));
        res.push_back(pii(5,2*n+1));
        for(int i=0;i<=2*n;i++)
            res.push_back(pii(5,i));
    }

    db(res.size())
    for(auto y : res)
        cout << y.f << ' ' << y.s << '\n';

    return 0;
}