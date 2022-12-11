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
#define MAXN (ll)(2e5+5)

ll a[MAXN],b[MAXN];
ll f[20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        for(int j=0;j<20;j++)
            if(a[i]&(1<<j))
                f[j]++;
    }

    for(int i=0;i<20;i++)
        for(int j=0;j<f[i];j++)
            b[j]+=(1<<i);

    ll res=0;
    for(int i=0;i<n;i++)
        res+=(b[i]*b[i]);
    db(res)

    return 0;
}