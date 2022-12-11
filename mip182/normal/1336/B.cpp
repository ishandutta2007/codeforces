//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
ll func(ll a,ll b,ll c)
{
    return (a-b)*(a-b)+(a-c)*(a-c)+(b-c)*(b-c);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int t;
    cin>>t;
    while (t--)
    {
        int xx,yy,zz;
        cin>>xx>>yy>>zz;
        vll x(xx),y(yy),z(zz);
        for (int i=0;i<xx;i++)
            cin>>x[i];
        rep(i,yy)
        cin>>y[i];
        rep(i,zz)
        cin>>z[i];
        sort(all(x));
        sort(all(y));
        sort(all(z));
        ll ans=func(x[0],y[0],z[0]);
        for (int i=0;i<xx;i++)
        {
            auto to=lower_bound(all(y),x[i]);
            if (to!=y.end())
            {
                ll g=*to;
                auto f=lower_bound(all(z),(g+x[i])/2);
                if (f!=z.end())
                {
                    ans=min(ans,func(x[i],g,*f));
                }
                if (f!=z.begin())
                {
                    f=prev(f);
                    ans=min(ans,func(x[i],g,*f));
                }
            }
            if (to!=y.begin())
            {
                to=prev(to);
                ll g=*to;
                auto f=lower_bound(all(z),(g+x[i])/2);
                if (f!=z.end())
                {
                    ans=min(ans,func(x[i],g,*f));
                }
                if (f!=z.begin())
                {
                    f=prev(f);
                    ans=min(ans,func(x[i],g,*f));
                }
            }
        }
        for (int i=0;i<yy;i++)
        {
            auto to=lower_bound(all(x),y[i]);
            if (to!=x.end())
            {
                ll g=*to;
                auto f=lower_bound(all(z),(g+y[i])/2);
                if (f!=z.end())
                {
                    ans=min(ans,func(y[i],g,*f));
                }
                if (f!=z.begin())
                {
                    f=prev(f);
                    ans=min(ans,func(y[i],g,*f));
                }
            }
            if (to!=x.begin())
            {
                to=prev(to);
                ll g=*to;
                auto f=lower_bound(all(z),(g+y[i])/2);
                if (f!=z.end())
                {
                    ans=min(ans,func(y[i],g,*f));
                }
                if (f!=z.begin())
                {
                    f=prev(f);
                    ans=min(ans,func(y[i],g,*f));
                }
            }
        }
        for (int i=0;i<zz;i++)
        {
            auto to=lower_bound(all(x),z[i]);
            if (to!=x.end())
            {
                ll g=*to;
                auto f=lower_bound(all(y),(g+z[i])/2);
                if (f!=y.end())
                {
                    ans=min(ans,func(z[i],g,*f));
                }
                if (f!=y.begin())
                {
                    f=prev(f);
                    ans=min(ans,func(z[i],g,*f));
                }
            }
            if (to!=x.begin())
            {
                to=prev(to);
                ll g=*to;
                auto f=lower_bound(all(y),(g+z[i])/2);
                if (f!=y.end())
                {
                    ans=min(ans,func(z[i],g,*f));
                }
                if (f!=y.begin())
                {
                    f=prev(f);
                    ans=min(ans,func(z[i],g,*f));
                }
            }
        }
        cout<<ans<<'\n';
    }




}