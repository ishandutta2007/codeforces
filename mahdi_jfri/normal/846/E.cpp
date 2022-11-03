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
const ll CA=-1e15;

vector <pll> vertex[MAXN];

ll a[MAXN];
ll b[MAXN];
ll dp[MAXN];

void dfs(ll v)
{
    dp[v]=b[v]-a[v];

    for(ll i=0;i<vertex[v].size();i++)
    {
        dfs(vertex[v][i].X);
        if(dp[v] < CA)
        {
            cout << "NO";
            exit(0);
        }
        if (dp[vertex[v][i].X]>=0)
        {
            dp[v]+=dp[vertex[v][i].X];
        }
        else
        {
            if(dp[vertex[v][i].X] < CA / vertex[v][i].Y)
            {
                cout << "NO";
                exit(0);
            }
            dp[v]+=vertex[v][i].Y*dp[vertex[v][i].X];
        }
    }

    if (dp[v]<CA)
    {
        cout<<"NO";
        exit(0);
    }
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin>>n;

	for(ll i=1;i<=n;i++)
    {
        cin>>b[i];
    }

	for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(ll i=2;i<=n;i++)
    {
        ll p , k;
        cin>>p>>k;

        vertex[p].pb(mp(i , k));
    }

    dfs(1);

    if (dp[1]>=0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}