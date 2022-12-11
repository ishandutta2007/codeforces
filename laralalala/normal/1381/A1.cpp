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
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            int lp;
            if(n&1)
            {
                if(i&1)
                    lp=n-((n-i)/2);
                else
                    lp=(n-i)/2;
            }
            else
            {
                if(i&1)
                    lp=(n-i)/2;
                else
                    lp=n-((n-i)/2);
            }
            int pl=(n-1-i);
            if(i)
                pl++;
//            cout << i << ' ' << lp << ' ' <<  pl << '\n';
            int v=a[i]-'0';
            if(pl&1)
                v=(1-v);
            if(v!=b[lp]-'0')
                res.push_back(1);
//            db(res.size())

            if(i!=n-1)
                res.push_back(i+2);
        }

        cout << res.size();
        for(auto y: res)
            cout << ' ' << y;
        cout << '\n';
    }

    return 0;
}
/**
1
2
01
10
1
2
01
01
**/