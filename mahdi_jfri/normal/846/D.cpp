#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) (x & -(x))
#define BIT(a,b) ((ll)((a)&(1<<(b)))==0 ? false : true)

const ll MAXN=5e2+10;
const ll INF=1e12+10;

ll a[MAXN][MAXN];
ll b[MAXN][MAXN];
ll ps[MAXN][MAXN];

ll n , m , k , q;

bool ok(ll f)
{
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=m;j++)
        {
            b[i][j]=(a[i][j]<=f);
        }
    }

    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+b[i][j];
        }
    }

    for(ll i=k;i<=n;i++)
    {
        for(ll j=k;j<=m;j++)
        {
            if (ps[i][j]-ps[i-k][j]-ps[i][j-k]+ps[i-k][j-k]==(k*k))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m>>k>>q;

	for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=m;j++)
        {
            a[i][j]=INF;
        }
    }

	for(ll i=0;i<q;i++)
    {
        ll  x , y , t;
        cin>>x>>y>>t;

        a[x][y]=t;
    }

    ll l=-1 , r=INF;

    while (true)
    {
        if (r-l==1)
        {
            cout<<(r==INF ? -1 : r);
            return 0;
        }

        ll mid=(l+r)/2;

        if (ok(mid))
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
}