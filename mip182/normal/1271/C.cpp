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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vector <int> xx={1,-1,0,0,1,1,-1,-1};
vector <int> yy={0,0,1,-1,1,-1,1,-1};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll sx,sy;
    cin>>n>>sx>>sy;
    vector <ll> x(n),y(n);
    rep(i,n)
    cin>>x[i]>>y[i];
    ll ans=-1;
    pair <ll,ll> a;
    for (int i=0;i<8;i++)
    {
        ll shx=sx+xx[i],shy=sy+yy[i];
        int cnt=0;
        if (sx+xx[i]<=1e9&&sx+xx[i]>=0&&sy+yy[i]>=0&&sy+yy[i]<=1e9)
        {
        for (int i=0;i<n;i++)
        {
            ll xp=sx,xt=x[i],yp=sy,yt=y[i];
            if (xp>xt)
                swap(xp,xt);
            if (yp>yt)
                swap(yp,yt);
            if (xp<=shx&&shx<=xt&&yp<=shy&&shy<=yt)
                cnt++;
        }
        }
        if (cnt>ans)
        {
            ans=cnt;
            a={shx,shy};
        }

    }
    cout<<ans<<'\n';
    cout<<a.first<<" "<<a.second;
}