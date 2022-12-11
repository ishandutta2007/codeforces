#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(3e6+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<ll>> fs(4,vector<ll>(4));
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        fs[x&3][y&3]++;
    }

    ll ans=0;
    ll sum=0;
    ll ps=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
//            cout << fs[i][j]<< '\n';
            ll comb=(fs[i][j]*(fs[i][j]-1))/2;
            ans+=fs[i][j]*ps;
            ps+=comb;
            ans+=comb*sum;
            comb=(comb*(fs[i][j]-2))/3;
            ans+=comb;

            sum+=fs[i][j];
        }
    db(ans)

    return 0;
}