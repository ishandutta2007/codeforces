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
vvi g;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    ll u,v;
    cin>>u>>v;
    if (v==u)
    {
        if (u==0){
            cout<<0;
        }
        else {
            cout << 1 << '\n';
            cout << u;
        }
        return 0;
    }
    if (v<u)
    {
        cout<<-1;
        return 0;
    }
    ll a=v-u;
    if (a%2==1)
        cout<<-1;
    else
    {
        ll x=0,y=0;
        bool ok=true;
        ll sum=0;
        for (ll i=0;i<64;i++)
        {
            if ((u>>i)&1)
                sum|=(((ll)(1))<<i);
        }
        if (sum>v)
            ok=false;
        x=sum;
        ll t=v-sum;
        for (ll i=0;i<64;i++)
        {
           // cout<<x<<" "<<ok<<'\n';
            if ((t>>i)&(1ll))
            {
             //   cout<<"ahha";
                if (i==0)
                    ok=false;
                else
                {
                    if (((u>>(i-1))&(1ll))!=0)
                        ok=false;
                    else
                    {
                        x|=((1ll)<<(i-1));
                    }
                }
            }
        }
   //     cout<<x<<'\n';
        if (ok)
        {
            cout<<2<<'\n';
            cout<<x<<" "<<(u^x);
        }
        else {
            cout << 3 << '\n';
            cout << u << " " << a / 2 << " " << a / 2;
        }
    }






}