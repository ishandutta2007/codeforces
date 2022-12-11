#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    vector <int> a(n);
    rep(i,n)
    cin>>a[i];
    map <vector <int>,int> m,k;
    for (int mask=0;mask<(1<<15);mask++)
    {
        vector <int> b(n);
        for (int i=0;i<n;i++)
        {
            b[i]=__builtin_popcount(((mask)^((a[i]&((1<<15)-1)))));
        }
        m[b]=mask+1;
    }
    for (int mask=0;mask<(1<<15);mask++)
    {
        vector <int> b(n);
        for (int i=0;i<n;i++)
        {
            b[i]=__builtin_popcount(((mask)^((a[i]>>15))));
        }
        k[b]=(mask<<15)+1;
    }
    vector <int> b(n);

    for (auto to:m)
    {
        for (int i=0;i<=30;i++)
        {
            vector <int> c(n);
            vector <int> d=to.first;
            bool ok=true;
            for (int j=0;j<n;j++)
            {
                c[j]=i-d[j];
            }
            if (ok)
            {
                if (k[c])
                {  // for (int i=0;i<n;i++)
                    //cout<<d[i]<<" "<<c[i]<<'\n';
                    cout<<((k[c]-1)^(to.second-1));
                    return 0;
                }
            }
        }
    }
    cout<<-1;
}