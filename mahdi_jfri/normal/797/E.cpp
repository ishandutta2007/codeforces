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

const ll MAXN=1e5+10;
const ll SQ=330;

ll dp[MAXN][SQ];

ll a[MAXN];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(ll i=0;i<SQ;i++)
    {
        for(ll j=n-1;j>=0;j--)
        {
            if ((a[j]+i+j)>=n)
            {
                dp[j][i]=1;
            }
            else
            {
                dp[j][i]=dp[a[j]+i+j][i]+1;
            }
        }
    }

    ll q;
    cin>>q;

    for(ll i=0;i<q;i++)
    {
        ll p,k;
        cin>>p>>k;

        p--;

        if (k<SQ)
        {
            cout<<dp[p][k]<<endl;
        }
        else
        {
            ll e=0;

            while (p<n)
            {
                e++;
                p+=a[p]+k;
            }

            cout<<e<<endl;
        }
    }
}