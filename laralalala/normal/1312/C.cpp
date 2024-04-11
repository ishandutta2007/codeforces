#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        int f[60];
        for(int i=0;i<60;i++)
            f[i]=0;
        for(int i=0;i<n;i++)
        {
            ll a;
            cin >> a;
            int pos=0;
            while(a)
            {
                f[pos]+=a%k;
                pos++;
                a/=k;
            }
        }

        bool ok=1;
        for(int i=0;i<60;i++)
            ok&=(f[i]<=1);
        if(ok)
            db("YES")
        else
            db("NO")
    }


    return 0;
}