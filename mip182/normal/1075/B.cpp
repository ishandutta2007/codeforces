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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int n,m;
    cin>>n>>m;
    set <pll> tax;
    vector <int> ans(n+m);
    vector <pll> pep(n+m);
    rep(i,n+m)
    cin>>pep[i].fi;
    rep(i,n+m)
    cin>>pep[i].se;
    for (int i=0;i<n+m;i++)
    {
        if (pep[i].se==1)
           tax.insert(make_pair(pep[i].fi,i));
    }
    for (int i=0;i<n+m;i++)
    {
        if (pep[i].se==0)
        {
            auto to=tax.upper_bound({pep[i].fi,INF});
            ll x=INFLL;
            int ind=-1,ind1=-1;
            ll y=-INFLL;
            if (to!=tax.end())
                x=min(x,(ll)(*to).fi),ind=(*to).se;
            if (to!=tax.begin())
                to=prev(to),y=max(y,(ll)(*to).fi),ind1=(*to).se;
         //   cout<<x<<" "<<y<<" "<<ind<<" "<<ind1<<'\n';
            if (pep[i].fi-y<=x-pep[i].fi)
            {
                ans[ind1]++;
            }
            else
                ans[ind]++;
        }
    }
    for (int i=0;i<n+m;i++)
    {
        if (pep[i].se==1)
            cout<<ans[i]<<" ";
    }











}