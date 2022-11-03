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

const ll MAXN=5e3+10;
const ll INF=1e16+10;

ll a[MAXN];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	ll n , g , f , h , res=-INF;;
	cin>>n;

	for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(ll i=1;i<=(n+1);i++)
    {
        ll e=0 , k=0 , u=i;

        for(ll j=i;j<=n;j++)
        {
            e+=a[j];

            if (e>k)
            {
                k=e;
                u=j+1;
            }
        }

        ll d=0 , x=0 , z=1;

        for(ll j=1;j<i;j++)
        {
            x+=a[j];

            if (x>d)
            {
                d=x;
                z=j+1;
            }
        }

        if (res<(d+k))
        {
            res=d+k;

            f=z;
            g=i;
            h=u;
        }
    }

    cout<<f-1<<" "<<g-1<<" "<<h-1;
}