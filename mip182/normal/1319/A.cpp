#include <bits/stdc++.h>
//#pragma GCC optmize("O3,Ofast,unroll-loops,fast-math,no-stack-protector")
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<(n);i++)
#define pii pair <int,int>
#define pll pair <ll,ll>
#define vi vector <int>
#define vvi vector <vector <int> >
#define vll vector <ll>
#define fi first
#define se second
#define mii map <int,int>
#define mll map <ll,ll>
#define si set <int>
#define sll set <ll>
#define pb push_back

const int MAXN=1e6+100;
const ll INF=1e9;
const ll INFLL=1e18;
const ll mod1=1e9+7;


signed  main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    #endif
    int n;
    cin>>n;
    vector <int> r(n),b(n);
    rep(i,n)
    cin>>r[i];
    rep(i,n)
    cin>>b[i];
    bool ok=false,ko=false;
    int cnt=0,chet=0;
    for (int i=0;i<n;i++)
    {
        if (r[i]==0&&b[i]==0)
        {
           continue;
        }
        else
        {
            if (r[i]>0)
                ko= true;
            if (r[i]==0&&b[i]==1)
            {
                cnt++;
            }
            else
            {
                if (r[i]==1&&b[i]==0)
                {
                    chet++;
                }
            }
        }
    }
    if (chet==0)
    {
        cout<<-1;
    }
    else
    {
        ll l=0,rr=1e8;
        ll ans=0;
        while (l<=rr)
        {
            ll mid=(l+rr)/2;
            if (mid*chet>cnt)
                ans=mid,rr=mid-1;
            else
                l=mid+1;
        }
        cout<<ans;
    }



}