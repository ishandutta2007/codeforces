#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
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
#define MAXN 200005

ll a[MAXN],f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            f[(i+a[i]+n*(ll)1e9)%n]++;
        }
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            ok&=(f[i]==1);
            f[i]=0;
        }

        if(ok)
            db("YES")
        else
            db("NO")
    }

    return 0;
}