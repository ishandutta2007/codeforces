#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ini=-1;
        int last=-1;
        vector<pip> mids;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='W')
            {
                if(ini==-1)
                    ini=i;
                if(last!=-1 && last!=i-1)
                    mids.push_back(pip(i-1-last,pii(last+1,i-1)));
                last=i;
            }
        }
        sort(all(mids));
        if(ini==-1)
        {
            for(int i=0;i<k;i++)
                s[i]='W';
        }
        else
        {
            for(auto y : mids)
            {
                for(int i=y.s.f;i<=y.s.s;i++)
                    if(k && s[i]=='L')
                    {
                        k--;
                        s[i]='W';
                    }
            }
            for(int i=max(0,ini-k);i<ini;i++)
            {
                s[i]='W';
                k--;
            }
            for(int i=last+1;i<n;i++)
            {
                if(k)
                {
                    k--;
                    s[i]='W';
                }
            }
        }

//        db(s)
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='W')
            {
                res++;
                if(i && s[i-1]=='W')
                    res++;
            }
        }
        db(res)
    }

    return 0;
}