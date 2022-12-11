#include <bits/stdc++.h>
using namespace std;
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
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout<<#x<<"="<<x<<", ";}
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 2e9+11;
int dist(pii a,pii b)
{
    return abs(a.fi-b.fi)+abs(a.se-b.se);
}
void solve()
{
    int r,n;
    cin>>r>>n;
    vector <pair <pii,int> > x(n+1);
    x[0]={{1,1},0};
    rep(i,n)
        cin>>x[i+1].se>>x[i+1].fi.fi>>x[i+1].fi.se;
    int now_max=0;
    vector <int> update_max(n+1);
    vector <int> mx(n+1);
    mx[0]=1;
    for (int i=0;i<=n;i++)
    {
        now_max=max(now_max,update_max[i]);
        mx[i]=max(mx[i],now_max);
        if (mx[i]==0)
            continue;
        for (int j=i+1;j<=n;j++)
        {
            if (x[j].se-x[i].se>=2*r)
            {
                update_max[j]=max(update_max[j],mx[i]+1);
                break;
            }
            if (dist(x[i].fi,x[j].fi)>x[j].se-x[i].se)
                continue;
            //cout<<x[i].fi.fi<<" "<<x[i].fi.se<<" "<<x[j].fi.fi<<" "<<x[j].fi.se<<'\n';
            mx[j]=max(mx[j],mx[i]+1);
        }
    }
    cout<<*max_element(all(mx))-1<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}